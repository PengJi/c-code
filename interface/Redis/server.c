#include <hiredis/hiredis.h>

/**
 * https://redis.io/commands#server
 * 
 * INFO
 * DBSIZE
 * FLUSHDB
 * FLUSHALL
 * CLIENT SETNAME
 * CLIENT GETNAME
 * CLIENT LIST
 * CLIENT REPLY
 * CLIENT PAUSE
 * CLIENT KILL
 * BGREWRITEAOF
 * BGSAVE
 * SAVE
 * LASTSAVE
 * SLAVEOF
 * ROLE
 * CONFIG RESETSTAT
 * CONFIG GET
 * CONFIG SET
 * CONFIG REWRITE
 * DUBUG
 * LATENCY
 * SLOWLOG
 * MEMORY
 * MONITOR
 */

redisReply *reply;
redisContext *c;

redisReply *reply;

void time2str(int time, char *res) {
	time_t t = time;
	char format[] = "%Y.%m.%d %H:%M:%S";
	struct tm lt;

	(void) localtime_r(&t, <);
	if (strftime(res, 64, format, <) == 0) {
		(void) fprintf(stderr,  "strftime(3): cannot format supplied date/time into buffer of size %u using: '%s'\n", sizeof(res), format);
		return;
	}
}

void info() {
	printf("---------------------------------------------------\n");
	printf("INFO [section/all/default] -> Bulk string reply: as a collection of text lines.\n");
	printf("\tLines can contain a section name (starting with a # character) or a property.\n");
	printf("\tAll the properties are in the form of field:value terminated by \\r\\n.\n");
	printf("\tall: Return all sections\n");
	printf("\tdefault: Return only the default set of sections\n");
	// #1 INFO
	reply = redisCommand(c, "INFO all");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
   	} 
	printf("1. INFO all -> \n%s\n", reply->str);
 	freeReplyObject(reply);
}

