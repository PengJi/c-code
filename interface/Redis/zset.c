#include <hiredis/hiredis.h>

redisReply *reply;
redisContext *c;

void zadd() {
	printf("---------------------------------------------------\n");
	printf("ZADD key [NX|XX] [CH] [INCR] score member [score member ...] -> \e[5;32;1mInteger reply\e[m, specifically:\n");
	printf("\tThe number of elements added to the sorted sets, not including elements already existing for which the score was updated.\n");
	printf("\tIf the INCR option is specified, the return value will be \e[5;32;1mBulk string reply\e[m:\n");
	printf("\tthe new score of member (a double precision floating point number), represented as string.\n");
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	// #1 ZADD myzset
	reply = redisCommand(c, "ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	// #2 ZRANGE myzset
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	printf("2. ZRANGE myzset 0 -1 withscores -> %d\n", reply->elements);
	int i;
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
	/*
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
	*/
 	freeReplyObject(reply);
}

void zrem() {
	printf("---------------------------------------------------\n");
	printf("ZREM key member [member] -> Integer reply, specifically:\n");
	printf("\tThe number of members removed from the sorted set, not including non existing members.\n");
	// #1 ZREM myzset 
	reply = redisCommand(c, "ZREM myzset 测试");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREM myzset 测试 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	// #2 ZREM myzset
	reply = redisCommand(c, "ZREM myzset 测试1 测试2");
	printf("2. ZREM myzset 测试1 测试2 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	// #3 ZRANGE myzset
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	printf("3. ZRANGE myzset 0 -1 withscores -> %d\n", reply->elements);
	int i;
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void zrange() {
	printf("---------------------------------------------------\n");
	printf("ZRANGE key start stop [withscores] -> Array reply: list of elements in the specified range\n");
	printf("\t(optionally with their scores, in case the WITHSCORES option is given).\n");
	// #1 ZRANGE myzset
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("2. ZRANGE myzset 0 -1 withscores -> %d\n", reply->elements);
	int i;
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zcard() {
	printf("---------------------------------------------------\n");
	printf("ZCARD key -> Integer reply: the cardinality (number of elements) of the sorted set, or 0 if key does not exist.\n");
	// #1 ZCARD key
	reply = redisCommand(c, "ZCARD myzset");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZCARD myzset -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void zrangebyscore() {
	printf("---------------------------------------------------\n");
	printf("ZRANGEBYSCORE key min max [withscores] [limit offset count] -> Array reply:\n");
	printf("\tlist of elements in the specified score range (optionally with their scores).\n");
	reply = redisCommand(c, "ZADD myzset 60 경기 20 서울 40 부산 100 대전 80 전라");
	// #1 ZRANGEBYSCORE
	reply = redisCommand(c, "ZRANGEBYSCORE myzset -inf +inf withscores");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZRANGEBYSCORE myzset -inf +inf withscores -> %d\n", reply->elements);
	int i;
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
	// #2 ZRANGEBYSCORE including
	reply = redisCommand(c, "ZRANGEBYSCORE myzset 40 80 withscores");
	printf("2. ZRANGEBYSCORE myzset 40 80 withscores -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
	// #3 ZRANGEBYSCORE excluding
	reply = redisCommand(c, "ZRANGEBYSCORE myzset (40 (80 withscores");
	printf("3. ZRANGEBYSCORE myzset (40 (80 withscores -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zcount() {
	printf("---------------------------------------------------\n");
	printf("ZCOUNT key min max -> Integer reply: the number of elements in the specified score range.\n");
	// #1 ZCOUNT
	reply = redisCommand(c, "ZCOUNT myzset -inf +inf");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZCOUNT myzset -inf +inf -> %d\n", reply->integer);
 	freeReplyObject(reply);
	// #2 ZCOUNT including
	reply = redisCommand(c, "ZCOUNT myzset 40 80");
	printf("2. ZCOUNT myzset 40 80 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	// #3 ZCOUNT excluding
	reply = redisCommand(c, "ZCOUNT myzset (40 (80");
	printf("3. ZCOUNT myzset (40 (80 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void zrangebylex() {
	printf("---------------------------------------------------\n");
	printf("ZRANGEBYLEX key min max [limit offset count] -> Array reply: list of elements in the specified value range.\n");
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 0 测试1 0 测试2 0 测试3 0 测试4 0 测试5");
 	freeReplyObject(reply);
	int i;
	// #1 ZRANGEBYLEX
	reply = redisCommand(c, "ZRANGEBYLEX myzset 游戏 比赛");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	// 32 green, 31 red, 1m bold
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("ZRANGEBYLEX myset \e[5;31;1m游戏 比赛\e[m (Command Error): %s\n", reply->str);
 		freeReplyObject(reply);
		//return;
 	} else {
		printf("1. ZRANGEBYLEX myzset 游戏 比赛 -> %d\n", reply->elements);
		for(i=0;i<reply->elements;i++) {
			printf("%d) %s\n", i, reply->element[i]->str);
		}
 		freeReplyObject(reply);
	}
	// #2 ZRANGEBYLEX including
	reply = redisCommand(c, "ZRANGEBYLEX myzset [比赛 [游戏");
	printf("2. ZRANGEBYLEX myzset [比赛 [游戏 -> %d (including)\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
	// #3 ZRANGEBYLEX excluding
	reply = redisCommand(c, "ZRANGEBYLEX myzset (比赛 (游戏");
	printf("3. ZRANGEBYLEX myzset (比赛 (游戏 -> %d (excluding)\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void zlexcount() {
	printf("---------------------------------------------------\n");
	printf("ZLEXCOUNT key min max -> Integer reply: the number of elements in the specified score range.\n");
	// #1 ZLEXCOUNT including
	reply = redisCommand(c, "ZLEXCOUNT myzset [比赛 [游戏");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	// 32 green, 31 red, 1m bold
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("ZLEXCOUNT myset \e[5;31;1m[比赛 [游戏\e[m (Command Error): %s\n", reply->str);
 		freeReplyObject(reply);
		//return;
 	} else {
		printf("1. ZLEXCOUNT myzset [比赛 [游戏 -> %d (including)\n", reply->integer);
 		freeReplyObject(reply);
	}
	// #2 ZLEXCOUNT excluding
	reply = redisCommand(c, "ZLEXCOUNT myzset (比赛 (游戏");
	printf("2. ZLEXCOUNT myzset (比赛 (游戏 -> %d (excluding)\n", reply->integer);
 	freeReplyObject(reply);
}

void zremrangebyrank() {
	printf("---------------------------------------------------\n");
	printf("ZREMRANGEBYRANK key start stop -> Integer reply: the number of elements removed.\n");
	int i;
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1");
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
	// #1 ZREMRANGEBYRANK
	reply = redisCommand(c, "ZREMRANGEBYRANK myzset 1 3");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREMRANGEBYRANK myzset 1 3 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1");
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void zremrangebyscore() {
	printf("---------------------------------------------------\n");
	printf("ZREMRANGEBYSCORE key min max -> Integer reply: the number of elements removed.\n");
	int i;
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
	// #1 ZREMRANGEBYSCORE
	reply = redisCommand(c, "ZREMRANGEBYSCORE myzset 40 80");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREMRANGEBYSCORE myzset 40 80 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zremrangebylex() {
	printf("---------------------------------------------------\n");
	printf("ZREMRANGEBYLEX key min max -> Integer reply: the number of elements removed.\n");
	int i;
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 0 测试1 0 测试2 0 测试3 0 测试4 0 测试5");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
	// #1 ZREMRANGEBYLEX
	reply = redisCommand(c, "ZREMRANGEBYLEX myzset [测试1 [测试2");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREMRANGEBYLEX myzset [测试3 [测试4 -> %d\n", reply->integer);
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zrevrange() {
	printf("---------------------------------------------------\n");
	printf("ZREVRANGE key start stop [withscores] -> Array reply: list of elements in the specified range (optionally with their scores).\n");
	int i;
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5");
 	freeReplyObject(reply);
	// #1 ZREVRANGE
	reply = redisCommand(c, "ZREVRANGE myzset 0 -1 withscores");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREVRANGE myzset 0 -1 withscores -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zrevrangebyscore() {
	printf("---------------------------------------------------\n");
	printf("ZREVRANGEBYSCORE key max min [withscores] [limit offset count] -> Array reply:\n"); 
	printf("\tlist of elements in the specified score range (optionally with their scores).\n");
	int i;
	reply = redisCommand(c, "DEL myzset");
	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5");
	freeReplyObject(reply);
	// #1 ZREVRANGEBYSCORE
	reply = redisCommand(c, "ZREVRANGEBYSCORE myzset 80 40 withscores");
	if (reply == NULL) {
  	printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREVRANGEBYSCORE myzset 80 40 -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zrevrangebylex() {
	printf("---------------------------------------------------\n");
	printf("ZREVRANGEBYLEX key max min [limit offset count] -> Array reply: list of elements in the specified score range.\n"); 
	int i;
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 0 测试1 0 测试2 0 测试3 0 测试4 0 测试5");
 	freeReplyObject(reply);
	// #1 ZREVRANGEBYLEX
	reply = redisCommand(c, "ZREVRANGEBYLEX myzset [测试1 [测试2");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREVRANGEBYLEX myzset [测试1 [测试2 -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void zrank() {
	printf("---------------------------------------------------\n");
	printf("ZRANK key member -> If member exists in the sorted set, Integer reply: the rank of member.\n"); 
	printf("\tIf member does not exist in the sorted set or key does not exist, Bulk string reply: nil.\n");
	int i;
	reply = redisCommand(c, "ZRANGE myzset 0 -1");
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
	// #1 ZRANK
	reply = redisCommand(c, "ZRANK myzset 대전");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZRANK myzset 대전 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void zrevrank() {
	printf("---------------------------------------------------\n");
	printf("ZREVRANK key member -> If member exists in the sorted set, Integer reply: the rank of member.\n"); 
	printf("\tIf member does not exist in the sorted set or key does not exist, Bulk string reply: nil.\n");
	int i;
	// #1 ZREVRANK
	reply = redisCommand(c, "ZREVRANK myzset 测试1");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZREVRANK myzset 测试1 -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void zscore() {
	printf("---------------------------------------------------\n");
	printf("ZSCORE key member -> \e[5;32;1mBulk string reply\e[m:\n");
	printf("\tthe score of member (a double precision floating point number), represented as string.\n"); 
	int i;
	reply = redisCommand(c, "DEL myzset");
	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 60 测试1 20 测试2 40 测试3 100 测试4 80 测试5");
	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE myzset 0 -1 withscores");
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
  freeReplyObject(reply);
	// #1 ZSCORE
	reply = redisCommand(c, "ZSCORE myzset 대전");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZSCORE myzset 대전 -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void zincrby() {
	printf("---------------------------------------------------\n");
	printf("ZINCRBY key increment member -> \e[5;32;1mBulk string reply\e[m:\n");
	printf("\tthe new score of member (a double precision floating point number), represented as string.\n"); 
	int i;
	// #1 ZINCRBY
	reply = redisCommand(c, "ZINCRBY daily_views 1 today");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZINCRBY daily_views 1 today -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void zunionstore() {
	printf("---------------------------------------------------\n");
	printf("ZUNIONSTORE dest_key numkeys src_key [src_key ...] [WEIGHTS weight [weight ...]] [AGGREGATE SUM|MIN|MAX] -> \n");
	printf("\tInteger reply: the number of elements in the resulting sorted set at destination.\n"); 
	char *srcKey1 = "myzset1";
	char *srcKey2 = "myzset2";
	char *destKey = "dest_key";
	int i;
	reply = redisCommand(c, "DEL %s %s %s", srcKey1, srcKey2, destKey);
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD %s 1 A 2 B 3 C", srcKey1);
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD %s 4 B 5 C 6 D", srcKey2);
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE %s 0 -1 withscores", srcKey1);
	printf("ZRANGE %s 0 -1 withscores -> %d\n", srcKey1, reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZRANGE %s 0 -1 withscores", srcKey2);
	printf("ZRANGE %s 0 -1 withscores -> %d\n", srcKey2, reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
	// #1 ZUNIONSTORE
	reply = redisCommand(c, "ZUNIONSTORE %s 2 %s %s", destKey, srcKey1, srcKey2);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZUNIONSTORE %s 2 %s %s -> %d\n", destKey, srcKey1, srcKey2, reply->integer);
	reply = redisCommand(c, "ZRANGE %s 0 -1 withscores", destKey);
	printf("ZRANGE %s 0 -1 withscores -> %d\n", destKey, reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zinterstore() {
	printf("---------------------------------------------------\n");
	printf("ZINTERSTORE dest_key numkeys src_key [src_key ...] [WEIGHTS weight [weight ...]] [AGGREGATE SUM|MIN|MAX] ->\n");
	printf("\tInteger reply: the number of elements in the resulting sorted set at destination.\n"); 
	char *srcKey1 = "myzset1";
	char *srcKey2 = "myzset2";
	char *destKey = "dest_key";
	int i;
	// #1 ZINTERSTORE
	reply = redisCommand(c, "ZINTERSTORE %s 2 %s %s", destKey, srcKey1, srcKey2);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ZINTERSTORE %s 2 %s %s -> %d\n", destKey, srcKey1, srcKey2, reply->integer);
	reply = redisCommand(c, "ZRANGE %s 0 -1 withscores", destKey);
	printf("ZRANGE %s 0 -1 withscores -> %d\n", destKey, reply->elements);
	for(i=0;i<reply->elements;i++) {
		if(i%2 == 0) {
			printf("%d) %s ", i, reply->element[i]->str);
		} else {
			printf("%s\n", reply->element[i]->str);
		}
	}
 	freeReplyObject(reply);
}

void zscan() {
	printf("---------------------------------------------------\n");
	printf("ZSCAN key cursor [MATCH pattern] [COUNT count] -> array of elements contain two elements, a member and its.\n"); 
	int i;
	char ch[100] = "X_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	reply = redisCommand(c, "DEL myzset");
 	freeReplyObject(reply);
	for(i=65;i<91;i++) {
		ch[0] = i;
		reply = redisCommand(c, "ZADD myzset %d %s", i, ch);
 		freeReplyObject(reply);
	}
	// #1 ZSCAN myset cursor
	char cursor[10] = "0";	
	do {
		reply = redisCommand(c, "ZSCAN myzset %s",cursor);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", c->errstr);
			return;
		}
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
		}
		printf("ZSCAN myzset %s\n", cursor);
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
