#include <hiredis/hiredis.h>

/**
 * EXISTS
 * UNLINK
 * KEYS
 * SCAN
 * SORT
 * RENAME
 * RENAMENX
 * EXPIRE
 * EXPIREAT
 * TTL
 * PEXPIRE
 * PEXPIREAT
 * PTTL
 * PERSIST
 * TYPE
 * OBJECT
 * RANDOMKEY
 * MOVE
 * DUMP
 * RESTORE
 * MIGRATE
 * TOUCH
 */

redisReply *reply;
redisContext *c;
char randomKey[100];
char value[100];
int valueLen;

void exists() {
	printf("---------------------------------------------------\n");
	printf("EXISTS key -> Integer reply, specifically:\n");
	printf("\t1 if the key exists.\n");
	printf("\t0 if the key does not exist.\n");
	// #1 EXISTS key
	reply = redisCommand(c, "EXISTS key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. EXISTS key -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void unlink() {
	printf("---------------------------------------------------\n");
	printf("UNLINK key [key ...] -> Integer reply: The number of keys that were unlinked.\n");
	// #1 UNLINK key
	reply = redisCommand(c, "UNLINK key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. UNLINK key -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void keys() {
	printf("---------------------------------------------------\n");
	printf("KEYS pattern -> Array reply: list of keys matching pattern.\n");
	int i;
	for(i=0;i<100;i++) {
		reply = redisCommand(c, "SET key-%d value-%d", i, i);
 		freeReplyObject(reply);
	}
	// #1 KEYS *
	reply = redisCommand(c, "KEYS *");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. KEYS * -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void scan() {
	printf("---------------------------------------------------\n");
	printf("SCAN cursor [MATCH pattern] [COUNT count] -> array of elements is a list of keys.\n"); 
	int i;
	// #1 SCAN cursor
	char cursor[10] = "0";	
	do {
		reply = redisCommand(c, "SCAN %s",cursor);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
		}
		printf("SCAN %s\n", cursor);
		for(i=0;i<reply->element[1]->elements;i++) {
			printf("%d) %s\n", i, reply->element[1]->element[i]->str);
		}
		printf("next cursor -> %s\n", reply->element[0]->str);
		strcpy(cursor, reply->element[0]->str);
 		freeReplyObject(reply);
	} while( strcmp(cursor, "0") );
}

void sort() {
	printf("---------------------------------------------------\n");
	printf("SORT key [BY pattern] [LIMIT offset count] [GET pattern [GET pattern ...]] [ASC|DESC] [ALPHA] [STORE destination] ->\n"); 
	printf("\tArray reply: without passing the store option the command returns a list of sorted elements.\n"); 
	printf("\tInteger reply: when the store option is specified the command returns the number of sorted elements in the destination list.\n"); 
	int i;
	reply = redisCommand(c, "SADD myurl Google.com Facebook.com Youtube.com Yahoo.com Baidu.com");
 	freeReplyObject(reply);
	// #1 SORT
	reply = redisCommand(c, "SORT myurl ALPHA");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. SORT myurl ALPHA\n");
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void rename_redis() {
	printf("---------------------------------------------------\n");
	printf("RENAME key new_key -> Simple string reply.\n");
	// #1 RENAME
	reply = redisCommand(c, "RENAME key-1 new_key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. RENAME key-1 new_key -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void renamenx() {
	printf("---------------------------------------------------\n");
	printf("RENAMENX key new_key -> Integer reply, specifically:\n");
	printf("\t1 if key was renamed to newkey.\n");
	printf("\t0 if newkey already exists.\n");
	// #1 RENAMENX
	reply = redisCommand(c, "RENAMENX key-2 new_key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. RENAMENX key-2 new_key -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void expire() {
	printf("---------------------------------------------------\n");
	printf("EXPIRE key seconds -> Integer reply, specifically:\n");
	printf("\t1 if the timeout was set. 0 if key does not exist.\n");
	// #1 EXPIRE 
	reply = redisCommand(c, "EXPIRE key-3 10");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. EXPIRE key-3 10 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void expireat() {
	printf("---------------------------------------------------\n");
	printf("EXPIREAT key timestamp -> Integer reply, specifically:\n");
	printf("\t1 if the timeout was set. 0 if key does not exist.\n");
	time_t now = time(NULL);
	now += 10;
	// #1 EXPIREAT 
	reply = redisCommand(c, "EXPIREAT key-4 %d", now);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. EXPIREAT key-4 %d -> %d\n", now, reply->integer);
 	freeReplyObject(reply);
}

void ttl() {
	printf("---------------------------------------------------\n");
	printf("TTL key -> Integer reply: TTL in seconds, or a negative value in order to signal an error.\n");
	printf("\tThe command returns -2 if the key does not exist.\n");
	printf("\tThe command returns -1 if the key exists but has no associated expire.\n");
	// #1 TTL
	reply = redisCommand(c, "TTL key-3");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. TTL key-3 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void pexpire() {
	printf("---------------------------------------------------\n");
	printf("PEXPIRE key milliseconds -> Integer reply, specifically: 1 if the timeout was set. 0 if key does not exist.\n");
	// #1 PEXPIRE 
	reply = redisCommand(c, "PEXPIRE key-5 10000");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. EXPIRE key-5 10000 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void pexpireat() {
	printf("---------------------------------------------------\n");
	printf("PEXPIREAT key milliseconds-timestamp -> Integer reply, specifically:\n");
	printf("\t1 if the timeout was set. 0 if key does not exist.\n");
	time_t now = time(NULL);
	now += (10*1000);
	// #1 EXPIREAT 
	reply = redisCommand(c, "PEXPIREAT key-6 %d", now);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. EXPIREAT key-6 %d -> %d\n", now, reply->integer);
 	freeReplyObject(reply);
}

void pttl() {
	printf("---------------------------------------------------\n");
	printf("PTTL key -> Integer reply: TTL in milliseconds, or a negative value in order to signal an error.\n");
	printf("\tThe command returns -2 if the key does not exist.\n");
	printf("\tThe command returns -1 if the key exists but has no associated expire.\n");
	// #1 PTTL
	reply = redisCommand(c, "PTTL key-5");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. PTTL key-5 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void persist() {
	printf("---------------------------------------------------\n");
	printf("PERSIST key -> Integer reply: TTL in milliseconds, or a negative value in order to signal an error.\n");
	printf("\tThe command returns -2 if the key does not exist.\n");
	printf("\tThe command returns -1 if the key exists but has no associated expire.\n");
	// #1 PERSIST
	reply = redisCommand(c, "PERSIST key-6");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. PERSIST key-6 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void type() {
	printf("---------------------------------------------------\n");
	printf("TYPE key -> Simple string reply: type of key, or none when key does not exist.\n");
	// #1 TYPE Strings
	reply = redisCommand(c, "SET key value");
 	freeReplyObject(reply);
	reply = redisCommand(c, "TYPE key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. TYPE key -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #2 TYPE Lists
	reply = redisCommand(c, "LPUSH mylist value");
 	freeReplyObject(reply);
	reply = redisCommand(c, "TYPE mylist");
	printf("2. TYPE mylist -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #3 TYPE Sets
	reply = redisCommand(c, "SADD myset value");
 	freeReplyObject(reply);
	reply = redisCommand(c, "TYPE myset");
	printf("3. TYPE myset -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #4 TYPE ZSets
	reply = redisCommand(c, "ZADD myzset 10 value");
 	freeReplyObject(reply);
	reply = redisCommand(c, "TYPE myzset");
	printf("4. TYPE myzset -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #5 TYPE Hashes
	reply = redisCommand(c, "HSET myhash field value");
 	freeReplyObject(reply);
	reply = redisCommand(c, "TYPE myhash");
	printf("5. TYPE myhash -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void object() {
	printf("---------------------------------------------------\n");
	printf("OBJECT subcommand [arguments [arguments ...]] -> Different return values are used for different subcommands.\n");
	printf("\tSubcommands refcount and idletime return integers.\n");
	printf("\tSubcommand encoding returns a bulk reply.\n");
	printf("\t1. Strings: embstr, raw, int\n");
	printf("\t2. Lists: quicklist, ziplist, linkedlist\n");
	printf("\t3. Sets: intset, hashtable\n");
	printf("\t4. ZSets: ziplist, skiplist\n");
	printf("\t5. Hashes: ziplist, hashtable\n");
	printf("\tIf the object you try to inspect is missing, a null bulk reply is returned.\n");
	// #1 OBJECT ENCODING Strings
	reply = redisCommand(c, "OBJECT ENCODING key");
	printf("1. OBJECT ENCODING key -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #2 OBJECT ENCODING Lists
	reply = redisCommand(c, "OBJECT ENCODING mylist");
	printf("2. OBJECT ENCODING mylist -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #3 OBJECT ENCODING Sets
	reply = redisCommand(c, "OBJECT ENCODING myset");
	printf("3. OBJECT ENCODING myset -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #4 OBJECT ENCODING ZSets
	reply = redisCommand(c, "OBJECT ENCODING myzset");
	printf("4. OBJECT ENCODING myzset -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #5 OBJECT ENCODING Hashes
	reply = redisCommand(c, "OBJECT ENCODING myhash");
	printf("5. OBJECT ENCODING myhash -> %s\n", reply->str);
 	freeReplyObject(reply);

	// #6 OBJECT IDLETIME
	reply = redisCommand(c, "OBJECT IDLETIME key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("6. OBJECT IDLETIME key -> %d\n", reply->integer);
 	freeReplyObject(reply);

	// #7 OBJECT REFCOUNT 
	reply = redisCommand(c, "OBJECT REFCOUNT key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("7. OBJECT REFCOUNT key -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void randomkey() {
	printf("---------------------------------------------------\n");
	printf("RANDOMKEY -> Bulk string reply: the random key, or nil when the database is empty.\n");
	// #1 RANDOMKEY
	reply = redisCommand(c, "RANDOMKEY");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. RANDOMKEY -> %s\n", reply->str);
	strcpy(randomKey, reply->str);
 	freeReplyObject(reply);
}

void move() {
	printf("---------------------------------------------------\n");
	printf("MOVE key db -> Integer reply, specifically: 1 if key was moved. 0 if key was not moved.\n");
	// #1 MOVE 
	reply = redisCommand(c, "MOVE %s 1", randomKey);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. MOVE %s 1 -> %d\n", randomKey, reply->integer);
 	freeReplyObject(reply);
	// #2 SELECT
	reply = redisCommand(c, "SELECT 1");
	printf("2. SELECT 1 -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #3 GET 
	reply = redisCommand(c, "GET %s", randomKey);
	printf("1. GET %s -> %s\n", randomKey, reply->str);
 	freeReplyObject(reply);
	reply = redisCommand(c, "SELECT 0");
 	freeReplyObject(reply);
}

void dump() {
	printf("---------------------------------------------------\n");
	printf("DUMP key -> Bulk string reply: the serialized value.\n");
	int i;
	reply = redisCommand(c, "GET key");
	printf("GET key -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #1 DUMP key
	reply = redisCommand(c, "DUMP key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. DUMP key -> %i, %s\n", reply->len, reply->str);
	for (i=0; i<reply->len; i++) {
		printf("%c = 0x%02X\n", reply->str[i], reply->str[i]);
		value[i] = reply->str[i];
	}
	valueLen = reply->len+1;
 	freeReplyObject(reply);
	// #2 DUMP mylist
	reply = redisCommand(c, "DUMP myset");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("2. DUMP mylist -> %i\n", reply->len);
	for (i=0; i<reply->len; i++) {
		printf("%c = 0x%02X\n", reply->str[i], reply->str[i]);
	}
  freeReplyObject(reply);
}

void restore() {
	printf("---------------------------------------------------\n");
	printf("RESTORE key ttl serialized-value [REPLACE] -> Simple string reply: The command returns OK on success.\n");
	int i;
	reply = redisCommand(c, "DEL key");
 	freeReplyObject(reply);
	// #1 RESTORE key
	reply = redisCommand(c, "RESTORE key 0 %b", value, (size_t) valueLen);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. RESTORE key -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void migrate() {
	printf("---------------------------------------------------\n");
	printf("MIGRATE host port key|"" destination-db timeout [COPY] [REPLACE] [KEYS key [key ...]] -> Simple string reply:\n");
	printf("\tThe command returns OK on success, or NOKEY if no keys were found in the source instance.\n");
	int i;
	reply = redisCommand(c, "SET key value");
 	freeReplyObject(reply);
	// #1 MIGRATE
	reply = redisCommand(c, "MIGRATE 127.0.0.1 6002 key 0 10000");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. MIGRATE key -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void touch() {
	printf("---------------------------------------------------\n");
	printf("TOUCH key [key ...] -> Integer reply: The number of keys that were touched.\n");
	int i;
	// #1 TOUCH
	reply = redisCommand(c, "TOUCH key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
	}
	printf("1. TOUCH key -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

int main(){
	return 0;
}
