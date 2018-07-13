//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//2. Add Two Numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
//19. Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n);
//21. Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
//24. Swap Nodes in Pairs
ListNode* swapPairs(ListNode* head);
//25. Reverse Nodes in k-Group
ListNode* reverseKGroup(ListNode* head, int k);
//61. Rotate List
ListNode* rotateRight(ListNode* head, int k);
//82. Remove Duplicates from Sorted List II
ListNode* deleteDuplicates(ListNode* head);
//83. Remove Duplicates from Sorted List
ListNode* deleteDuplicates(ListNode* head);
//86. Partition List
ListNode* partition(ListNode* head, int x);
//92. Reverse Linked List II
ListNode* reverseBetween(ListNode* head, int m, int n);
//138. Copy List with Random Pointer
RandomListNode *copyRandomList(RandomListNode *head);
//141. Linked List Cycle
bool hasCycle(ListNode *head);
//142. Linked List Cycle II
ListNode *detectCycle(ListNode *head);
//143. Reorder List
void reorderList(ListNode* head);
//146. LRU Cache
void LRUCache(int capacity);
int get(int key);
void put(int key, int value);
//147. insertion-sort-list
ListNode* insertionSortList(ListNode* head);
//148. Sort List
ListNode *sortList(ListNode *head);
//160. Intersection of Two Linked Lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
//206. Reverse Linked List
ListNode* reverseList(ListNode* head);
//234. Palindrome Linked List
bool isPalindrome(ListNode* head);
