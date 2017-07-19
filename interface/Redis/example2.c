#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>

int main(int argc, char **argv) {
    unsigned int j;
    redisContext *c;
    redisReply *reply;
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    /* PING server */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key */
    reply = redisCommand(c,"SET %s %s", "foo", "hello world");
    printf("SET: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key using binary safe API */
    reply = redisCommand(c,"SET %b %b", "bar", (size_t) 3, "hello", (size_t) 5);
    printf("SET (binary API): %s\n", reply->str);
    freeReplyObject(reply);

    /* Try a GET and two INCR */
    reply = redisCommand(c,"GET foo");
    printf("GET foo: %s\n", reply->str);
    freeReplyObject(reply);

    reply = redisCommand(c,"INCR counter");
    printf("INCR counter: %lld\n", reply->integer);
    freeReplyObject(reply);
    /* again ... */
    reply = redisCommand(c,"INCR counter");
    printf("INCR counter: %lld\n", reply->integer);
    freeReplyObject(reply);

    /* Create a list of numbers, from 0 to 9 */
    reply = redisCommand(c,"DEL mylist");
    freeReplyObject(reply);
    for (j = 0; j < 10; j++) {
        char buf[64];

        snprintf(buf,64,"%d",j);
        reply = redisCommand(c,"LPUSH mylist element-%s", buf);
        freeReplyObject(reply);
    }

    /* Let's check what we have inside the list */
    reply = redisCommand(c,"LRANGE mylist 0 -1");
    if (reply->type == REDIS_REPLY_ARRAY) {
        for (j = 0; j < reply->elements; j++) {
            printf("%u) %s\n", j, reply->element[j]->str);
        }
    }
    freeReplyObject(reply);

	int keytest = 1;
	int keyvalue = 12345;
	redisCommand(c,"set %d %d",keytest,keyvalue);
    reply = redisCommand(c,"get %d",keytest);
	printf("keytest: %s\n",reply->str);

	char* keyname = "test";
    reply = redisCommand(c,"GET %s",keyname);
    printf("GET foo: %s\n", reply->str);
	char* test = reply->str;
	double test1 = atof(test);
	printf("test value: %f\n",test1);
    freeReplyObject(reply);

    reply = redisCommand(c,"SETNX %s %f", "test", 0.0);
    printf("SET: %s\n", reply->str);
    freeReplyObject(reply);

	reply = redisCommand(c,"DEL test");
	reply = redisCommand(c,"SETNX %s %f","test",0.0);
	reply = redisCommand(c,"get test");
	test1 = atof(reply->str);
	printf("test1 value: %f\n",test1);

	double RTS;
    reply = redisCommand(c,"GET %u",13);
	if(reply->str == NULL)
		RTS = 0.0;
	else
		RTS = atof(reply->str);  // 得到之前总和
    redisCommand(c,"del %u",13);
    RTS = RTS + (553781316544076.000000 - 553781302580089.000000);
	printf("RTS: %f\n",RTS);
    redisCommand(c,"SETNX %u %f",13,RTS);

    freeReplyObject(reply);

    /* Disconnects and frees the context */
    redisFree(c);

    return 0;
}
