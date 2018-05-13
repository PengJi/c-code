#include <hiredis/hiredis.h>

/**
 * INFO Sentinel
 * Sentinel Monitor
 * Sentinel Masters
 * Sentinel Master
 * Sentinel Slaves
 * Sentinel Sentinels
 * Sentinel Reset
 * Sentinel Failover
 * Sentinel Ckquorum
 * Sentinel Simulate-Failure
 * Sentinel FlushConfig
 * Sentinel Info-Cache
 * Sentinel Pending-Scripts
 * Sentinel Remove
 */

redisReply *reply;
redisContext *sc16000;
redisContext *sc16001;
redisContext *sc16002;

void infoSentinel() {
	printf("---------------------------------------------------\n");
	printf("INFO SENTINEL -> Bulk string reply: as a collection of text lines.\n");
	printf("\tLines can contain a section name (starting with a # character) or a property.\n");
	printf("\tAll the properties are in the form of field:value terminated by \\r\\n.\n");
	int i;
	reply = redisCommand(sc16000, "INFO sentinel");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("%s\n", reply->str);
 	freeReplyObject(reply);
}

void sentinelMonitor() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL MONITOR -> Simple string reply\n");
	int i;
	// 1. SENTINEL MONITOR 16000
	reply = redisCommand(sc16000, "SENTINEL MONITOR mymaster 127.0.0.1 6000 1");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("1. SENTINEL MONITOR mymaster 127.0.0.1 6000 1 -> %s\n", reply->str);
 	freeReplyObject(reply);
	// 2. SENTINEL MONITOR 16001
	reply = redisCommand(sc16001, "SENTINEL MONITOR mymaster 127.0.0.1 6000 1");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16001->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("2. SENTINEL MONITOR mymaster 127.0.0.1 6000 1 -> %s\n", reply->str);
 	freeReplyObject(reply);
	// 3. SENTINEL MONITOR 16002
	reply = redisCommand(sc16002, "SENTINEL MONITOR mymaster 127.0.0.1 6000 1");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16002->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("3. SENTINEL MONITOR mymaster 127.0.0.1 6000 1 -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void sentinelMasters() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL MASTERS -> Nested Array reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL MASTERS");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL MASTERS -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d)   ", i);
		for(j=0;j<reply->element[i]->elements;j++) {
			printf("\t%d) %s\n", j, reply->element[i]->element[j]->str);
		}
	}
 	freeReplyObject(reply);
}

void sentinelMaster() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL MASTER <master name> -> Array reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL MASTER mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL MASTERS mymaster -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void sentinelSlaves() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL SLAVES <master name> -> Nested Array reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL SLAVES mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL SLAVES mymaster -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d)   ", i);
		for(j=0;j<reply->element[i]->elements;j++) {
			printf("\t%d) %s\n", j, reply->element[i]->element[j]->str);
		}
	}
 	freeReplyObject(reply);
}

void sentinelSentinels() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL SENTINELS <master name> -> Nested Array reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL SENTINELS mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL SENTINELS mymaster -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d)   ", i);
		for(j=0;j<reply->element[i]->elements;j++) {
			printf("\t%d) %s\n", j, reply->element[i]->element[j]->str);
		}
	}
 	freeReplyObject(reply);
}

void sentinelReset() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL RESET [<master name>] -> Integer reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL RESET mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL RESET mymaster -> %d\n", reply->integer);
 	freeReplyObject(reply);
}

void sentinelFailover() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL FAILOVER <master name> -> Simple string reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL FAILOVER mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL FAILOVER mymaster -> %d\n", reply->str);
 	freeReplyObject(reply);
}

void sentinelCkquorum() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL CKQUORUM <master name> -> Bulk string reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL CKQUORUM mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL CKQUORUM mymaster -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void sentinelSimulateFailure() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL SIMULATE-FAILURE crash-after-election/crash-after-promotion -> Bulk string reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL SIMULATE-FAILURE crash-after-election");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL SIMULATE-FAILURE crash-after-election -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void sentinelFlushConfig() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL FLUSHCONFIG -> Simple string reply\n");
	int i, j;
	reply = redisCommand(sc16000, "SENTINEL FLUSHCONFIG");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL FLUSHCONFIG -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void sentinelInfoCache() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL INFO-CACHE <master name> -> 3 Nested Array reply\n");
	int i, j, k;
	reply = redisCommand(sc16000, "SENTINEL INFO-CACHE mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL INFO-CACHE mymaster -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
		for(j=0;j<reply->element[i]->elements;j++) {
			printf("  %d) %s\n", j, reply->element[i]->element[j]->str);
			for(k=0;k<reply->element[i]->element[j]->elements;k++) {
				if (k==0) {
					printf("    %d) %d\n", k, reply->element[i]->element[j]->element[k]->integer);
				} else {
					printf("    %d) %s\n", k, reply->element[i]->element[j]->element[k]->str);
				}
			}
		}
	}
 	freeReplyObject(reply);
}

void sentinelPendingScripts() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL PENDING-SCRIPTS -> 3 Nested Array reply\n");
	int i, j, k;
	reply = redisCommand(sc16000, "SENTINEL PENDING-SCRIPTS");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL PENDING-SCRIPTS -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
		for(j=0;j<reply->element[i]->elements;j++) {
			printf("  %d) %s\n", j, reply->element[i]->element[j]->str);
			for(k=0;k<reply->element[i]->element[j]->elements;k++) {
				printf("    %d) %s\n", k, reply->element[i]->element[j]->element[k]->str);
			}
		}
	}
 	freeReplyObject(reply);
}

void sentinelRemove() {
	printf("---------------------------------------------------\n");
	printf("SENTINEL REMOVE <master name> -> Simple string reply\n");
	int i;
	// #1 Sentinel remove 16000
	reply = redisCommand(sc16000, "SENTINEL REMOVE mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL REMOVE mymaster -> %s\n", reply->str);
 	freeReplyObject(reply);

	reply = redisCommand(sc16000, "SENTINEL REMOVE mymaster");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", sc16000->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("SENTINEL REMOVE mymaster -> %s\n", reply->str);
 	freeReplyObject(reply);
}

int main(){
	return 0;
}
