#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define NUM 48
#define START 1010001
#define END 1020000
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static int count = 0;

void *prime(void *p){
	int n, i, flag;
	int num, fd, ret;
	char name[BUFSIZ];
	char buf[BUFSIZ];

	bzero(name, BUFSIZ);
	//num = *p;
	//num = reinterpret_cast<int>(p);
	num = (int *) p;
	sprintf(name, "/tmp/tmpfilezorro%d", num);
	fd = open(name, O_RDWR|O_CREAT|O_TRUNC|O_NONBLOCK , 0644);

	if (fd < 0) {
		perror("open()");
		exit(1);
	}

	while (1) {
		if (pthread_mutex_lock(&mutex) != 0) {
			perror("pthread_mutex_lock()");
			pthread_exit(NULL);
		}
		while (count == 0) {
			if (pthread_cond_wait(&cond, &mutex) != 0) {
				perror("pthread_cond_wait()");
				pthread_exit(NULL);
			}
		}
		if (count == -1) {
			if (pthread_mutex_unlock(&mutex) != 0) {
				perror("pthread_mutex_unlock()");
				pthread_exit(NULL);
			}
			break;
		}
		n = count;
		count = 0;
		if (pthread_cond_broadcast(&cond) != 0) {
			perror("pthread_cond_broadcast()");
			pthread_exit(NULL);
		}
		if (pthread_mutex_unlock(&mutex) != 0) {
			perror("pthread_mutex_unlock()");
			pthread_exit(NULL);
		}
		flag = 1;
		for (i=2;i<n/2;i++) {
			ret = read(fd, buf, BUFSIZ);
			if (ret < 0) {
				perror("read()");
			}
			if (n%i == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf("%d is a prime form %d!\n", n, pthread_self());
		}
	}

	close(fd);
	pthread_exit(NULL);
}

int main(void){
	pthread_t tid[NUM];
	int ret, i, num;
	for (i=0;i<NUM;i++) {
		ret = pthread_create(&tid[i], NULL, prime, (void *)i);
		if (ret != 0) {
			perror("pthread_create()");
			exit(1);
		}
	}
	for (i=START;i<END;i+=2) {
		if (pthread_mutex_lock(&mutex) != 0) {
			perror("pthread_mutex_lock()");
			pthread_exit(NULL);
		}
		while (count != 0) {
			if (pthread_cond_wait(&cond, &mutex) != 0) {
				perror("pthread_cond_wait()");
				pthread_exit(NULL);
			}
		}
		count = i;
		if (pthread_cond_broadcast(&cond) != 0) {
			perror("pthread_cond_broadcast()");
			pthread_exit(NULL);
		}
		if (pthread_mutex_unlock(&mutex) != 0) {
			perror("pthread_mutex_unlock()");
			pthread_exit(NULL);
		}
	}
	if (pthread_mutex_lock(&mutex) != 0) {
		perror("pthread_mutex_lock()");
		pthread_exit(NULL);
	}
	while (count != 0) {
		if (pthread_cond_wait(&cond, &mutex) != 0) {
			perror("pthread_cond_wait()");
			pthread_exit(NULL);
		}
	}
	count = -1;
	if (pthread_cond_broadcast(&cond) != 0) {
		perror("pthread_cond_broadcast()");
		pthread_exit(NULL);
	}
	if (pthread_mutex_unlock(&mutex) != 0) {
		perror("pthread_mutex_unlock()");
		pthread_exit(NULL);
	}
	for (i=0;i<NUM;i++) {
		ret = pthread_join(tid[i], NULL);
		if (ret != 0) {
			perror("pthread_join()");
			exit(1);
		}
	}
	exit(0);
}

