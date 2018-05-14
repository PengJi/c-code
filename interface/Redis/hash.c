#include <hiredis/hiredis.h>

/**
 * https://redis.io/commands#hash
 * 
 * HSET
 * HDEL
 * HGET
 * HLEN
 * HMSET
 * HMGET
 * HKEYS
 * HVALS
 * HGETALL
 * HSTRLEN
 * HINCRBY
 * HINCRBYFLOAT
 * HEXISTS
 * HSETNX
 * HSCAN
 */

redisReply *reply;
redisContext *c;
char key[] = "user-1";

void hset() {
	printf("---------------------------------------------------\n");
	printf("HSET key field value -> Integer reply, specifically:\n");
	printf("\t1 if field is a new field in the hash and value was set.\n");
	printf("\t0 if field already exists in the hash and the value was updated.\n");
	reply = redisCommand(c, "DEL %s", key);
 	freeReplyObject(reply);
	// #1 HSET key field value
	reply = redisCommand(c, "HSET %s %s %s", key, "email", "charlie@redisgate.com");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 

	printf("1. HSET %s %s %s -> %d\n", key, "email", "charlie@redisgate.com", reply->integer);
 	freeReplyObject(reply);
	reply = redisCommand(c, "HSET %s %s %s", key, "language", "english");
	printf("2. HSET %s %s %s -> %d\n", key, "language", "english", reply->integer);
 	freeReplyObject(reply);
	reply = redisCommand(c, "HSET %s %s %s", key, "gender", "m");
	printf("3. HSET %s %s %s -> %d\n", key, "gender", "m", reply->integer);
 	freeReplyObject(reply);
}

void hdel() {
	printf("---------------------------------------------------\n");
	printf("HDEL key field [field ...]-> Integer reply: the number of fields that were removed from the hash,\n"); 
	printf("\tnot including specified but non existing fields.\n");
	// #1 HDEL key field
	reply = redisCommand(c, "HDEL %s %s %s", key, "email", "language");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HDEL %s %s %s -> %d\n", key, "email", "language", reply->integer);
 	freeReplyObject(reply);
}

void hget() {
	printf("---------------------------------------------------\n");
	printf("HGET key field -> Bulk string reply: the value associated with field,\n");
	printf("\tor nil when field is not present in the hash or key does not exist.\n"); 
	// #1 HGET key field
	reply = redisCommand(c, "HGET %s %s", key, "gender");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HGET %s %s -> %s\n", key, "gender", reply->str);
 	freeReplyObject(reply);
}

void hlen() {
	printf("---------------------------------------------------\n");
	printf("HLEN key -> Integer reply: number of fields in the hash, or 0 when key does not exist.\n");
	// #1 HLEN key
	reply = redisCommand(c, "HLEN %s", key);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HLEN %s -> %d\n", key, reply->integer);
 	freeReplyObject(reply);
}

void hmset() {
	printf("---------------------------------------------------\n");
	printf("HMSET key field value [field value ...] -> Simple string reply.\n");
	// #1 HMSET key field value
	reply = redisCommand(c, "HMSET %s %s %s %s %s", key, "email", "charlie@redisgate.com", "language", "english");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HMSET %s %s %s %s %s -> %s\n", key, "email", "charlie@redisgate.com", "language", "english", reply->str);
 	freeReplyObject(reply);
}

