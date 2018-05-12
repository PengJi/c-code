#include <hiredis/hiredis.h>

redisReply *reply;
redisContext *c;

void sadd() {
  printf("---------------------------------------------------\n");
  printf("SADD key member [member ...] -> Integer reply:\n");
  printf("\tthe number of elements that were added to the set,\n");
  printf("\tnot including all the elements already present into the set\n");
  // #1 SADD myset value1 value2 value3
  reply = redisCommand(c, "SADD myset value1 value2 value3");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SADD myset value1 value2 value3 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void srem() {
  printf("---------------------------------------------------\n");
  printf("SREM key member [member ...] -> Integer reply:\n");
  printf("\tthe number of members that were removed from the set,\n");
  printf("\tnot including non existing members.\n");
  // #1 SREM myset value1 value2
  reply = redisCommand(c, "SREM myset value1 value2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SREM myset value1 value2 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void smembers() {
  printf("---------------------------------------------------\n");
  printf("SMEMBERS key -> Array reply: all elements of the set.\n");
  // #1 SMEMBERS myset
  reply = redisCommand(c, "SMEMBERS myset");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SMEMBERS myset -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void scard() {
  printf("---------------------------------------------------\n");
  printf("SCARD key -> Integer reply:\n");
  printf("\tthe cardinality (number of elements) of the set, or 0 if key does not exist.\n");
  // #1 SCARD myset
  reply = redisCommand(c, "SCARD myset");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SCARD myset -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void sunion() {
  printf("---------------------------------------------------\n");
  printf("SUNION key [key ...] -> Array reply: list with members of the resulting set.\n");
  redisCommand(c, "DEL myset1 myset2");
  redisCommand(c, "SADD myset1 A B C");
  redisCommand(c, "SADD myset2 B C D");
  // #1 SUNION myset1 myset2
  reply = redisCommand(c, "SUNION myset1 myset2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SUNION myset1 myset2 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sinter() {
  printf("---------------------------------------------------\n");
  printf("SINTER key [key ...] -> return Array reply: list with members of the resulting set.\n");
  redisCommand(c, "DEL myset1 myset2");
  redisCommand(c, "SADD myset1 A B C");
  redisCommand(c, "SADD myset2 B C D");
  // #1 SINTER myset1 myset2
  reply = redisCommand(c, "SINTER myset1 myset2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SINTER myset1 myset2 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sdiff() {
  printf("---------------------------------------------------\n");
  printf("SDIFF key [key ...] -> return Array reply: list with members of the resulting set.\n");
  redisCommand(c, "DEL myset1 myset2");
  redisCommand(c, "SADD myset1 A B C");
  redisCommand(c, "SADD myset2 B D");
  // #1 SINTER myset1 myset2
  reply = redisCommand(c, "SDIFF myset1 myset2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SDIFF myset1 myset2 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sunionstore() {
  printf("---------------------------------------------------\n");
  printf("SUNIONSTORE destination_key source_key [source_key ...] -> Integer reply:\n"); 
  printf("\tthe number of elements in the resulting set.\n");
  redisCommand(c, "DEL myset1 myset2");
  redisCommand(c, "SADD myset1 A B C");
  redisCommand(c, "SADD myset2 B C D");
  // #1 SUNIONSTORE dest_key myset1 myset2
  reply = redisCommand(c, "SUNIONSTORE dest_key myset1 myset2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SUNIONSTORE dest_key myset1 myset2 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // 2. SMEMBERS dest_key
  reply = redisCommand(c, "SMEMBERS dest_key");
  printf("2. SMEMBERS dest_key -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sinterstore() {
  printf("---------------------------------------------------\n");
  printf("SINTERSTORE destination_key source_key [source_key ...] -> Integer reply:\n"); 
  printf("\tthe number of elements in the resulting set.\n");
  redisCommand(c, "DEL myset1 myset2");
  redisCommand(c, "SADD myset1 A B C");
  redisCommand(c, "SADD myset2 B C D");
  // #1 SINTERSTORE dest_key myset1 myset2
  reply = redisCommand(c, "SINTERSTORE dest_key myset1 myset2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SINTERSTORE dest_key myset1 myset2 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // 2. SMEMBERS dest_key
  reply = redisCommand(c, "SMEMBERS dest_key");
  printf("2. SMEMBERS dest_key -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sdiffstore() {
  printf("---------------------------------------------------\n");
  printf("SDIFFSTORE destination_key source_key [source_key ...] -> Integer reply:\n"); 
  printf("\tthe number of elements in the resulting set.\n");
  redisCommand(c, "DEL myset1 myset2");
  redisCommand(c, "SADD myset1 A B C");
  redisCommand(c, "SADD myset2 B D");
  // #1 SDIFFSTORE dest_key myset1 myset2
  reply = redisCommand(c, "SDIFFSTORE dest_key myset1 myset2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SDIFFSTORE dest_key myset1 myset2 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // 2. SMEMBERS dest_key
  reply = redisCommand(c, "SMEMBERS dest_key");
  printf("2. SMEMBERS dest_key -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sismember() {
  printf("---------------------------------------------------\n");
  printf("SISMEMBER key member -> Integer reply, specifically:\n"); 
  printf("\t1 if the element is a member of the set.\n");
  printf("\t0 if the element is not a member of the set, or if key does not exist.\n");
  redisCommand(c, "DEL myset");
  redisCommand(c, "SADD myset mem_1 mem_2");
  // #1 SISMEMBER myset mem_1
  reply = redisCommand(c, "SISMEMBER myset mem_1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SISMEMBER myset mem_1 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 SISMEMBER myset mem_X
  reply = redisCommand(c, "SISMEMBER myset mem_X");
  printf("2. SISMEMBER myset mem_X -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void smove() {
  printf("---------------------------------------------------\n");
  printf("SMOVE source_key destination_key member -> Integer reply, specifically:\n"); 
  printf("\t1 if the element is moved.\n");
  printf("\t0 if the element is not a member of source and no operation was performed.\n");
  reply = redisCommand(c, "DEL src_key dest_key");
  freeReplyObject(reply);
  reply = redisCommand(c, "SADD src_key A B C");
  freeReplyObject(reply);
  reply = redisCommand(c, "SADD dest_key D");
  freeReplyObject(reply);
  reply = redisCommand(c, "SMEMBERS src_key");
  printf("SMEMBERS src_key\n");
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  reply = redisCommand(c, "SMEMBERS dest_key");
  printf("SMEMBERS dest_key\n");
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  // #1 SMOVE src_key dest_key A
  reply = redisCommand(c, "SMOVE src_key dest_key A");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SMOVE src_key dest_key A -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "SMEMBERS src_key");
  printf("SMEMBERS src_key\n");
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
  reply = redisCommand(c, "SMEMBERS dest_key");
  printf("SMEMBERS dest_key\n");
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void spop() {
  // bold green blink
  printf("---------------------------------------------------\n");
  printf("SPOP key [count] -> \e[5;32;1mBulk string reply\e[m: the removed element, or nil when key does not exist.\n"); 
  printf("\t\e[5;32;1mArray reply\e[m: when the additional count argument is passed the command returns an array of elements,\n");
  printf("\tor an empty array when key does not exist.\n");
  reply = redisCommand(c, "DEL myset");
  freeReplyObject(reply);
  reply = redisCommand(c, "SADD myset mem_1 mem_2 mem_3");
  freeReplyObject(reply);
  // #1 SPOP myset
  reply = redisCommand(c, "SPOP myset");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  }
  printf("1. SPOP myset -> %s\n", reply->str);
  freeReplyObject(reply);
  // #2 SPOP myset 2
  reply = redisCommand(c, "SPOP myset 2");
  printf("2. SPOP myset 2 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void srandmember() {
  // bold green blink
  printf("---------------------------------------------------\n");
  printf("SRANDMEMBER key [count] -> \e[5;32;1mBulk string reply\e[m: without the additional count argument the command returns\n"); 
  printf("\ta Bulk Reply with the randomly selected element, or nil when key does not exist.\n");
  printf("\t\e[5;32;1mArray reply\e[m: when the additional count argument is passed the command returns an array of elements,\n");
  printf("\tor an empty array when key does not exist.\n");
  reply = redisCommand(c, "DEL myset");
  freeReplyObject(reply);
  reply = redisCommand(c, "SADD myset mem_1 mem_2 mem_3 mem_4 mem_5");
  freeReplyObject(reply);
  // #1 SRANDMEMBER myset
  reply = redisCommand(c, "SRANDMEMBER myset");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
      freeReplyObject(reply);
    return;
  }
  printf("1. SRANDMEMBER myset -> %s\n", reply->str);
  freeReplyObject(reply);
  // #2 SRANDMEMBER myset 2
  reply = redisCommand(c, "SRANDMEMBER myset 2");
  printf("2. SRANDMEMBER myset 2 -> %d\n", reply->elements);
  int i;
  for(i=0;i<reply->elements;i++) {
    printf("%d) %s\n", i, reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void sscan() {
  printf("---------------------------------------------------\n");
  printf("SSCAN key cursor [MATCH pattern] [COUNT count] -> array of elements is a list of Set members.\n"); 
  reply = redisCommand(c, "DEL myset");
  freeReplyObject(reply);
  reply = redisCommand(c, "SADD myset A1 A2 A3 B1 B2 B3 C1 C2 C3 D1 D2 D3 E1 E2 E3");
  freeReplyObject(reply);
  // #1 SSCAN myset cursor
  char cursor[10] = "0";  
  do {
    reply = redisCommand(c, "SSCAN myset %s",cursor);
    if (reply == NULL) {
      printf("redisCommand reply is NULL: %s\n", c->errstr);
      return;
    }
    if (reply->type == REDIS_REPLY_ERROR) {
      printf("Command Error: %s\n", reply->str);
      freeReplyObject(reply);
      return;
    }
    printf("SSCAN myset %s\n", cursor);
    int i;
    for(i=0;i<reply->element[1]->elements;i++) {
      printf("%d) %s\n", i, reply->element[1]->element[i]->str);
    }
    printf("next cursor -> %s\n", reply->element[0]->str);
    strcpy(cursor, reply->element[0]->str);
    freeReplyObject(reply);
  } while( strcmp(cursor, "0") );
}

int main(){
	return 0;
}
