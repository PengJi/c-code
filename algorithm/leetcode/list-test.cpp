#include "list.h"

using namespace std;

ListNode* CreateListNode(int value){
    ListNode* pNode = new ListNode(value);
    // pNode->val = value;
    // pNode->next = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext){
    if(pCurrent == nullptr){
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode){
    if(pNode == nullptr){
        printf("The node is nullptr\n");
    }else{
        printf("The key in node is %d.\n", pNode->val);
    }
}

void PrintList(ListNode* pHead){
    printf("PrintList starts.\n");

    ListNode* pNode = pHead;
    while(pNode != nullptr){
        printf("%d\t", pNode->val);
        pNode = pNode->next;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead){
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value){
    ListNode* pNew = new ListNode(value);
    // pNew->val = value;
    // pNew->next = nullptr;

    if(*pHead == nullptr){
        *pHead = pNew;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr)
            pNode = pNode->next;

        pNode->next = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value){
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->val == value){
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr && pNode->next->val != value)
            pNode = pNode->next;

        if(pNode->next != nullptr && pNode->next->val == value){
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }

        if(pToBeDeleted != nullptr){
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
}

ListNode* reverse(ListNode *head){
    ListNode *prev = nullptr;
    while(head != nullptr){
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}
bool isPalindrome(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast != nullptr){
        slow = slow->next;
    }
    slow = reverse(slow);
    fast = head;

    while(slow != nullptr){
        if(fast->val != slow->val){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }

    return true;
}

void test_isPalindrome(){
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    PrintList(pNode1);

    printf("isPalindrome result %d\n", isPalindrome(pNode1));

    DestroyList(pNode1);
}

void test_isPalindrome1(){
    ListNode* pNode1 = CreateListNode(0);
    ListNode* pNode2 = CreateListNode(0);

    ConnectListNodes(pNode1, pNode2);

    PrintList(pNode1);

    printf("isPalindrome result %d\n", isPalindrome(pNode1));

    DestroyList(pNode1);
}

void test_isPalindrome2(){
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(0);
    ListNode* pNode3 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);

    PrintList(pNode1);

    printf("isPalindrome result %d\n", isPalindrome(pNode1));

    DestroyList(pNode1);
}

void test_isPalindrome3(){
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    PrintList(pNode1);

    printf("isPalindrome result %d\n", isPalindrome(pNode1));

    DestroyList(pNode1);
}

int main(){
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    PrintListNode(pNode4);
    PrintList(pNode1);

    AddToTail(&pNode1, 6);
    PrintList(pNode1);

    RemoveNode(&pNode1, 3);
    PrintList(pNode1);

    DestroyList(pNode1);

    test_isPalindrome();
    test_isPalindrome1();
    test_isPalindrome2();
    test_isPalindrome3();

    return 0;
}
