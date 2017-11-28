char *RPExpression(char *e){
	//将中缀表达式转化为后缀表达式
	//参数为传入的中缀表达式，设置两个栈，分别存放操作符和逆波兰式
	Stack s1,s2;
	InitStack(s1);//存放操作符
	InitStack(s2);//存放逆波兰式
	Push(s1,'#');
	
	char *p=e,ch;
	int length=0;//表达式长度
	for(*p!='\0';p++){
		switch(*p){
		//遇"("则直接入栈
		case '(':
			push(s1,*p);
			break;
		//遇")"则将距离s1栈顶的最近的"("之间的运算符，逐个出栈，依次送入栈s2，并放弃"("
		case ')':
			while(GetTop(s1)!='('){
				pop(s1,ch);
				push(s2,ch);
			}
			pop(s1,ch);
			break;
		//若当前栈s1的栈顶元素是'('，则当前运算符直接压入栈s1
		//否则，将当前运算符与栈s1的栈顶元素比较，若优先级较栈顶元素大，则直接压入栈s1中
		//  否则将s1栈顶元素弹出，并压入栈s2中，直到栈顶运算符的优先级别低于当前运算符，然后再将当前运算符压入栈s1中
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
		//遇操作数则直接压入栈s2中
		default:
			push(s2,*p);
			length++;
		}
	}
	//若栈s1非空，则将栈中元素依次弹出并压入栈s2中
	while(!StackEmpty(s1)&&GetTop(s1)!='#'){
		pop(s1,ch);
		push(s2,ch);
	}
	//最后将栈s2输出，逆序排列成字符串;
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