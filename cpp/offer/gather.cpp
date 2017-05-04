struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x),next(NULL){}
}
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
	
	//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        
    }

	
};



