#include "tree.h"

TreeNode* CreateTreeNode(int value){
    TreeNode* pNode = new TreeNode(value);
    pNode->left = nullptr;
    pNode->right = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight){
    if(pParent != nullptr){
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void PrintTreeNode(const TreeNode* pNode){
    if(pNode != nullptr){
        printf("value of this node is: %d\n", pNode->val);

        if(pNode->left != nullptr)
            printf("value of left child is: %d.\n", pNode->left->val);
        else
            printf("left child is nullptr.\n");

        if(pNode->right != nullptr)
            printf("value of right child is: %d.\n", pNode->right->val);
        else
            printf("right child is nullptr.\n");
    }else{
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const TreeNode* pRoot){
    PrintTreeNode(pRoot);

    if(pRoot != nullptr){
        if(pRoot->left != nullptr)
            PrintTreeNode(pRoot->left);

        if(pRoot->right != nullptr)
            PrintTreeNode(pRoot->right);
    }
}

void DestroyTree(TreeNode* pRoot){
    if(pRoot != nullptr){
        TreeNode* left = pRoot->left;
        TreeNode* right = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(left);
        DestroyTree(right);
    }
}

int main(){
    TreeNode *node1 = CreateTreeNode(1);

    delete node1;

    return 0;
}