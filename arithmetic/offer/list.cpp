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
     * 从尾到头打印链表   
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
     * 链表中，倒数第k个结点
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

    /*
     * 反转链表
     * 输入一个链表，反转链表后，输出链表的所有元素
     */
    ListNode* ReverseList(ListNode* pHead) {
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

    /*
     * 合并两个排序链表
     * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
     */
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

    /*
     * 复杂链表的复制
     * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
     * 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
     * 1. 利用递归
     */
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
         
        //开辟一个新节点
        RandomListNode* pClonedHead=new RandomListNode(pHead->label);
        pClonedHead->next = pHead->next;
        pClonedHead->random = pHead->random;
         
        //递归其他节点
        pClonedHead->next=Clone(pHead->next);
         
        return pClonedHead;
    }

    /*
     * 二叉搜索树与双向链表
     * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
     * 1. 递归
     */
    TreeNode *pre=NULL;
    TreeNode *lastLeft=NULL;
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if(pRootOfTree==NULL){
            return NULL;
        }
        Convert(pRootOfTree->left);
        pRootOfTree->left=pre;
        if(pre!=NULL)
            pre->right=pRootOfTree;
        pre=pRootOfTree;
        lastLeft=lastLeft==NULL?pRootOfTree:lastLeft;
        Convert(pRootOfTree->right);
        return lastLeft; 
    }

    /*
     * 双链表的第一个公共结点
     * 输入两个链表，找出它们的第一个公共结点
     */
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = getLen(pHead1);
        int len2 = getLen(pHead2);
        int step;
        if(len1>len2){
            step = len1-len2;
            pHead1 = walk(pHead1,step);
        }else{
            step = len2-len1;
            pHead2 = walk(pHead2,step);
        }
        
        while(pHead1 != NULL){
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
    
    int getLen(ListNode* LN){
        if(LN == NULL) return 0;
        int m = 0;
        while(LN!=NULL){
            m++;
            LN=LN->next;
        }
        return m;
    }
    
    ListNode *walk(ListNode* LN,int step){
        while(step--){
            LN = LN->next;
        }
        return LN;
    }

    /*
     * 链表中环的入口结点
     * 一个链表包含还，请找出该链表的环的入口结点
     * 1. 两个指针fast和slow，fast以slow两倍速度前进，如果没有环，那么fast和slow不会相遇此时返回null；
     * 如果有环，那fast和slow肯定会再次相遇，相遇的时候，fast刚好比slow多走了一圈环的长度。
     * 用图来描述下，当fast与slow相遇时，fast走过的距离为a + b + c + b，而slow走过的距离为 a + b，因为fast是slow速度的两倍，
     * 则有a+b+c+b = 2*(a+b)，登出a=c;此时slow节点所处X处到环起点Y处的距离a和X节点到Y处距离c其实是相等的，此时第三个指针p从x处，
     * 以和slow指针相同的速度前进，当它两相遇时，即为环的起点Y处！
     */
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *p = pHead;
                while(p!=slow){
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return NULL;
    }

    /*
     * 删除链表中重复的结点
     * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
     * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
     */
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next==NULL) return pHead;
        ListNode *HeadNode = new ListNode(-1);
        HeadNode ->next = pHead;
        ListNode *pveNode = HeadNode;
        ListNode *p = HeadNode->next;
        ListNode *nextNode = p->next;
        while(p!=NULL && p->next!=NULL){
            if(p->val == nextNode->val){
                while(nextNode->next != NULL && nextNode->val == nextNode->next->val){
                    nextNode = nextNode->next;
                }
                p=nextNode->next;
                nextNode = p->next;
                pveNode->next = p;
            }else{
                pveNode = p;
                p=nextNode;
                nextNode = nextNode->next;
            }
        }
        return HeadNode->next;
    }
}

