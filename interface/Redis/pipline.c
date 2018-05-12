#include <hiredis/hiredis.h>

redisReply *reply;
redisContext *c;

int cnt=10000;
time_t time1, time2;

void normalSet() {
	printf("---------------------------------------------------\n");
	printf("Normal   SET %d -> ", cnt);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		reply = redisCommand(c, "SET key-%d value-%d", i, i);
		if (reply == NULL) {
   		printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
   		freeReplyObject(reply);
			return;
   		} 
   		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time1 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf("  Elasped time(ms): %4d\n", time1);
}

void pipelineSet() {
	printf("Pipeline SET %d -> ", cnt);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		redisAppendCommand(c, "SET key=%d value=%d", i, i);
	}
	for(i=0;i<cnt;i++) {
		redisGetReply(c, (void **) &reply);
		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time2 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf("  Elasped time(ms): %4d -> %0.1f\n", time2, (float)time1/time2);
}

void normalLpush() {
	printf("---------------------------------------------------\n");
	printf("Normal   LPUSH %d -> ", cnt);
	reply = redisCommand(c, "DEL mylist1");
 	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		reply = redisCommand(c, "LPUSH mylist1 value-%d", i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
 		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time1 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf("Elasped time(ms): %4d\n", time1);
}

void pipelineLpush() {
	printf("Pipeline LPUSH %d -> ", cnt);
	reply = redisCommand(c, "DEL mylist2");
  freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		redisAppendCommand(c, "LPUSH mylist2 value=%d", i);
	}
	for(i=0;i<cnt;i++) {
		redisGetReply(c, (void **) &reply);
		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time2 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf("Elasped time(ms): %4d -> %0.1f\n", time2, (float)time1/time2);
}

void normalSadd() {
	printf("---------------------------------------------------\n");
	printf("Normal   SADD %d -> ", cnt);
	reply = redisCommand(c, "DEL myset1");
 	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		reply = redisCommand(c, "SADD myset1 value-%d", i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
 		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time1 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf(" Elasped time(ms): %4d\n", time1);
}

void pipelineSadd() {
	printf("Pipeline SADD %d -> ", cnt);
	reply = redisCommand(c, "DEL myset2");
 	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		redisAppendCommand(c, "SADD myset2 value=%d", i);
	}
	for(i=0;i<cnt;i++) {
		redisGetReply(c, (void **) &reply);
		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time2 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf(" Elasped time(ms): %4d -> %0.1f\n", time2, (float)time1/time2);
}

void normalZadd() {
	printf("---------------------------------------------------\n");
	printf("Normal   ZADD %d -> ", cnt);
	reply = redisCommand(c, "DEL myzset1");
   	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		reply = redisCommand(c, "ZADD myzset1 %d value-%d", i, i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
 		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time1 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf(" Elasped time(ms): %4d\n", time1);
}

void pipelineZadd() {
	printf("Pipeline ZADD %d -> ", cnt);
	reply = redisCommand(c, "DEL myzset2");
 	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		redisAppendCommand(c, "ZADD myzset2 %d value=%d", i, i);
	}
	for(i=0;i<cnt;i++) {
		redisGetReply(c, (void **) &reply);
		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time2 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf(" Elasped time(ms): %4d -> %0.1f\n", time2, (float)time1/time2);
}

void normalHset() {
	printf("---------------------------------------------------\n");
	printf("Normal   HSET %d -> ", cnt);
	reply = redisCommand(c, "DEL myhash1");
   	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		reply = redisCommand(c, "HSET myhash1 field-%d value-%d", i, i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
 		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time1 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf(" Elasped time(ms): %4d\n", time1);
}

void pipelineHset() {
	printf("Pipeline HSET %d -> ", cnt);
	reply = redisCommand(c, "DEL myhash2");
 	freeReplyObject(reply);
	time_t start=0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	start = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
	int i;
	for(i=0;i<cnt;i++) {
		redisAppendCommand(c, "HSET myhash2 field-%d value=%d", i, i);
	}
	for(i=0;i<cnt;i++) {
		redisGetReply(c, (void **) &reply);
		freeReplyObject(reply);
	}
	clock_gettime(CLOCK_REALTIME, &ts);
	time2 = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000) - start;
	printf(" Elasped time(ms): %4d -> %0.1f\n", time2, (float)time1/time2);
}

int main(){
	return 0;
}
