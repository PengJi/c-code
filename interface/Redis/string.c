#include <hiredis/hiredis.h>

/**
 * https://redis.io/commands#string
 * 
 * SET
 * DEL
 * GET
 * INCR
 * DECR
 * INCRBY
 * DECRBY
 * INCRBYFLOAT
 * SETNX
 * SETEX
 * PSETEX
 * MSET
 * MGET
 * MSETNX
 * APPEND
 * STRLEN
 * SETRANGE
 * GETRANGE
 * GETSET
 * SETBIT
 * GETBIT
 * BITOP
 * BITCOUNT
 * BITPOS
 */

redisReply *reply;
redisContext *c;

void set() {
  printf("---------------------------------------------------\n");
  printf("SET key value [NX|XX] [EX seconds] [PX milliseconds] -> Simple string reply: OK or null\n");
  // #1 SET key value
  reply = redisCommand(c, "SET key value");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SET key value -> %s\n", reply->str);
  freeReplyObject(reply);

  // #2 SET key "Hello Redis"
  reply = redisCommand(c, "SET key %s", "Hello Redis");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("2. SET key 'Hello Redis' -> %s\n", reply->str);
  freeReplyObject(reply);

  // #3 SET key1 Hello NX, SET key1 Redis NX -> key
  reply = redisCommand(c, "SET key1 Hello NX");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("3-1. SET key1 Hello NX -> %s\n", reply->str);
  freeReplyObject(reply);

  reply = redisCommand(c, "SET key1 Redis NX");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("3-2. SET key1 Redis NX -> %s\n", reply->str);
  freeReplyObject(reply);

  // #4 SET key2 Hello XX -> key
  reply = redisCommand(c, "SET key2 Hello XX");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("4. SET key2 Hello XX -> %s\n", reply->str);
  freeReplyObject(reply);

  // #5 SET key3 Hello EX 5 -> 5
  reply = redisCommand(c, "SET key3 Hello EX 5");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("5. SET key3 Hello EX 5 -> %s\n", reply->str);
  freeReplyObject(reply);

  // #6 SET key4 Hello PX 5000 - 5000ms
  reply = redisCommand(c, "SET key4 Hello PX 5000");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("6. SET key4 Hello PX 5000 -> %s\n", reply->str);
  freeReplyObject(reply);
}

void del() {
  printf("---------------------------------------------------\n");
  printf("DEL key [key ...] -> Integer reply: The number of keys that were removed.\n");
  // #1 DEL key
  reply = redisCommand(c, "DEL key");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. DEL key -> %d\n", reply->integer);
  freeReplyObject(reply);

  // #2 DEL key1 key2 ...
  reply = redisCommand(c, "DEL key1 key2 key3 key4");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("2. DEL key1 key2 key3 key4 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void get() {
  printf("---------------------------------------------------\n");
  printf("GET key -> Bulk string reply: the value of key, or nil when key does not exist.\n");
  // #1 GET key
  reply = redisCommand(c, "GET key");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. GET key -> %s\n", reply->str);
  freeReplyObject(reply);

  // #2 GET key
  redisCommand(c, "SET key %s", "Hello Redis!");
  reply = redisCommand(c, "GET key");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("2. GET key -> %s\n", reply->str);
  freeReplyObject(reply);
}

void incr() {
  printf("---------------------------------------------------\n");
  printf("INCR key -> Integer reply: the value of key after the increment.\n");
  // #1 INCR visit
  reply = redisCommand(c, "INCR visit");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
   } 
  printf("1. INCR visit -> %d\n", reply->integer);
  reply = redisCommand(c, "INCR visit");
  printf("2. INCR visit -> %d\n", reply->integer);
   freeReplyObject(reply);
}