void dbsize() {
	printf("---------------------------------------------------\n");
	printf("DBSIZE -> Integer reply:\n");
	printf("\tReturn the number of keys in the currently-selected database.\n");
	// #1 DBSIZE
	reply = redisCommand(c, "DBSIZE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. DBSIZE -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void flushdb() {
	printf("---------------------------------------------------\n");
	printf("FLUSHDB ASYNC(Redis 4.0.0 or greater) -> Simple string reply\n");
	printf("\tDelete all the keys of the currently selected DB.\n");
	printf("\tThis command never fails.\n");
	// #1 FLUSHDB
	reply = redisCommand(c, "FLUSHDB");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. FLUSHDB -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void flushall() {
	printf("---------------------------------------------------\n");
	printf("FLUSHALL ASYNC(Redis 4.0.0 or greater) -> Simple string reply\n");
	printf("\tDelete all the keys of all the existing databases, not just the currently selected one.\n");
	printf("\tThis command never fails.\n");
	// #1 FLUSHALL
	reply = redisCommand(c, "FLUSHALL");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. FLUSHALL -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clientSetName() {
	printf("---------------------------------------------------\n");
	printf("CLIENT SETNAME connection-name -> Simple string reply:\n");
	printf("\tOK if the connection name was successfully set.\n");
	// #1 CLIENT SETNAME
	reply = redisCommand(c, "CLIENT SETNAME redisGate");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CLIENT SETNAME redisGate -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clientGetName() {
	printf("---------------------------------------------------\n");
	printf("CLIENT GETNAME -> Bulk string reply:\n");
	printf("\tThe connection name, or a null bulk reply if no name is set.\n");
	// #1 CLIENT GETNAME
	reply = redisCommand(c, "CLIENT GETNAME");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CLIENT GETNAME -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clientList() {
	printf("---------------------------------------------------\n");
	printf("CLIENT LIST -> Bulk string reply: a unique string, formatted as follows:\n");
	printf("\tOne client connection per line (separated by LF)\n");
	printf("\tEach line is composed of a succession of property=value fields separated by a space character.\n");
	// #1 CLIENT LIST
	reply = redisCommand(c, "CLIENT LIST");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CLIENT LIST -> \n%s\n", reply->str);
 	freeReplyObject(reply);
}

void clientReply() {
	printf("---------------------------------------------------\n");
	printf("CLIENT REPLY ON|OFF|SKIP -> Simple string reply: OK.\n");
	printf("\tWhen called with either OFF or SKIP subcommands, no reply is made.\n");
	printf("\tWhen called with ON.\n");
	// #1 CLIENT REPLY
	reply = redisCommand(c, "CLIENT REPLY ON");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CLIENT REPLY ON -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clientPause() {
	printf("---------------------------------------------------\n");
	printf("CLIENT PAUSE timeout(ms) -> Simple string reply:\n");
	printf("\tThe command returns OK or an error if the timeout is invalid.\n");
	// #1 CLIENT PAUSE
	reply = redisCommand(c, "CLIENT PAUSE 10000");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CLIENT PAUSE 10000 -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clientKill() {
	printf("---------------------------------------------------\n");
	printf("CLIENT KILL [ip:port] -> Simple string reply: OK if the connection exists and has been closed\n");
	printf("\t[ID client-id] [TYPE normal|master|slave|pubsub] [ADDR ip:port] [SKIPME yes/no]\n");
	printf("\t-> Integer reply: the number of clients killed.\n");
	// #1 CLIENT KILL ip:port
	reply = redisCommand(c, "CLIENT KILL 127.0.0.1:5000");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		// return;
 	} else {
		printf("1. CLIENT KILL 127.0.0.1:5000 -> %s\n", reply->str);
 		freeReplyObject(reply);
	}
	// #2 CLIENT KILL ID redisGateX
	reply = redisCommand(c, "CLIENT KILL ID redisGateX");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		// return;
 	} else {
		printf("2. CLIENT KILL ID redisGateX -> %d\n", reply->integer);
 		freeReplyObject(reply);
	}
}

void bgrewriteaof() {
	printf("---------------------------------------------------\n");
	printf("BGREWRITEAOF -> Bulk string reply.\n");
	// #1 BGREWRITEAOF 
	reply = redisCommand(c, "BGREWRITEAOF");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. BGREWRITEAOF -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void bgsave() {
	printf("---------------------------------------------------\n");
	printf("BGSAVE -> Bulk string reply.\n");
	// #1 BGSAVE
	reply = redisCommand(c, "BGSAVE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. BGSAVE -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void save() {
	printf("---------------------------------------------------\n");
	printf("SAVE -> Simple string reply: The commands returns OK on success.\n");
	// #1 SAVE
	reply = redisCommand(c, "SAVE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. SAVE -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void lastsave() {
	printf("---------------------------------------------------\n");
	printf("LASTSAVE -> Integer reply: an UNIX time stamp.\n");
	// #1 LASTSAVE
	reply = redisCommand(c, "LASTSAVE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	time2str(reply->integer, res);
	printf("1. LASTSAVE -> %d (%s)\n", reply->integer, res);
 	freeReplyObject(reply);
}

void slaveof() {
	printf("---------------------------------------------------\n");
	printf("SLAVEOF ip port -> Simple string reply.\n");
	printf("SLAVEOF NO ONE -> Simple string reply.\n");
	// #1 SLAVEOF ip port
	reply = redisCommand(c, "SLAVEOF 127.0.0.1 5000");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. SLAVEOF 127.0.0.1 5000 -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #2 SLAVEOF NO ONE
	reply = redisCommand(c, "SLAVEOF NO ONE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("2. SLAVEOF NO ONE -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void role() {
	printf("---------------------------------------------------\n");
	printf("ROLE -> Array reply.\n");
	// #1 ROLE
	reply = redisCommand(c, "ROLE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. ROLE -> %s\n", reply->element[0]->str);
 	freeReplyObject(reply);
}

void configResetStat() {
	printf("---------------------------------------------------\n");
	printf("CONFIG RESETSTAT -> Simple string reply: always OK.\n");
	// #1 CONFIG RESETSTAT
	reply = redisCommand(c, "CONFIG RESETSTAT");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CONFIG RESETSTAT -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void configGet() {
	printf("---------------------------------------------------\n");
	printf("CONFIG GET parameter -> Array reply.\n");
	int i;
	// #1 CONFIG GET
	reply = redisCommand(c, "CONFIG GET *");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CONFIG GET * -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
	// #2 CONFIG GET
	reply = redisCommand(c, "CONFIG GET slave-priority");
	printf("2. CONFIG GET slave-priority -> %s %s\n", reply->element[0]->str, reply->element[1]->str);
	strcpy(name, reply->element[0]->str);
	strcpy(value, reply->element[1]->str);
 	freeReplyObject(reply);
}

void configSet() {
	printf("---------------------------------------------------\n");
	printf("CONFIG SET parameter value -> Simple string reply:\n");
	printf("\tOK when the configuration was set properly.\n");
	printf("\tOtherwise an error is returned.\n");
	int i;
	// #1 CONFIG SET
	reply = redisCommand(c, "CONFIG SET %s %s", name, value);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CONFIG SET %s %s -> %s\n", name, value, reply->str);
 	freeReplyObject(reply);
	// #2 CONFIG SET
	reply = redisCommand(c, "CONFIG SET %s %d", "latency-monitor-threshold", 1);
	printf("2. CONFIG SET %s %d -> %s\n", "latency-monitor-threshold", 1, reply->str);
 	freeReplyObject(reply);
	// #3 CONFIG SET
	reply = redisCommand(c, "CONFIG SET %s %d", "slowlog-log-slower-than", 0);
	printf("3. CONFIG SET %s %d -> %s\n", "slowlog-log-slower-than", 0, reply->str);
 	freeReplyObject(reply);
}

void configRewrite() {
	printf("---------------------------------------------------\n");
	printf("CONFIG REWRITE -> Simple string reply:\n");
	printf("\tOK when the configuration was rewritten properly.\n");
	printf("\tOtherwise an error is returned.\n");
	int i;
	// #1 CONFIG REWRITE
	reply = redisCommand(c, "CONFIG REWRITE");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. CONFIG REWRITE -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void debug() {
	printf("---------------------------------------------------\n");
	printf("DEBUG subcommand -> subcommand에 따라 리턴값이 다르다.\n");
	int i;
	// #1 DEBUG subcommand
	reply = redisCommand(c, "DEBUG help");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. DEBUG help -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
	// #2 DEBUG sleep 5
	printf("\nDEBUG sleep 5\n");
	reply = redisCommand(c, "DEBUG sleep 5");
	printf("2. DEBUG sleep 5 -> %s\n", reply->str);
 	freeReplyObject(reply);
	// #3 DEBUG structsize
	reply = redisCommand(c, "DEBUG structsize");
	printf("3. DEBUG structsize -> %s\n", reply->str);
 	freeReplyObject(reply);

	reply = redisCommand(c, "SET key value");
 	freeReplyObject(reply);
	reply = redisCommand(c, "LPUSH mylist value1 value2");
 	freeReplyObject(reply);
	reply = redisCommand(c, "SADD myset value1 value2");
 	freeReplyObject(reply);
	reply = redisCommand(c, "ZADD myzset 10 value1 20 value2");
 	freeReplyObject(reply);
	reply = redisCommand(c, "HSET myhash field1 value1 field2 value2");
 	freeReplyObject(reply);
	reply = redisCommand(c, "EXPIRE myhash 10");
 	freeReplyObject(reply);
	reply = redisCommand(c, "EXPIRE myzset 10");
 	freeReplyObject(reply);

	// #4 DEBUG HTSTATS
	reply = redisCommand(c, "DEBUG HTSTATS 0");
	printf("4. DEBUG HTSTATS 0 -> \n%s\n", reply->str);
 	freeReplyObject(reply);
}

void latency() {
	printf("---------------------------------------------------\n");
	printf("LATENCY Subcommand -> subcommand에 따라 리턴값이 다르다.\n");
	printf("\tLATEST: 2 Nested Array reply.\n");
	printf("\tHISTORY: 2 Nested Array reply.\n");
	printf("\tGRAPH: Buld string reply.\n");
	printf("\tDOCTOR: Buld string reply.\n");
	printf("\tRESET: integer reply.\n");
	int i, j;
	// #1 LATENCY latest
	reply = redisCommand(c, "LATENCY latest");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. LATENCY latest -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) \n", i, reply->element[i]->elements);
		for(j=0;j<reply->element[i]->elements;j++) {
			if (j==0) {
				printf("  %d) %s\n", j, reply->element[i]->element[j]->str);
			} if (j==1) {
				time2str(reply->element[i]->element[j]->integer, res);
				printf("  %d) %d (%s)\n", j, reply->element[i]->element[j]->integer, res);
			} else {
				printf("  %d) %d \n", j, reply->element[i]->element[j]->integer);
			}
		}
	}
 	freeReplyObject(reply);
	// #2 LATENCY history
	reply = redisCommand(c, "LATENCY history command");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("2. LATENCY history command -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) \n", i, reply->element[i]->elements);
		for(j=0;j<reply->element[i]->elements;j++) {
			if (j==0) {
				time2str(reply->element[i]->element[j]->integer, res);
				printf("  %d) %d (%s)\n", j, reply->element[i]->element[j]->integer, res);
			} else {
				printf("  %d) %d\n", j, reply->element[i]->element[j]->integer);
			}
		}
	}
 	freeReplyObject(reply);
	// #3 LATENCY graph
	reply = redisCommand(c, "LATENCY graph command");
	if (reply == NULL) {
  	printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
		return;
  } 
	printf("3. LATENCY graph command -> %s\n", reply->str);
  freeReplyObject(reply);
	// #4 LATENCY doctor
	reply = redisCommand(c, "LATENCY doctor");
	if (reply == NULL) {
  	printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
		return;
  } 
	printf("4. LATENCY doctor -> %s\n", reply->str);
  freeReplyObject(reply);
	// #5 LATENCY reset
	reply = redisCommand(c, "LATENCY reset");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("5. LATENCY reset -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void slowlog() {
	printf("---------------------------------------------------\n");
	printf("SLOWLOG Subcommand(GET/LEN/RESET) -> subcommand에 따라 리턴값이 다르다.\n");
	printf("\tGET: 3 Nested Array reply.\n");
	printf("\tLEN: Integer reply.\n");
	printf("\tRESET: Simple string reply.\n");
	int i, j, k;
	// #1 SLOWLOG get
	reply = redisCommand(c, "SLOWLOG get");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. SLOWLOG get -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) \n", i, reply->element[i]->elements);
		for(j=0;j<reply->element[i]->elements;j++) {
			if (j==0) {
				printf("  %d) %d\n", j, reply->element[i]->element[j]->integer);
			} else if (j==1) {
				time2str(reply->element[i]->element[j]->integer, res);
				printf("  %d) %d (%s)\n", j, reply->element[i]->element[j]->integer, res);
			} else if (j==2) {
				printf("  %d) %dus\n", j, reply->element[i]->element[j]->integer);
			} else if (j==3) {
				for(k=0;k<reply->element[i]->element[j]->elements;k++) {
					printf("    %d) %s\n", k, reply->element[i]->element[j]->element[k]->str);
				}
			} else {
				printf("  %d) %s\n", j, reply->element[i]->element[j]->str);
			}
		}
	}
 	freeReplyObject(reply);
	// #2 SLOWLOG len
	reply = redisCommand(c, "SLOWLOG len");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("2. SLOWLOG len -> %d\n", reply->integer);
 	freeReplyObject(reply);
	// #3 SLOWLOG reset
	reply = redisCommand(c, "SLOWLOG reset");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("3. SLOWLOG reset -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void memory() {
	printf("---------------------------------------------------\n");
	printf("MEMORY Subcommand -> subcommand에 따라 리턴값이 다르다.\n");
	printf("\thelp -> Array reply.\n");
	printf("\tusage -> Integer reply.\n");
	printf("\tstats -> Array reply.\n");
	printf("\tdoctor -> Bulk string reply.\n");
	printf("\tmalloc-stats -> Bulk string reply.\n");
	printf("\tpurge -> Simple string reply.\n");
	int i, j, k;
	// #1 MEMORY help
	reply = redisCommand(c, "MEMORY help");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. MEMORY help -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("\t%d) %s\n", i, reply->element[i]->str);
	}
	freeReplyObject(reply);
	// #2 MEMORY usage key
	reply = redisCommand(c, "MEMORY usage key");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("2. MEMORY usage key -> %d\n", reply->integer);
	freeReplyObject(reply);
	// #3 MEMORY stats
	reply = redisCommand(c, "MEMORY stats");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("3. MEMORY stats -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		if (i%2 == 0) {
			printf("\t%d) %s -> ", i, reply->element[i]->str);
		} else {
			if (reply->element[i]->str == NULL) {
				printf("%d\n", reply->element[i]->integer);
			} else {
				printf("%s\n", reply->element[i]->str);
			}
		}
	}
	freeReplyObject(reply);
	// #4 MEMORY doctor 
	reply = redisCommand(c, "MEMORY doctor");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("4. MEMORY doctor -> %s\n", reply->str);
	freeReplyObject(reply);
	// #5 MEMORY malloc-stats
	reply = redisCommand(c, "MEMORY malloc-stats");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("5. MEMORY malloc-stats -> \n%s\n", reply->str);
	freeReplyObject(reply);
	// #6 MEMORY purge 
	reply = redisCommand(c, "MEMORY purge");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("6. MEMORY purge -> %s\n", reply->str);
	freeReplyObject(reply);
}

void monitor() {
	printf("---------------------------------------------------\n");
	printf("MONITOR\n");
	int i, j, k;
	// #1 MONITOR
	reply = redisCommand(c, "MONITOR");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", c->errstr);
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. MONITOR -> %s\n", reply->str);
	while(redisGetReply(c,(void**) &reply) == REDIS_OK) {
		printf("%s\n", reply->str);
		freeReplyObject(reply);
	}
}

int main(){
	return 0
}
