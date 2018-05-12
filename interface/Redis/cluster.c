#include <hiredis/hiredis.h>

redisReply *reply;
redisContext *cc;

void clusterMeet() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER MEET ip port -> Simply string reply\n");
	int i;
	reply = redisCommand(cc, "CLUSTER MEET 127.0.0.1 7001");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER MEET 127.0.0.1 7001 -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clusterForget() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER FORGET -> Simple string reply.\n");
	reply = redisCommand(cc, "CLUSTER FORGET %s", nodeId);
	if (reply == NULL) {
   	printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
   	freeReplyObject(reply);
		return;
  } 
	printf("CLUSTER FORGET %s -> %s\n", nodeId, reply->str);
  freeReplyObject(reply);

	reply = redisCommand(cc, "CLUSTER FORGET %s", "XXXXXX");
	if (reply == NULL) {
  	printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
		return;
  } 
	printf("CLUSTER FORGET %s -> %s\n", "XXXXXX", reply->str);
  freeReplyObject(reply);
}

void clusterAddSlots() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER ADDSLOTS -> Simply string reply\n");
	reply = redisCommand(cc, "CLUSTER ADDSLOTS 0");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER ADDSLOTS 0 -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clusterDelSlots() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER DELSLOTS -> Simply string reply\n");
	int i;
	reply = redisCommand(cc, "CLUSTER DELSLOTS 0");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER DELSLOTS 0 -> %s\n", reply->str);
 	freeReplyObject(reply);
}

void clusterInfo() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER INFO -> Bulked string reply.\n");
	int i;
	reply = redisCommand(cc, "CLUSTER INFO");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER INFO -> \n%s\n", reply->str);
 	freeReplyObject(reply);
}

void clusterNodes() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER NODES -> Bulked string reply.\n");
	printf("\t返回构成集群的节点信息.\n");
	int i, j, lines=0;
	int exit=0;
	char *ptr, *next_ptr, *ptr2, *next_ptr2;
	reply = redisCommand(cc, "CLUSTER NODES");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("len %d %d\n", reply->len);
	printf("CLUSTER NODES -> \n%s\n", reply->str);
	for(i=0;i<reply->len;i++) {
		if (reply->str[i] == '\n') lines++;
	}
	i=1;
	j=1;
	printf("lines %d\n", lines);
	//获得用于下一个命令的第一个主节点ID
	ptr = strtok_r(reply->str, "\n", &next_ptr);
	printf( "%d. %s\n", i++, ptr); 
	ptr2 = strtok_r( ptr, " ", &next_ptr2);
	printf( "  %d) %s\n", j++, ptr2); 
	strcpy(nodeId, ptr2);
	while( ptr2 = strtok_r( NULL, " ", &next_ptr2)) {
		if (j==3 && !strcmp("master", ptr2) ) {
			exit = 1;	
			break;
		}
		printf( "  %d) %s\n", j++, ptr2); 
	}
	while( ptr = strtok_r( NULL, "\n", &next_ptr)) {
		printf( "%d. %s\n", i++, ptr); 
		j=1;	
		ptr2 = strtok_r( ptr, " ", &next_ptr2);
		printf( "  %d) %s\n", j++, ptr2); 
		if (exit==1) break;
		strcpy(nodeId, ptr2);
		while( ptr2 = strtok_r( NULL, " ", &next_ptr2)) {
			if (j==3 && !strcmp("master", ptr2) ) {
				exit = 1;	
				break;
			}
			printf( "  %d) %s\n", j++, ptr2); 
		}
	} 
 	freeReplyObject(reply);
}

void clusterReplicate() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER REPLICATE <node-id> -> Simple string reply.\n");
	reply = redisCommand(cc, "CLUSTER REPLICATE %s", "xxxx");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER REPLICATE %s -> %s\n", "xxxx", reply->str);
 	freeReplyObject(reply);
}

void clusterSlaves() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER SLAVES <master node-id> -> Array reply.\n");
	printf("\t返回主节点的从属信息.\n");
	int i;
	printf("master nodeId: %s\n", nodeId);
	reply = redisCommand(cc, "CLUSTER SLAVES %s", nodeId);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER SLAVES %s -> %d\n", nodeId, reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d) %s\n", i, reply->element[i]->str);
	}
 	freeReplyObject(reply);
}

