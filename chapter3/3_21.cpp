char *RPExpression(char *e){
	//����׺���ʽת��Ϊ��׺���ʽ
	//����Ϊ�������׺���ʽ����������ջ���ֱ��Ų��������沨��ʽ
	Stack s1,s2;
	InitStack(s1);//��Ų�����
	InitStack(s2);//����沨��ʽ
	Push(s1,'#');
	
	char *p=e,ch;
	int length=0;//���ʽ����
	for(*p!='\0';p++){
		switch(*p){
		//��"("��ֱ����ջ
		case '(':
			push(s1,*p);
			break;
		//��")"�򽫾���s1ջ���������"("֮���������������ջ����������ջs2��������"("
		case ')':
			while(GetTop(s1)!='('){
				pop(s1,ch);
				push(s2,ch);
			}
			pop(s1,ch);
			break;
		//����ǰջs1��ջ��Ԫ����'('����ǰ�����ֱ��ѹ��ջs1
		//���򣬽���ǰ�������ջs1��ջ��Ԫ�رȽϣ������ȼ���ջ��Ԫ�ش���ֱ��ѹ��ջs1��
		//  ����s1ջ��Ԫ�ص�������ѹ��ջs2�У�ֱ��ջ������������ȼ�����ڵ�ǰ�������Ȼ���ٽ���ǰ�����ѹ��ջs1��
		case '+':
		case '-':
			for(ch=GetTop(s1);ch!='#';ch=GetTop(s1)){
				if(ch=='('){
					break;
				}else{
					pop(s1,ch);
					push(s2,ch);
				}
			}
			push(s1,*p);
			length++;
			break;
		case '*':
		case '/':
			for(ch=GetTop(s1);ch!='#'&&ch!='+'&&ch!='-';ch=GetTop(s1)){
				if(ch=='('){
					break;
				}else{
					pop(s1,ch);
					push(s2,ch);
				}
			}
			push(s1,*p);
			length++;
			break;
		//����������ֱ��ѹ��ջs2��
		default:
			push(s2,*p);
			length++;
		}
	}
	//��ջs1�ǿգ���ջ��Ԫ�����ε�����ѹ��ջs2��
	while(!StackEmpty(s1)&&GetTop(s1)!='#'){
		pop(s1,ch);
		push(s2,ch);
	}
	//���ջs2������������г��ַ���;
	char *result;
	result=(char *) malloc(sizeof(char)*(length+1));
	result+=length;
	*result='\0';
	result--;
	for(;!StackEmpty(s2);result--){
		pop(s2,ch);
		*result=ch;
	}
	++result;
	return result;
}