typedef struct {
	BTNode* ptr;
	enum {0,1,2} mark;
}}PMType; //有mark 域的结点指针类型
vvoid PostOrder_Stack(BiTree T){
	//后续遍历二叉树的非递归算法,用栈
	PMType a;
	InitStack(S); 
	Push (S,{T,0}); 
	while(!StackEmpty(S)){
		Pop(S,a);
		switch(a.mark){
		case 0:
			Push(S,{a.ptr,1}); 
			if(a.ptr->lchild) Push(S,{a.ptr->lchild,0}); 
			break;
		case 1:
			Push(S,{a.ptr,2}); 
			if(a.ptr->rchild) Push(S,{a.ptr->rchild,0}); 
			break;
		case 2:
			visit(a.ptr); 
		}
	}
}}