void clusterKeyslot() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER KEYSLOT key -> Integer reply: slot number.\n");
	printf("\t无论秘钥是否存在，都返回槽号.\n");
	char *key="key";
	int i;
	for(i=0;i<10;i++) {
		reply = redisCommand(cc, "CLUSTER KEYSLOT %s%d", key, i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", cc->errstr);
			return;
		}	
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
		printf("CLUSTER KEYSLOT %s%d -> %d\n", key, i, reply->integer);
 		freeReplyObject(reply);
	}
}

void clusterCountKeysInSlot() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER COUNTKEYSINSLOT <slot number> -> Integer reply.\n");
	printf("\t返回插槽中的键数.\n");
	int i;
	for(i=0;i<10;i++) {
		reply = redisCommand(cc, "CLUSTER COUNTKEYSINSLOT %d", i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", cc->errstr);
			return;
		}	
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
		printf("CLUSTER COUNTKEYSINSLOT %d -> %d\n", i, reply->integer);
 		freeReplyObject(reply);
	}
}

void clusterGetKeysInSlot() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER GETKEYSINSLOT <slot number> count -> Array reply.\n");
	printf("\t返回插槽中的秘钥.\n");
	int i, j;
	for(i=0;i<10;i++) {
		reply = redisCommand(cc, "CLUSTER GETKEYSINSLOT %d 10", i);
		if (reply == NULL) {
 			printf("redisCommand reply is NULL: %s\n", cc->errstr);
			return;
		}	
		if (reply->type == REDIS_REPLY_ERROR) {
			printf("Command Error: %s\n", reply->str);
 			freeReplyObject(reply);
			return;
 		} 
		printf("%d) CLUSTER GETKEYSINSLOT %d 10 -> %d\n", i, reply->elements);
		for(j=0;j<reply->elements;j++) {
			printf("  %d) %s\n", j, reply->element[j]->str);
		}
 		freeReplyObject(reply);
	}
}

void clusterSetSlot() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER SETSLOT -> Simple string reply.\n");
	char node[] = "xxxxx";
	// #1 SETSLOT MIGRATING
	reply = redisCommand(cc, "CLUSTER SETSLOT 0 MIGRATING %s", node);
	printf("1. CLUSTER SETSLOT 0 MIGRATING %s -> ", node);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
 	} else {
		printf("%s\n", reply->str);
 		freeReplyObject(reply);
	}
	// #2 SETSLOT IMPORTING 
	reply = redisCommand(cc, "CLUSTER SETSLOT 0 IMPORTING %s", node);
	printf("2. CLUSTER SETSLOT 0 IMPORTING %s -> ", node);
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
  } else {
		printf("%s\n", reply->str);
  	freeReplyObject(reply);
	}
	// #3 SETSLOT STABLE 
	reply = redisCommand(cc, "CLUSTER SETSLOT 0 STABLE");
	printf("3. CLUSTER SETSLOT 0 STABLE -> ");
	if (reply == NULL) {
  	printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
  } else {
		printf("%s\n", reply->str);
  	freeReplyObject(reply);
	}
	// #4 SETSLOT NODE
	reply = redisCommand(cc, "CLUSTER SETSLOT 0 NODE %s", node);
	printf("4. CLUSTER SETSLOT 0 NODE %s -> ", node);
	if (reply == NULL) {
  	printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
  	freeReplyObject(reply);
  } else {
		printf("%s\n", reply->str);
  	freeReplyObject(reply);
	}
}

