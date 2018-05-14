#include <hiredis/hiredis.h>

/**
 * https://redis.io/commands#list
 * 
 * LPUSH
 * RPOP
 * LPOP
 * RPUSH
 * LRANGE
 * LLEN
 * LINDEX
 * LSET
 * LINSERT
 * LREM
 * LTRIM
 * RPOPLPUSH
 * LPUSHX
 * RPUSHX
 * BLPOP
 * BRPOP
 * BRPOPLPUSH
 */

redisReply *reply;
redisContext *c;

void lpush() {
  printf("---------------------------------------------------\n");
  printf("LPUSH key value [value ...] -> Integer reply: the length of the list after the push operations.\n");
  // #1 LPUSH mylist value1 value2 value3
  reply = redisCommand(c, "LPUSH mylist value1 value2 value3");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LPUSH mylist value1 value2 value3 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // LRANGE
  reply = redisCommand(c, "LRANGE mylist 0 -1");
  printf("2. LRANGE mylist 0 -1 -> %d\n", reply->elements);
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("\t%d) %s\n", i, reply->element[i]->str);
  }
  getchar();
}

void rpop() {
  printf("---------------------------------------------------\n");
  printf("RPOP key -> Bulk string reply: the value of the last element, or nil when key does not exist.\n");
  // #1 RPOP mylist
  reply = redisCommand(c, "RPOP mylist");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. RPOP mylist -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

void lpop() {
  printf("---------------------------------------------------\n");
  printf("LPOP key -> Bulk string reply: the value of the first element, or nil when key does not exist.\n");
  // #1 LPOP mylist
  reply = redisCommand(c, "LPOP mylist");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LPOP mylist -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

void rpush() {
  printf("---------------------------------------------------\n");
  printf("RPUSH key value [value ...] -> Integer reply: the length of the list after the push operation.\n");
  // #1 RPUSH mylist Rvalue1
  reply = redisCommand(c, "RPUSH mylist Rvalue1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. RPUSH mylist Rvalue1 -> %d\n", reply->integer);
  freeReplyObject(reply);
  getchar();
}

void lrange() {
  printf("---------------------------------------------------\n");
  printf("LRANGE key start stop -> Array reply: list of elements in the specified range.\n");
  // #1 LRANGE mylist 0 -1
  reply = redisCommand(c, "LRANGE mylist 0 -1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LRANGE mylist 0 -1 -> %d\n", reply->elements);
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  // #2 LRANGE mylist 2 4
  reply = redisCommand(c, "LRANGE mylist 2 4");
  printf("2. LRANGE mylist 2 4 -> %d\n", reply->elements);
  for(i=0; i<reply->elements; i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void llen() {
  printf("---------------------------------------------------\n");
  printf("LLEN key -> Integer reply: the length of the list at key.\n");
  // #1 LLEN mylist 
  reply = redisCommand(c, "LLEN mylist");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LLEN mylist -> %d\n", reply->integer);
  freeReplyObject(reply);
  getchar();
}

void lindex() {
  printf("---------------------------------------------------\n");
  printf("LINDEX key index -> Bulk string reply: the requested element, or nil when index is out of range.\n");
  // #1 LINDEX mylist 1
  reply = redisCommand(c, "LINDEX mylist 1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LINDEX mylist 1 -> %s\n", reply->str);
  freeReplyObject(reply);
  // #2 LINDEX mylist 5
  reply = redisCommand(c, "LINDEX mylist 5");
  printf("2. LINDEX mylist 5 -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

void lset() {
  printf("---------------------------------------------------\n");
  printf("LSET key index value -> Simple string(OK) reply.\n");
  // #1 LSET mylist 1 XXXXX
  reply = redisCommand(c, "LSET mylist 1 XXXXX");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LSET  mylist 1 XXXXX -> %s\n", reply->str);
  freeReplyObject(reply);
  // #2 LRANGE mylist 0 2
  reply = redisCommand(c, "LRANGE mylist 0 2");
  printf("2. LRANGE mylist 0 2 -> %d\n", reply->elements);
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void linsert() {
  printf("---------------------------------------------------\n");
  printf("LINSERT key BEFORE|AFTER pivot value -> Integer reply: \n");
  printf("\tthe length of the list after the insert operation,\n");
  printf("\tor -1 when the value pivot was not found.\n");
  // #1 LINSERT mylist BEFORE XXXXX BeforeValue
  reply = redisCommand(c, "LINSERT mylist BEFORE XXXXX BeforeValue");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LINSERT mylist BEFORE XXXXX BeforeValue -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 LINSERT mylist AFTER XXXXX AFTERValue
  reply = redisCommand(c, "LINSERT mylist AFTER XXXXX AFTERValue");
  printf("2. LINSERT mylist AFTER XXXXX AFTERValue -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #3 LRANGE mylist 0 5
  reply = redisCommand(c, "LRANGE mylist 0 5");
  printf("3. LRANGE mylist 0 5 -> %d\n", reply->elements);
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void lrem() {
  printf("---------------------------------------------------\n");
  printf("LREM key count value -> Integer reply: the number of removed elements.\n");
  // #1 LREM mylist 0 XXXXX
  reply = redisCommand(c, "LREM mylist 0 XXXXX");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LREM mylist 0 XXXXX -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 LRANGE mylist 0 10
  reply = redisCommand(c, "LRANGE mylist 0 10");
  printf("2. LRANGE mylist 0 10 -> %d\n", reply->elements);
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void ltrim() {
  printf("---------------------------------------------------\n");
  printf("LTRIM key start stop -> Simple string reply.\n");
  // #1 LTRIM mylist 1 3
  reply = redisCommand(c, "LTRIM mylist 1 3");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LTRIM mylist 1 3 -> %s\n", reply->str);
  freeReplyObject(reply);
  // #2 LRANGE mylist 0 -1
  reply = redisCommand(c, "LRANGE mylist 0 -1");
  printf("2. LRANGE mylist 0 -1 -> %d\n", reply->elements);
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void rpoplpush() {
  printf("---------------------------------------------------\n");
  printf("RPOPLPUSH source_key destination_key -> Bulk string reply:\n");
  printf("\tthe element being popped from source and pushed to destination.\n");
  printf("\tIf timeout is reached, a Null reply is returned.\n");
  // #1 RPOPLPUSH mylist destkey
  reply = redisCommand(c, "RPOPLPUSH mylist destkey");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. RPOPLPUSH mylist destkey -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

void lpushx() {
  printf("---------------------------------------------------\n");
  printf("LPUSHX key value -> Integer reply: the length of the list after the push operation.\n");
  // #1 LPUSHX mylist2 value1
  reply = redisCommand(c, "LPUSHX mylist2 value1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. LPUSHX mylist2 value1 -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

void rpushx() {
  printf("---------------------------------------------------\n");
  printf("RPUSHX key value -> Integer reply: the length of the list after the push operation.\n");
  // #1 RPUSHX mylist2 value1
  reply = redisCommand(c, "RPUSHX mylist2 value1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. RPUSHX mylist2 value1 -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

void blpop() {
  printf("---------------------------------------------------\n");
  printf("BLPOP key [key ...] timeout -> Array reply: specifically:\n");
  printf("\tA nil multi-bulk when no element could be popped and the timeout expired.\n");
  printf("\tA two-element multi-bulk with the first element being the name of the key\n");
  printf("\twhere an element was popped and the second element being the value of the popped element.\n");
  // #1 BLPOP mylist 10
  reply = redisCommand(c, "BLPOP mylist 10");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. BLPOP mylist 10 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  // #2 BLPOP mylist2 10
  reply = redisCommand(c, "BLPOP mylist2 10");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("2. BLPOP mylist2 10 -> %d\n", reply->elements);
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void brpop() {
  printf("---------------------------------------------------\n");
  printf("BRPOP key [key ...] timeout -> Array reply: specifically:\n");
  printf("\tA nil multi-bulk when no element could be popped and the timeout expired.\n");
  printf("\tA two-element multi-bulk with the first element being the name of the key\n");
  printf("\twhere an element was popped and the second element being the value of the popped element.\n");
  // #1 BRPOP mylist 10
  reply = redisCommand(c, "BRPOP mylist 10");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. BRPOP mylist 10 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  getchar();
}

void brpoplpush() {
  printf("---------------------------------------------------\n");
  printf("BRPOPLPUSH source destination timeout -> Bulk string reply:\n");
  printf("\tthe element being popped from source and pushed to destination.\n");
  printf("\tIf timeout is reached, a Null reply is returned.\n");
  // #1 BRPOPLPUSH mylist destkey
  reply = redisCommand(c, "BRPOPLPUSH mylist destkey 10");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. BRPOPLPUSH mylist destkey 10 -> %s\n", reply->str);
  freeReplyObject(reply);
  getchar();
}

int main(){

	return 0;
}
