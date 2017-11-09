/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	/*
	 * 101. Symmetric Tree
	 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
	 */
	bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }

	/*
	 * 111
	 * Minimum Depth of Binary Tree
	 * Given a binary tree, find its minimum depth.
	 * The minimum depth is the number of nodes along the shortest 
	 * path from the root node down to the nearest leaf node.
	 */
    int minDepth(TreeNode* root) {
        if(!root)
        	return 0;
        if(!root->left)
        	return 1+minDepth(root->right);
        if(!root->right)
        	return 1+minDepth(root->left);

        return 1+min(minDepth(root->left),minDepth(root->right));
    }

	/*
	 * 145
	 * Binary Tree Postorder Traversal
	 * Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
	 */
	 vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        TreeNode *lastVisit = root;
        while(node != NULL || !stk.empty()){
            while(node != NULL){
                stk.push(node);
                node = node->left;
            }
            
            node = stk.top();
            
            if(node -> right == NULL || node -> right == lastVisit){
                vec.push_back(node->val);
                stk.pop();
                lastVisit = node;
                node = NULL;
            }else{
                node = node->right;
            }
        }
        
        return vec;
    }
};