void clusterSlots() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER SLOTS -> 3 Nested Array reply.\n");
	printf("\t返回插槽范围和主节点信息.\n");
	int i, j, k;
	reply = redisCommand(cc, "CLUSTER SLOTS");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
		return;
 	} 
	printf("CLUSTER SLOTS -> %d\n", reply->elements);
	for(i=0;i<reply->elements;i++) {
		printf("%d)\n", i);
		for(j=0;j<reply->element[i]->elements;j++) {
			if (j<2) {
				printf("  %d) %d\n", j, reply->element[i]->element[j]->integer);
			} else if (j==2) {
				printf("  %d) master\n", j);
			} else {
				printf("  %d) clone(slave) %d\n", j, j-2);
			}
			for(k=0;k<reply->element[i]->element[j]->elements;k++) {
				if (k==1) {
					printf("    %d) %d\n", k, reply->element[i]->element[j]->element[k]->integer);
				} else {
					printf("    %d) %s\n", k, reply->element[i]->element[j]->element[k]->str);
				}
			}
		}
	}
 	freeReplyObject(reply);
}

void clusterFailover() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER FAILOVER -> Simple string reply.\n");
	// #1 FAILOVER
	reply = redisCommand(cc, "CLUSTER FAILOVER");
	printf("1. CLUSTER FAILOVER -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
 	} else {
		printf("%s\n", reply->str);
 		freeReplyObject(reply);
	}
	// #2 FAILOVER FORCE
	reply = redisCommand(cc, "CLUSTER FAILOVER FORCE");
	printf("2. CLUSTER FAILOVER FORCE -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
 	} else {
		printf("%s\n", reply->str);
 		freeReplyObject(reply);
	}
	// #3 FAILOVER TAKEOVER
	reply = redisCommand(cc, "CLUSTER FAILOVER TAKEOVER");
	printf("3. CLUSTER FAILOVER TAKEOVER -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 		freeReplyObject(reply);
 	} else {
		printf("%s\n", reply->str);
 		freeReplyObject(reply);
	}
}

void clusterCountFailureReports() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER COUNT-FAILURE-REPORTS -> integer reply.\n");
	// #1 COUNT-FAILURE-REPORTS
	reply = redisCommand(cc, "CLUSTER COUNT-FAILURE-REPORTS %s", nodeId);
	printf("1. CLUSTER COUNT-FAILURE-REPORTS -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 	} else {
		printf("%d\n", reply->integer);
	}
 	freeReplyObject(reply);
}

void clusterReset() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER RESET -> simple string reply.\n");
	// #1 CLUSTER RESET 
	reply = redisCommand(cc, "CLUSTER RESET");
	printf("1. CLUSTER RESET -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 	} else {
		printf("%s\n", reply->str);
	}
 	freeReplyObject(reply);
}

void clusterSaveConfig() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER SAVECONFIG -> simple string reply.\n");
	// #1 CLUSTER SAVECONFIG 
	reply = redisCommand(cc, "CLUSTER SAVECONFIG");
	printf("1. CLUSTER SAVECONFIG -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 	} else {
		printf("%s\n", reply->str);
	}
 	freeReplyObject(reply);
}

void clusterSetConfigEpoch() {
	printf("---------------------------------------------------\n");
	printf("CLUSTER SET-CONFIG-EPOCH -> simple string reply.\n");
	// #1 SET-CONFIG-EPOCH 
	reply = redisCommand(cc, "CLUSTER SET-CONFIG-EPOCH 0");
	printf("1. CLUSTER SET-CONFIG-EPOCH 0 -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 	} else {
		printf("%s\n", reply->str);
	}
 	freeReplyObject(reply);
}

void clusterReadOnly() {
	printf("---------------------------------------------------\n");
	printf("READONLY -> simple string reply.\n");
	// #1 READONLY
	reply = redisCommand(cc, "READONLY");
	printf("1. READONLY -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 	} else {
		printf("%s\n", reply->str);
	}
 	freeReplyObject(reply);
}

void clusterReadWrite() {
	printf("---------------------------------------------------\n");
	printf("READWRITE -> simple string reply.\n");
	// #1 READWRITE
	reply = redisCommand(cc, "READWRITE");
	printf("1. READWRITE -> ");
	if (reply == NULL) {
 		printf("redisCommand reply is NULL: %s\n", cc->errstr);
		return;
	}	
	if (reply->type == REDIS_REPLY_ERROR) {
		printf("Command Error: %s\n", reply->str);
 	} else {
		printf("%s\n", reply->str);
	}
 	freeReplyObject(reply);
}

int main(){
	return 0;
}
