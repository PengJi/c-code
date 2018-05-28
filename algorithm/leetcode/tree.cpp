/**
 * 树
 * 二叉树的遍历
 * 二叉树的构建
 * 二叉查找树
 * 二叉树的递归
 */
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
   * 95. Unique Binary Search Trees II
Given an integer n, generate all structurally unique BST's (binary search trees) 
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

problem:
https://leetcode.com/problems/unique-binary-search-trees-ii/description/

solution:
https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/133025/More-clean-and-readable-than-Top-discuss.(C++-version-from-jiuzhang-algorithm)
   */
    vector<TreeNode *> generate(int beg, int end){
      vector<TreeNode*> ret;
      if(beg>end){
        ret.push_back(NULL);
        return ret;
      }

      for(int i=beg; i<=end; i++){
        vector<TreeNode*> leftTree = generate(beg, i-1);
        vector<TreeNode*> rightTree = generate(i+1, end);
        for(int j=0; j<leftTree.size(); j++ )
          for(int k=0; k<rightTree.size(); k++){
            TreeNode *node = new TreeNode(i+1);
            ret.push_back(node);
            node->left = leftTree[j];
            node->right = rightTree[k];
          }
      }

      return ret;
    }
    vector<TreeNode*> generateTrees(int n){
      if(n==0){
        vector<TreeNode *> ret;
        return ret;
      }

      return generate(0, n-1);
    }

  /**
   * 96. Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

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

  /**
   * 98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
   */
	bool isValidBST(TreeNode* root) {
		return isValidBST(root,NULL,NULL);
	}
	bool isValidBST(TreeNode *root,TreeNode* lower, TreeNode* upper){
		if(root == nullptr)
			return true;
		if(lower && root->val <= lower->val || upper && root->val >= upper->val)
			return false;
		return isValidBST(root->left,lower,root) && isValidBST(root->right,root,upper);
  }

  /**
   * 99. Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
   */
  /*
  O(n) 空间的解法是，开一个指针数据，中序遍历，将节点指针一次存放到数组里，然后寻找亮出逆向的位置，
  先从前往后找第一个逆序的位置，然后从后往前找第二个逆序的位置，交换这两个指针的值。
  中序遍历一般需要用到栈，空间也是O(n)。
   */
  //morris中序遍历
  void recoverTree(TreeNode* root) {
    pair<TreeNode *,TreeNode*> broken;
    TreeNode* prev = nullptr;
    TreeNode* cur = root;

    while(cur != nullptr){
      if(cur->left == nullptr){
        detect(broken,prev,cur);
        prev = cur;
        cur = cur->right;
      }else{
        auto node = cur->left;

        while(node->right != nullptr && node->right != cur)
          node = node->right;

        if(node->right == nullptr){
          node->right = cur;
          //prev = cur; 不能有这句，因为cur还没有被访问。
          cur = cur->left;
        }else{
          detect(broken,prev,cur);
          node->right = nullptr;
          prev=cur;
          cur = cur->right;
        }
      }
    }
    swap(broken.first->val, broken.second->val);
  }
  void detect(pair<TreeNode*,TreeNode*> &broken, TreeNode* prev, TreeNode *current){
    if(prev != nullptr && prev->val > current->val){
      if(broken.first == nullptr){
        broken.first = prev;
      } //不能用else，例如{1,0}，会导致最后swap时，second为nullptr
      broken.second = current;
    }
  }

  /**
   * 100. Same Tree
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

Example 2:
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false

Example 3:
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
   */
  //递归版
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q)
      return true;
    if(!p || !q)
      return false;

    return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
  }
  //迭代版
  bool isSameTree(TreeNode *p, TreeNode *q) {
    stack<TreeNode *> s;
    s.push(p);
    s.push(q);

    while(!s.empty()){
      p = s.top();
      s.pop();
      q = s.top();
      s.pop();

      if(!p && !q)
        continue;
      if(!p || !q)
        return false;
      if(p->val != q->val)
        return false;

      s.push(p->left);
      s.push(q->left);

      s.push(p->right);
      s.push(q->right);
    }

    return true;
  }

	/*
	 * 101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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

  /**
   * 102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
   */
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    traverse(root,1,result);
    return result;
  }
  void traverse(TreeNode *root, size_t level, vector<vector<int>> &result){
    if(!root)
      return;

    if(level > result.size())
      result.push_back(vector<int>());

    result[level-1].push_back(root->val);

    traverse(root->left, level+1, result);
    traverse(root->right, level+1, result);
  }

  /**
   * 103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
   */
  //广度优先遍历，用一个bool记录是从左到右还是从右到左，每一层结束就翻转一下
  //递归
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    traverse(root, 1, result, true);
    return result;
  }
  void traverse(TreeNode *root, size_t level, vector<vector<int>> &result, bool left_to_right){
    if(!root)
      return;

    if(level > result.size())
      result.push_back(vector<int>());

    if(left_to_right)
      result[level-1].push_back(root->val);
    else
      result[level-1].insert(result[level-1].begin(),root->val);

    traverse(root->left, level+1, result, !left_to_right);
    traverse(root->right, level+1, result, !left_to_right);
  }
  //迭代版
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode *> current, next;
    bool left_to_right = true;

    if(root == nullptr){
      return result;
    }else{
      current.push(root);
    }

    while(!current.empty()){
      vector<int> level;
      while(!current.empty()){
        TreeNode *node = current.front();
        current.pop();
        level.push_back(node->val);
        if(node->left != nullptr)
          next.push(node->left);
        if(node->right != nullptr)
          next.push(node->right);
      }
      if(!left_to_right)
        reverse(level.begin(), level.end());
      result.push_back(level);
      left_to_right = !left_to_right;
      swap(next,current);
    }

    return result;
  }

  /**
     * 104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
     */
  int maxDepth(TreeNode* root) {
    if(root == nullptr)
      return 0;

    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
  }

  /**
   * 105. Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
   */
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(begin(preorder), end(preorder), 
      begin(inorder), end(inorder));
  }
  template<typename InputIterator>
  TreeNode *buildTree(InputIterator pre_first, InputIterator pre_last,
    InputIterator in_first, InputIterator in_last){
    if(pre_first == pre_last) return nullptr;
    if(in_first == in_last) return nullptr;

    auto root = new TreeNode(*pre_first);

    auto inRootPos = find(in_first, in_last, *pre_first);
    auto leftSize = distance(in_first, inRootPos);

    root->left = buildTree(next(pre_first), next(pre_first,
      leftSize + 1), in_first, next(in_first, leftSize));
    root->right = buildTree(next(pre_first, leftSize+1), pre_last,
      next(inRootPos), in_last);

    return root;
  }

  /**
   * 106. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
   */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return buildTree(begin(inorder), end(inorder),
        begin(postorder), end(postorder));
    }
    template<typename BidiIt>
    TreeNode *buildTree(BidiIt in_first, BidiIt in_last,
      BidiIt post_first, BidiIt post_last){
      if(in_first == in_last) return nullptr;
      if(post_first == post_last) return nullptr;

      const auto val = *prev(post_last);
      TreeNode *root = new TreeNode(val);

      auto in_root_pos = find(in_first, in_last, val);
      auto left_size = distance(in_first, in_root_pos);
      auto post_left_last = next(post_first, left_size);

      root->left = buildTree(in_first, in_root_pos, post_first, post_left_last);
      root->right = buildTree(next(in_root_pos), in_last, post_left_last, prev(post_last));

      return root;
    }

  /**
   * 107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
   */
  //递归
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    traverse(root,1,result);
    std::reverse(result.begin(), result.end());
    return result;
  }
  void traverse(TreeNode *root, size_t level, vector<vector<int>> &result){
    if(!root)
      return;

    if(level > result.size())
      result.push_back(vector<int>());

    result[level-1].push_back(root->val);
    traverse(root->left, level+1, result);
    traverse(root->right, level+1, result);
  }
  //迭代
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if(root == nullptr)
      return result;

    queue<TreeNode *> current, next;
    vector<int> level; //elements in level

    current.push(root);
    while(!current.empty()){
      while(!current.empty()){
        TreeNode *node = current.front();
        current.pop();
        level.push_back(node->val);
        if(node->left != nullptr)
          next.push(node->left);
        if(node->right != nullptr)
          next.push(node->right);
      }
      result.push_back(level);
      level.clear();
      swap(next,current);
    }

    reverse(result.begin(), result.end());

    return result;
  }

  /**
     * 108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of 
every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
     */
    //分治法
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }

    template<typename RandomAccessIterator>
    TreeNode *sortedArrayToBST(RandomAccessIterator first,
      RandomAccessIterator last){
      const auto length = distance(first,last);

      if(length <= 0)
        return nullptr;

      auto mid = first+length/2;
      TreeNode *root = new TreeNode(*mid);
      root->left = sortedArrayToBST(first,mid);
      root->right = sortedArrayToBST(mid+1,last);

      return root;
    }

    /**
     * 109. Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted linked list: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
     */
  //自底向上
  TreeNode* sortedListToBST(ListNode* head) {
    int len = 0;
    ListNode *p = head;
    while(p){
      len++;
      p = p->next;
    }

    return sortedListToBST(head, 0, len-1);
  }
  TreeNode *sortedListToBST(ListNode*& list, int start, int end){
    if(start>end) return nullptr;

    int mid = start+(end-start)/2;
    TreeNode *leftChild = sortedListToBST(list, start, mid-1);
    TreeNode *parent = new TreeNode(list->val);
    parent->left = leftChild;
    list = list->next;
    parent->right = sortedListToBST(list, mid+1, end);

    return parent;
  }

    /**
     * 110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
     */
  bool isBalanced(TreeNode* root) {
    return balancedHeight(root) >= 0;
  }
  int balancedHeight(TreeNode *root){
    if(root == nullptr)
      return 0;

    int left = balancedHeight(root->left);
    int right = balancedHeight(root->right);

    if(left < 0 || right < 0 || abs(left-right) > 1) //剪枝
      return -1;

    return max(left,right) + 1; //三方合并
  }

	/*
	 * 111. Minimum Depth of Binary Tree
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

    /**
     * 112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
     * 
     */
  bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr)
      return false;

    if(root->left == nullptr && root->right == nullptr) //leaf
      return sum == root->val;

    return hasPathSum(root->left,sum-root->val)
      || hasPathSum(root->right,sum-root->val);
  }

  /**
   * 113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
   */
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int> cur;
    pathSum(root, sum, cur, result);
    return result;
  }
  void pathSum(TreeNode *root, int gap, vector<int> &cur, vector<vector<int>> &result){
    if(root == nullptr)
      return;

    cur.push_back(root->val);

    if(root->left == nullptr && root->right==nullptr){
      if(gap == root->val)
        result.push_back(cur);
    }

    pathSum(root->left, gap-root->val, cur, result);
    pathSum(root->right, gap-root->val, cur, result);

    cur.pop_back();
  }
    
    /*
     * 114. Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

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

    /**
     * 116. Populating Next Right Pointers in Each Node
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
 and every parent has two children).

Example:
Given the following perfect binary tree,
     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:
     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
     */
  void connect(TreeLinkNode *root) {
    connect(root, NULL);
  }
  void connect(TreeLinkNode *root, TreeLinkNode *sibling){
    if(root == nullptr)
      return;
    else
      root->next = sibling;

    connect(root->left, root->right);
    if(sibling)
      connect(root->right, sibling->left);
    else
      connect(root->right, nullptr);
  }

  /**
     * 117. Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
     */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
  void connect(TreeLinkNode *root) {
    if(root == nullptr)
      return;

    TreeLinkNode dumy(-1);
    for(TreeLinkNode *curr = root,*prev = &dumy; curr; curr = curr->next){
      if(curr -> left != nullptr){
        prev -> next = curr->left;
        prev = prev->next;
      }

      if(curr->right != nullptr){
        prev->next = curr->right;
        prev = prev->next;
      }
    }

    connect(dumy.next);
  }

  /**
     * 124. Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree 
along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
     */
    /*
    路径可以从任意结点开始，到任意结点结束
    可以利用“最大连续子序列”问题的思路，可以采用binary tree最常用的dfs来进行遍历。
    先算出左右子树的结果L和R，如果L大于0，那么对后续结果是有利的，加上L，
    如果R大于0，对后续结果也是有利的，继续加上R。
     */
  int max_sum;
  int maxPathSum(TreeNode* root) {
    max_sum = INT_MIN;
    dfs(root);
    return max_sum;
  }
  int dfs(const TreeNode *root){
    if(root==nullptr)
      return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);

    int sum = root->val;
    if(l>0)
      sum += l;
    if(r>0)
      sum += r;
    max_sum = max(max_sum,sum);
    return max(r,l) >0 ? max(r,l)+root->val:root->val;
  }

  /**
   * 129. Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
   */
  int sumNumbers(TreeNode* root) {
    return dfs(root,0);
  }
  int dfs(TreeNode *root, int sum){
    if(root == nullptr)
      return 0;

    if(root->left == nullptr && root->right == nullptr)
      return sum*10 + root->val;

    return dfs(root->left, sum*10+root->val) + dfs(root->right, sum*10+root->val);
  }

  /**
   * 144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?

problem:
https://leetcode.com/problems/binary-tree-preorder-traversal/description/
   */
    //使用栈
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode *> s;
        if(root != nullptr) s.push(root);

        while(!s.empty()){
            const TreeNode *p = s.top();
            s.pop();
            result.push_back(p->val);

            if(p->right != nullptr) s.push(p->right);
            if(p->left != nullptr) s.push(p->left);
        }

        return result;
    }
    //Morris先序遍历
    vector<int> preorderTraversal(TreeNode *root){
        vecotr<int> result;
        TreeNode *cur = root, *prev = nullptr;

        while(cur != nullptr){
          if(cur->left == nullptr){
              result.push_back(cur->val);
              prev = cur;
              cur = cur->right;
          }else{
              //查找前驱
              TreeNode *node = cur->left;
              while(node->right 1= nullptr && node->right != cur)
                  node = node->right;

              if(node->right == nullptr){ //还没线索化，则建立线索
                  result.push_back(cur->val); //仅这一行的位置与中序不同
                  node->right = cur;
                  prev = cur; //cur刚刚被访问过
                  cur = cur->left;
              }else{ //已经线索化，则删除线索
                  node->right = nullptr;
                  cur = cur->right;
              }
          }
        }

        return result;
    }

	/*
	 * 145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

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