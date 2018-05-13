#include <hiredis/hiredis.h>

/**
 * publish
 * subscribe
 */

redisReply *reply;
redisContext *c;
char channel[] = "ch01";

void publish() {
	printf("---------------------------------------------------\n");
	printf("PUBLISH channel message -> Integer reply: the number of clients that received the message.\n");
	// #1 PUBLISH channel message
	reply = redisCommand(c, "PUBLISH %s %s", channel, "Hello Hiredis");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. PUBLISH %s %s -> %d\n", channel, "Hello Hiredis", reply->integer);
 	freeReplyObject(reply);
}

void subscribe() {
	printf("---------------------------------------------------\n");
	printf("SUBSCRIBE channel [channel ...] -> Array reply.\n");
	printf("\t使用 redisGetReply() 获取消息. \n");
	printf("\t使用 'exit'结束.\n");
	int i;
	// #1 SUBSCRIBE channel 
	reply = redisCommand(c, "SUBSCRIBE %s", channel);
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
	while(redisGetReply(c,(void**) &reply) == REDIS_OK) {
		for(i=0;i<reply->elements;i++) {
			printf("%d) %s\n", i, reply->element[i]->str);
			if (i==2 && !strcmp(reply->element[i]->str,"exit")) {
				return;
			}
		}
		freeReplyObject(reply);
	}
}

int main(){
	return 0;
}
