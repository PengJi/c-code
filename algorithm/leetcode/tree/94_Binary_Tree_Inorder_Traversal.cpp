#include <vector>


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
