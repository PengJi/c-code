struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x),next(NULL){}
}
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution{
public:
	//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
	int Numberof1(int n){
		int count = 0;
		while(n){
			n &= n-1;
			count++;
		}
		return count;
	}

	//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
	double Power(double base, int exponent){
		long p = abs(exponent);
		double r = 1.0;
		while(p){
			if(p & 1)
				r *= base;
			base *= base;
			p >>= 1;
		}
		return exponent<0?1/r:r;
	}

	// 反转链表
	//输入一个链表，反转链表后，输出链表的所有元素。
    ListNode* ReverseList(ListNode* pHead) {
		/*
        ListNode *pre = NULL;
        ListNode *p = NULL;
        pre = pHead;
        p = pHead->next;
        pre -> next = NULL;
        while(p != NULL){
        	pre = pHead;
            pHead = p;
            p = p->next;
            pHead -> next = pre;
        }
        
        return pHead;
		*/
		ListNode *pre = NULL;
        ListNode *next = NULL;
        while(pHead != NULL){
            next = pHead -> next;
            pHead -> next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
	
	// 合并两个排序的列表
	// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode *H = new ListNode(0);
        ListNode *cur = H;
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        while(p&&q){
            if(p -> val <= q -> val){
                cur -> next = p;
                cur = cur->next;
                p = p->next;
            }else{
                cur -> next = q;
                cur = cur->next;
                q = q->next;
            }
        }
        if(p != NULL)
            cur -> next = p;
        if(q != NULL){
            cur -> next = q;
        }
        return H->next; 
    }

	// 树的子结构
	// https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
    bool isSubtree(TreeNode* pRoota,TreeNode* pRootb){
        if(pRootb == NULL) return true;
        if(pRoota == NULL) return false;
        if(pRoota -> val == pRootb -> val){
            return isSubtree(pRoota->left,pRootb->left) && isSubtree(pRoota -> right,pRootb -> right);
        }else 
            return false;
    }
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        return isSubtree(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1 -> right,pRoot2);
    }

	// https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    //操作给定的二叉树，将其变换为源二叉树的镜像。 
	void Mirror(TreeNode *pRoot) {

    }
	
	// https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
    vector<int> printMatrix(vector<vector<int> > matrix) {

    }

	// https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
	void push(int value) {
        
    }
    void pop() {
        
    }
    int top() {
        
    }
    int min() {
        
    }

	// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
    }

	// 从上往下打印二叉树
	// https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
	vector<int> PrintFromTopToBottom(TreeNode* root) {

    }

	// 二叉搜索树的后序遍历序列
	// https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
    bool VerifySquenceOfBST(vector<int> sequence) {

    }

	// 二叉树中和为某一值的路径
	// https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

    }

	// 负责链表的复制
	// https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
    RandomListNode* Clone(RandomListNode* pHead)
    {
        
    }

	// 二叉搜索树与双向链表
	// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
	// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        
    }
};



