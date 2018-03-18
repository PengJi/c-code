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
	 * 94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-binary-tree-inorder-traversal.html
	 */
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> allNodeValues;
        TreeNode *cur = root;
        stack<TreeNode*> s;

        while(cur || !s.empty()){
        	if(!cur){
        		cur = s.top();
        		s.pop();
        		allNodeValues.push_back(cur->val);
        		cur = cur->right;
        	}else{
        		s.push(cur);
        		cur = cur->left;
        	}
        }

        return allNodeValues;
    }

  /**
   * 96. Unique Binary Search Trees
   * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   */
  int numTrees(int n) {
      vector<int> f(n+1,0);

      f[0] = 1;
      f[1] = 1;
      for(int i=2; i<=n; ++i){
        for(int k=1; k<=i; ++k)
          f[i] += f[k-1] * f[i-k];
      }

      return f[n];
  }

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
     * 114. 
     * Flatten Binary Tree to Linked List
     * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
     * Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-flatten-binary-tree-to-linked.html
     */
	void flatten(TreeNode* root) {
        if(!root)
        	return;
        vector<TreeNode *> allNodes;
        preorder(root,allNodes);
        int n = allNodes.size();
        for(int i=0;i<n-1;i++){
        	allNodes[i]->left = NULL;
        	allNodes[i]->right = allNodes[i+1];
        }
        allNodes[n-1]->left = allNodes[n-1]->right = NULL;
    }
    void preorder(TreeNode *root,vector<TreeNode*> &allNodes){
    	if(!root)
    		return;
    	allNodes.push_back(root);
    	preorder(root->left,allNodes);
    	preorder(root->right,allNodes);
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