void hmget() {
	printf("---------------------------------------------------\n");
	printf("HMGET key field [field ...] -> Array reply: list of values associated with the given fields,\n");
	printf("\tin the same order as they are requested.\n");
	int i;
	// #1 HMGET key field 
	reply = redisCommand(c, "HMGET %s %s %s %s", key, "email", "language", "gender");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HMGET %s %s %s %s -> %d\n", key, "email", "language", "gender", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void hkeys() {
	printf("---------------------------------------------------\n");
	printf("HKEYS key -> Array reply: list of fields in the hash,\n");
	printf("\tor an empty list when key does not exist.\n");
	int i;
	// #1 HKEYS key 
	reply = redisCommand(c, "HKEYS %s", key);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HKEYS %s -> %d\n", key, reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void hvals() {
	printf("---------------------------------------------------\n");
	printf("HVALS key -> Array reply: list of values in the hash,\n");
	printf("\tor an empty list when key does not exist.\n");
	int i;
	// #1 HKEYS key 
	reply = redisCommand(c, "HVALS %s", key);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HVALS %s -> %d\n", key, reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void hgetall() {
	printf("---------------------------------------------------\n");
	printf("HGETALL key -> Array reply: list of fields and their values stored in the hash,\n");
	printf("\tor an empty list when key does not exist.\n");
	int i;
	// #1 HGETALL key 
	reply = redisCommand(c, "HGETALL %s", key);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HGETALL %s -> %d\n", key, reply->elements);
	for(i=0;i<reply->elements;i++) {
		if (i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void hstrlen() {
	printf("---------------------------------------------------\n");
	printf("HSTRLEN key field -> Integer reply: the string length of the value associated with field,\n");
	printf("\tor zero when field is not present in the hash or key does not exist at all.\n");
	int i;
	// #1 HSTRLEN key field
	reply = redisCommand(c, "HSTRLEN %s %s", key, "email");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HSTRLEN %s %s -> %d\n", key, "email", reply->integer);
 	freeReplyObject(reply);
}

void hincrby() {
	printf("---------------------------------------------------\n");
	printf("HINCRBY key field incrment -> Integer reply: the value at field after the increment operation.\n");
	int i;
	// #1 HINCRBY key field incrment
	reply = redisCommand(c, "HINCRBY %s %s %d", key, "visits", 1);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HINCRBY %s %s 1 -> %d\n", key, "visits", reply->integer);
 	freeReplyObject(reply);
	// #2 HINCRBY key field incrment
	reply = redisCommand(c, "HINCRBY %s %s %d", key, "visits", 5);
	printf("2. HINCRBY %s %s 5 -> %d\n", key, "visits", reply->integer);
 	freeReplyObject(reply);
}

void hincrbyfloat() {
	printf("---------------------------------------------------\n");
	printf("HINCRBYFLOAT key field incrment -> \e[5;32;1mBulk string reply\e[m: the value of field after the increment.\n");
	int i;
	// #1 HINCRBYFLOAT key field incrment
	reply = redisCommand(c, "HINCRBYFLOAT %s %s %f", key, "weight", 75.6);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HINCRBYFLOAT %s %s 75.6 -> %s\n", key, "weight", reply->str);
 	freeReplyObject(reply);
	// #2 HINCRBYFLOAT key field incrment
	reply = redisCommand(c, "HINCRBYFLOAT %s %s %f", key, "weight", 12.6);
	printf("2. HINCRBYFLOAT %s %s 12.6 -> %s\n", key, "weight", reply->str);
 	freeReplyObject(reply);
}

void hexists() {
	printf("---------------------------------------------------\n");
	printf("HEXISTS key field -> Integer reply, specifically:\n");
	printf("\t1 if the hash contains field.\n");
	printf("\t0 if the hash does not contain field, or key does not exist.\n");
	int i;
	// #1 HEXISTS key field
	reply = redisCommand(c, "HEXISTS %s %s", key, "email");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HEXISTS %s %s -> %d\n", key, "email", reply->integer);
 	freeReplyObject(reply);
}

void hsetnx() {
	printf("---------------------------------------------------\n");
	printf("HSETNX key field value -> Integer reply, specifically:\n");
	printf("\t1 if field is a new field in the hash and value was set.\n");
	printf("\t0 if field already exists in the hash and no operation was performed.\n");
	int i;
	// #1 HSETNX key field value
	reply = redisCommand(c, "HSETNX %s %s %s", key, "email", "redisgate@gmail.com");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. HSETNX %s %s %s -> %d\n", key, "email", "redisgate@gmail.com", reply->integer);
 	freeReplyObject(reply);
}

void hscan() {
	printf("---------------------------------------------------\n");
	printf("HSCAN key cursor [MATCH pattern] [COUNT count] -> array of elements contain two elements,\n");
	printf("\ta field and a value, for every returned element of the Hash.\n");
	int i;
	char field[10] = "X_field";
	char value[100] = "X_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	reply = redisCommand(c, "DEL myhash");
 	freeReplyObject(reply);
	for(i=65;i<91;i++) {
		field[0] = i;
		value[0] = i;
		reply = redisCommand(c, "HSET myhash %s %s", field, value);
 		freeReplyObject(reply);
	}
	// #1 HSCAN myhash cursor
	char cursor[10] = "0";	
	do {
		reply = redisCommand(c, "HSCAN myhash %s",cursor);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
		}
		printf("HSCAN myhash %s\n", cursor);
		for(i=0;i<reply->element[1]->elements;i++) {
			if(i%2 == 0) {
				printf("%d) %s ", i, reply->element[1]->element[i]->str);
			} else {
				printf("%s\n", reply->element[1]->element[i]->str);
			}
		}
		printf("next cursor -> %s\n", reply->element[0]->str);
		strcpy(cursor, reply->element[0]->str);
 		freeReplyObject(reply);
	} while( strcmp(cursor, "0") );
}

int main(){
	return 0;
}
