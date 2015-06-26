int isPalindrome(){
	//判断输入的字符串是否是回文
	//分别将字符串存入栈和队列，然后依次出栈和队列，判断两元素是否相等
	InitStack(S);
	InitQueue(Q);
	char a,b,c;
	while((c.getchar())!='@'){
		push(S,c);
		enQueue(Q,c);
	}
	while(!StackEmpty(S)){
		pop(S,a);
		deQueue(Q,b);
		if(a!=b)
			return 0;
	}
	return 1;
}