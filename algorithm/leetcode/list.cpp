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
	 * Sort a linked list in O(n log n) time using constant space complexity.
	 *
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
};