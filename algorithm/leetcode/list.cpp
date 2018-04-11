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
	 * 2. 
	 * Add Two Numbers
	 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

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

	/*
	 * 21. 
	 * Merge Two Sorted Lists
	 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
	 *
	 * solution:
	 * http://bangbingsyb.blogspot.ca/2014/11/leetcode-merge-two-sorted-lists.html
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
     * 83. Remove Duplicates from Sorted List
     * Given a sorted linked list, delete all duplicates such that each element appear only once.

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
     * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

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
     * Reverse a linked list from position m to n. Do it in-place and in one-pass.
     *
     * For example:
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
     * 141. Linked List Cycle
     * Given a linked list, determine if it has a cycle in it.

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
     * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
	 * 143
	 * Reorder List
	 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
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
	 * 147
	 * insertion-sort-list
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
	 * 148
	 * Sort List
	 * Sort a linked list in O(nlogn) time using constant space complexity.
     *
     * solution:
	 * 快慢指针，归并排序
	 * https://www.nowcoder.com/questionTerminal/d75c232a0405427098a8d1627930bea6
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