void decr() {
  printf("---------------------------------------------------\n");
  printf("DECR key -> Integer reply: the value of key after the decrement.\n");
  // #1 DECR visit
  reply = redisCommand(c, "DECR visit");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. DECR visit -> %d\n", reply->integer);
  reply = redisCommand(c, "DECR visit");
  printf("2. DECR visit -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "DECR visit");
  printf("3. DECR visit -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void incrby() {
  printf("---------------------------------------------------\n");
  printf("INCRBY key increment(integer) -> Integer reply: the value of key after the increment.\n");
  // #1 INCRBY visit 10
  reply = redisCommand(c, "INCRBY visit 10");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. INCRBY visit 10 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 INCRBY visit -10 
  reply = redisCommand(c, "INCRBY visit -10");
  printf("2. INCRBY visit -10 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #3 INCRBY visit 2.5 -> Error
  reply = redisCommand(c, "INCRBY visit 2.5");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("3. INCRBY visit 2.5 (Command Error): %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("3. INCRBY visit 2.5 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void decrby() {
  printf("---------------------------------------------------\n");
  printf("DECRBY key decrement(integer) -> Integer reply: the value of key after the decrement.\n");
  // #1 DECRBY visit 10
  reply = redisCommand(c, "DECRBY visit 10");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. DECRBY visit 10 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 DECRBY visit -20
  reply = redisCommand(c, "DECRBY visit -20");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("2. DECRBY visit -20 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void incrbyfloat() {
  printf("---------------------------------------------------\n");
  printf("INCRBYFLOAT key increment -> Bulk string reply: the value of key after the increment.\n");
  printf("\e[5;32;1mCaution\e[m: Not reply->integer But reply->str\n");
  // \e[5[32[1m string \e[m -> Bold and Green Blink
  // #1 INCRBYFLOAT visit 15.6
  reply = redisCommand(c, "INCRBYFLOAT visit 15.6");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. INCRBYFLOAT visit 15.6 -> %s\n", reply->str);
   freeReplyObject(reply);
  // #2 INCRBYFLOAT visit -25.5
  reply = redisCommand(c, "INCRBYFLOAT visit -25.5");
  printf("2. INCRBYFLOAT visit -25.5 -> %s\n", reply->str);
  freeReplyObject(reply);
}

void setnx() {
  printf("---------------------------------------------------\n");
  printf("SETNX key value -> Integer reply, specifically: 1 if the key was set. 0 if the key was not set.\n");
  // #1 SETNX key value
  reply = redisCommand(c, "SETNX key value");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SETNX key value -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void setex() {
  printf("---------------------------------------------------\n");
  printf("SETEX key seconds value -> Simple string reply.\n");
  // #1 SETEX
  reply = redisCommand(c, "SETEX key 5 value");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SETEX key 5 value -> %s\n", reply->str);
  freeReplyObject(reply);
}

void psetex() {
  printf("---------------------------------------------------\n");
  printf("PSETEX key milliseconds value -> Simple string reply.\n");
  // #1 SETEX
  reply = redisCommand(c, "PSETEX key 5000 value");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. PSETEX key 5000 value -> %s\n", reply->str);
  freeReplyObject(reply);
}

void mset() {
  printf("---------------------------------------------------\n");
  printf("MSET key value [key value ...] -> Simple string reply: always OK since MSET can't fail.\n");
  // #1 MSET key1 value1 key2 value2
  reply = redisCommand(c, "MSET key1 value1 key2 value2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. MSET key1 value1 key2 value2 -> %s\n", reply->str);
  freeReplyObject(reply);
}

void mget() {
  printf("---------------------------------------------------\n");
  printf("MGET key [key ...] -> Array reply: list of values at the specified keys.\n");
  // #1 SET key value
  reply = redisCommand(c, "MGET key1 key2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. MGET key1 key2 ->\n");
  int i;
  for(i=0; i<reply->elements; i++) {
    printf("\t%s\n", reply->element[i]->str);
  }
  freeReplyObject(reply);
}

void msetnx() {
  printf("---------------------------------------------------\n");
  printf("MSETNX key value [key value ...] -> Integer reply, specifically: \n");
  printf("\t1 if the all the keys were set.\n");
  printf("\t0 if no key was set (at least one key already existed).\n");
  // #1 MSETNX key3 value3 key4 value4
  reply = redisCommand(c, "MSETNX key3 value3 key4 value4");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. MSETNX key3 value3 key4 value4 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void append() {
  printf("---------------------------------------------------\n");
  printf("APPEND key value -> Integer reply: the length of the string after the append operation.\n");
  // #1 APPEND key value
  reply = redisCommand(c, "APPEND key value");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. APPEND key value -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 APPEND key Hello
  reply = redisCommand(c, "APPEND key Hello");
  printf("2. APPEND key Hello -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void strlen_redis() {
  printf("---------------------------------------------------\n");
  printf("STRLEN key -> Integer reply: the length of the string at key, or 0 when key does not exist.\n");
  // #1 STRLEN key
  reply = redisCommand(c, "STRLEN key");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. STRLEN key -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void setrange() {
  printf("---------------------------------------------------\n");
  printf("SETRANGE key offset value -> Integer reply: the length of the string after it was modified by the command.\n");
  redisCommand(c, "SET key %s", "This is MySQL Server");
  // #1 SETRANGE key 8 Redis
  reply = redisCommand(c, "SETRANGE key 8 Redis");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
      freeReplyObject(reply);
    return;
  } 
  printf("1. SETRANGE key 8 Redis -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "GET key");
  printf("2. GET key -> %s\n", reply->str);
  freeReplyObject(reply);
}

void getrange() {
  printf("---------------------------------------------------\n");
  printf("GETRANGE key start end -> Bulk string reply.\n");
  // #1 GETRANGE key 8 12
  reply = redisCommand(c, "GETRANGE key 8 12");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. GETRANGE key 8 12 -> %s\n", reply->str);
  freeReplyObject(reply);
}

void getset() {
  printf("---------------------------------------------------\n");
  printf("GETSET key value -> Bulk string reply: the old value stored at key, or nil when key did not exist.\n");
  // #1 GETSET key value
  reply = redisCommand(c, "GETSET key value");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. GETSET key value -> %s\n", reply->str);
  freeReplyObject(reply);
}

void setbit() {
  printf("---------------------------------------------------\n");
  printf("Bit operations\n");
  printf("SETBIT key offset value -> Integer reply: the original bit value stored at offset.\n");
  reply = redisCommand(c, "SET key A");
  // #1 SETBIT key 6 1
  reply = redisCommand(c, "SETBIT key 6 1");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. SETBIT key 6 1 -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "GET key");
  printf("2. GET key -> %s\n", reply->str);
  freeReplyObject(reply);
}

void getbit() {
  printf("---------------------------------------------------\n");
  printf("GETBIT key offset -> Integer reply: the bit value stored at offset.\n");
  // #1 GETBIT key 6
  reply = redisCommand(c, "GETBIT key 6");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. GETBIT key 6 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 GETBIT key 7
  reply = redisCommand(c, "GETBIT key 7");
  printf("2. GETBIT key 7 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void bitop() {
  printf("---------------------------------------------------\n");
  printf("BITOP operation destkey key [key ...] -> Integer reply:\n");
  printf("\tThe size of the string stored in the destination key, that is equal to the size of the longest input string.\n");
  redisCommand(c, "SET key1 A");
  redisCommand(c, "SET key2 B");
  // #1 BITOP AND destkey key1 key2
  reply = redisCommand(c, "BITOP AND destkey key1 key2");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. BITOP AND destkey key1 key2 -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "GET destkey");
  printf("2. GET destkey -> %s\n", reply->str);
  freeReplyObject(reply);
  // #3 BITOP OR destkey key1 key2
  reply = redisCommand(c, "BITOP OR destkey key1 key2");
  printf("3. BITOP OR destkey key1 key2 -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "GET destkey");
  printf("4. GET destkey -> %s\n", reply->str);
  freeReplyObject(reply);
  // #5 BITOP XOR destkey key1 key2
  reply = redisCommand(c, "BITOP XOR destkey key1 key2");
  printf("5. BITOP XOR destkey key1 key2 -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "GET destkey");
  printf("6. GET destkey -> %s\n", reply->str);
  freeReplyObject(reply);
  // #7 BITOP NOT destkey key1
  reply = redisCommand(c, "BITOP NOT destkey key1");
  printf("7. BITOP NOT destkey key1 -> %d\n", reply->integer);
  freeReplyObject(reply);
  reply = redisCommand(c, "GET destkey");
  printf("8. GET destkey -> %s\n", reply->str);
  freeReplyObject(reply);
  redisCommand(c, "DEL destkey");
}

void bitcount() {
  printf("---------------------------------------------------\n");
  printf("BITCOUNT key [start end] -> Integer reply: The number of bits set to 1.\n");
  redisCommand(c, "SET key ABC");
  // #1 BITCOUNT key
  reply = redisCommand(c, "BITCOUNT key");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
    freeReplyObject(reply);
    return;
  } 
  printf("1. BITCOUNT key -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 BITCOUNT key 1 2
  reply = redisCommand(c, "BITCOUNT key 1 2");
  printf("2. BITCOUNT key 1 2 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

void bitpos() {
  printf("---------------------------------------------------\n");
  printf("BITPOS key bit [start [end]] -> Integer reply.\n");
  redisCommand(c, "SET key ABC");
  // #1 BITPOS key 0
  reply = redisCommand(c, "BITPOS key 0");
  if (reply == NULL) {
    printf("redisCommand reply is NULL: %s\n", c->errstr);
    return;
  }
  if (reply->type == REDIS_REPLY_ERROR) {
    printf("Command Error: %s\n", reply->str);
      freeReplyObject(reply);
    return;
  } 
  printf("1. BITPOS key 0 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #2 BITPOS key 1
  reply = redisCommand(c, "BITPOS key 1");
  printf("2. BITPOS key 1 -> %d\n", reply->integer);
  freeReplyObject(reply);
  // #3 BITPOS key 1 2
  reply = redisCommand(c, "BITPOS key 1 2");
  printf("3. BITPOS key 1 2 -> %d\n", reply->integer);
  freeReplyObject(reply);
}

int main(){
   redisReply *reply;

   // Connecting
   redisContext *c = redisConnect("127.0.0.1", 6379);

   if (c == NULL || c->err) {
	  if (c) {
		 printf("Connecting Error: %s\n", c->errstr);
	  } else {
		 printf("Can't allocate redis context\n");
	  }
	  return -1;
   }
}

