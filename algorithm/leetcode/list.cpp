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