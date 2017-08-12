#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		}
};

class Solution{
public:

	/*
	 * 输入一个链表，从尾到头打印链表每个节点的值。
	 * 1. 用库函数，每次扫描一个节点，将该结点数据存入vector中，如果该节点有下一节点，将下一节点数据直接插入vector最前面，直至遍历完
	 * 2. 直接加在最后，最后调用reverse
	 * 3. 反转链表，然后输出
	 */
	vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        if(head != NULL)
        {
            value.insert(value.begin(),head->val);
            while(head->next != NULL)
            {
                value.insert(value.begin(),head->next->val);
                head = head->next;
            }         
             
        }
        return value;
    }

	/*
	 * 输入一个链表，输出该链表中倒数第k个结点。
	 */
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	ListNode *pre = NULL,*p = NULL;
        p = pListHead;
        pre = pListHead;
        int a;
        int count = 0;
        while(p != NULL){
            p = p->next;
            count++;
        }
        a = count - k;
        if(a==0) return pre;
        if(a<0) return NULL;
        while(a-->0){
            pre = pre -> next;
        }
        return pre;
    }



}

