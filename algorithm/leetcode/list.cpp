/**
 * 线性表
 * 链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	/*
	 * 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
	 */
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	    ListNode preHead(0), *p = &preHead;
	    int extra = 0;
	    while (l1 || l2 || extra) {
	        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
	        extra = sum / 10;
	        p->next = new ListNode(sum % 10);
	        p = p->next;
	        l1 = l1 ? l1->next : l1;
	        l2 = l2 ? l2->next : l2;
	    }
	    return preHead.next;
	}

    /**
     * 19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
     */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    //设两个指针p,q，让q先走n步，然后p和q一起走，知道q走到尾节点，删除p->next即可。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q=&dummy;

        for(int i=0; i<n; i++)
            q=q->next;

        while(q->next){
            p = p->next;
            q = q->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }

	/*
	 * 21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-merge-two-sorted-lists.html
	 */
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(-1);
        ListNode *t3 = l3; 

        while(l1 && l2){
        	if(l1->val <= l2->val){
        		t3->next = l1;
        		l1 = l1->next;
        	}else{
        		t3->next = l2;
        		l2 = l2->next;
        	}

        	t3 = t3->next;
        }

        t3->next = l1?l1:l2;
        ListNode *tmp = l3;
        l3 = l3->next;
        delete tmp;

        return l3;
    }

    /**
     * 24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
     */
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode *prev = &dummy, *cur = prev->next, *next=cur->next; next; 
            prev = cur,cur=cur->next, next=cur?cur->next:nullptr){
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }

        return dummy.next;
    }
    ListNode *swapPairs(ListNode *head){
        ListNode *p = head;

        while(p && p->next){
            swap(p->val, p->next->val);
            p = p->next->next;
        }

        return head;
    }

    /**
     * 25. Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
     */
    //递归
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k<2)
            return head;

        ListNode *next_group = head;
        for(int i=0; i<k; ++i){
            if(next_group)
                next_group = next_group->next;
            else 
                return head;
        }

        //next_group is the head of next group
        //new_next_group is the new head of next group after reversion
        ListNode *new_next_group = reverseKGroup(next_group, k);
        ListNode *prev = NULL, *cur = head;
        while(cur != next_group){
            ListNode *next = cur->next;
            cur->next = prev? prev:new_next_group;
            prev = cur;
            cur = next;
        }
        return prev; //prev will be the new head of this group
    }
    //迭代版
    ListNode *reverseKGroup(ListNode *head, int k){
        if(head == nullptr || head->next == nullptr || k<2)
            return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode *prev = &dummy, *end = head; end; end = prev->next){
            for(int i=1; i<k&&end; i++)
                end = end->next;
            if(end == nullptr)
                break;
            prev = reverse(prev, prev->next, end);
        }

        return dummy.next;
    }
    //prev是first前一个元素，[begin,end]闭区间，保证三者都不为null
    //返回反转后的倒数第一个元素
    ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end){
        ListNode *end_next = end->next;
        for(ListNode *p = begin, *cur=p->next, *next = cur->next;
            cur != end_next;
            p = cur,cur = next, next=next?next->next:nullptr){
            cur->next = p;
        }
        begin->next = end_next;
        prev->next = end;
        return begin;
    }

    /**
     * 61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

Example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
     */
    //先遍历一遍，得出链表长度len,令 k%=len，
    //将尾节点next节点指向首结点，形成一个环，接着往后跑len-k步，从这里断开，就是要求的结果了。
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k==0)
            return head;

        int len = 1;
        ListNode *p = head;
        while(p->next){ //求长度
            len++;
            p = p->next;
        }
        k = len - k%len;

        p->next = head; //首尾相连
        for(int step=0; step<k; step++){
            p = p->next;
        }

        head = p->next;
        p->next = nullptr;
        return head;
    }

    /**
     * 82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
     */
    //递归版
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *p = head->next;
        if(head->val == p->val){
            while(p && head->val == p->val){
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicates(p);
        }else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
    //迭代版
    ListNode *deleteDuplicates(ListNode *head){
        if(head == nullptr)
            return head;

        ListNode dummy(INT_MIN); //头结点
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        while(cur != nullptr){
            bool duplicated = false;
            while(cur->next != nullptr && cur->val == cur->next->val){
                duplicated = true;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            if(duplicated){
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }

            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }

        prev->next = cur;
        return dummy.next;
    }

    /**
     * 83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
     */
    //递归版
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode dummy(head->val+1); //值与head不同即可
        dummy.next = head;

        recur(&dummy,head);
        return dummy.next;
    }
    static void recur(ListNode *prev, ListNode *cur){
        if(cur == nullptr)
            return ;

        if(prev->val == cur->val){
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        }else{
            recur(prev->next, cur->next);
        }
    }
    //迭代版
    ListNode* deleteDuplicates(ListNode* head){
        if(head == nullptr)
            return nullptr;

        for(ListNode *prev = head, *cur=head->next; cur; cur = prev->next){
            if(prev->val == cur->val){
                prev->next = cur->next;
                delete cur;
            }else{
                prev=cur;
            }
        }

        return head;
    }

    /**
     * 86. Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
     */
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1); //头结点
        ListNode right_dummy(-1); //头结点

        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;

        for(ListNode *cur = head; cur; cur = cur->next){
            if(cur->val < x){
                left_cur->next = cur;
                left_cur = cur;
            }else{
                right_cur->next = cur;
                right_cur = cur;
            }
        }

        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        return left_dummy.next;
    }

    /**
     * 92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        n -= m;
        ListNode prehead(0);
        prehead.next = head;
        ListNode *pre = &prehead;
        while(--m)
            pre = pre->next;
        ListNode *pstart = pre->next;
        while(n--){
            ListNode *p = pstart->next;
            pstart->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }

        return prehead.next;
    }

    /**
     * 138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
     */
    //扫描两遍
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode *cur = head; cur != nullptr; ){
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        for(RandomListNode* cur=head; cur!=nullptr;){
            if(cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        //分拆两个单链表
        RandomListNode dummy(-1);
        for(RandomListNode *cur = head, *new_cur = &dummy; cur!=nullptr; ){
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }

        return dummy.next;
    }

    /**
     * 141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
     */
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }

        return false;
    }

    /**
     * 142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode *slow2 = head;

                while(slow2 != slow){
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }

        return nullptr;
    }

	/*
	 * 143. Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
	 */
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        
        //找到中间结点
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2->next != NULL && p2->next->next != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        //翻转后半结点
        //1->2->3->4->5->6 to 1->2->3->6->5->4
        ListNode *preMiddle = p1;
        ListNode *preCurrent = p1->next;
        while(preCurrent->next != NULL){
            ListNode *current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }
        
        //合并结点
        //1->2->3->6->5->4 to 1->6->2->5->3->4
        p1 = head;
        p2 = preMiddle->next;
        while(p1 != preMiddle){
            preMiddle->next=p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }
    }

	/*
	 * 147. insertion-sort-list
	 * Sort a linked list using insertion sort.
	 */
	ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
        	return head;

        ListNode *dumy = new ListNode(0); //new starter of the sorted list
        ListNode *cur = head; //the node will be inserted
        ListNode *pre = dumy; //insert node between pre and pre.next
        ListNode *next = NULL; //the next node will be inserted

        while(cur != NULL){
        	next = cur->next;
        	while(pre->next != NULL && pre->next->val < cur->val) //find the right place to insert
        		pre = pre->next;
        	cur->next = pre->next;
        	pre->next = cur;
        	pre=dumy;
        	cur=next;
        }

        return dumy->next;
    }

	/*
	 * 148. Sort List
Sort a linked list in O(nlogn) time using constant space complexity.

Solution:
快慢指针，归并排序
https://www.nowcoder.com/questionTerminal/d75c232a0405427098a8d1627930bea6
	 */
    ListNode *sortList(ListNode *head){
        if(!head || !head->next)
            return head;
        
        ListNode *p = head, *q = head->next;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
        }
             
        ListNode *left = sortList(p->next);
        p->next = NULL;
        ListNode *right = sortList(head);

        return merge(left,right);
    }
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode dumy(0);
        ListNode *p = &dumy;
        while(left && right){
            if(left->val < right->val){
                p->next = left;
                left = left->next;
            }else{
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if(left)
            p->next = left;
        if(right)
            p->next = right;
        return dumy.next;
    }

    /**
     * 206. Reverse Linked List
     * Reverse a singly linked list.
     */
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr != NULL){
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

};