int isPalindrome(){
	//�ж�������ַ����Ƿ��ǻ���
	//�ֱ��ַ�������ջ�Ͷ��У�Ȼ�����γ�ջ�Ͷ��У��ж���Ԫ���Ƿ����
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