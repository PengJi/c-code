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

};



