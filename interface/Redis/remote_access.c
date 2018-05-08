#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>

/**
 * 远程访问
 *
 */

int main() {
	redisContext *c;
	redisReply *reply;
	int i;
	//const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
	const char *hostname = "192.168.100.79";
	int port = 6379;
	struct timeval timeout = {1, 500000}; //1.5 seconds

	c = redisConnectWithTimeout(hostname, port, timeout);
	if(c == NULL || c->err){
		if(c){
			printf("Connection error: %s\n", c->errstr);
			redisFree(c);
		}else{
			printf("Connection error: can't allocate redis context\n");
		}

		exit(1);
	}

	//ping server
	reply = redisCommand(c, "PING");
	printf("PING: %s\n", reply->str);
	freeReplyObject(reply);

	//set a key
	reply = redisCommand(c, "SET %s %s", "foo", "hello world");
	printf("SET: %s\n",reply->str);
	freeReplyObject(reply);

	//get a key
	reply = redisCommand(c, "GET foo");
	printf("GET foo: %s\n", reply->str);
	freeReplyObject(reply);

	//disconnect and free the context
	redisFree(c);

	return 0;
}
