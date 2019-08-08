#include <iostream>

using namespace std;

/**
 * 树
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
public:
 	/**
     * 7
 	 * 重建二叉树
 	 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 	 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 	 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和
 	 * 中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 	 */
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int inlen = vin.size();
        if(inlen == 0)
            return NULL;
        vector<int> left_pre,right_pre,left_in,right_in;
        //创建根结点，根结点肯定是前序遍历的第一个数
        TreeNode* head = new TreeNode(pre[0]);
        //中序遍历根结点所在位置，存放于变量gen中
        int gen = 0;
        for(int i = 0;i<inlen;i++){
            if(vin[i] == pre[0]){
                gen = i;
                break;
            }
        }
        
        // 对于中序遍历，根结点左边的结点位于二叉树的左边，
        // 根结点右边的结点位于二叉树俄右边
        // 对二叉树结点进行归并
        for(int i = 0;i<gen;i++){
            left_in.push_back(vin[i]);
            left_pre.push_back(pre[i+1]); //注意这里不能使用++i
        }
        for(int i = gen+1;i<inlen;i++){
            right_in.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }
        
        // 取出前序和中序遍历根结点左边和右边的子树
        // 递归，再对其进行上述所有步骤，即再区分子树的左右子树，直到页结点
        head -> left = reConstructBinaryTree(left_pre,left_in);
        head -> right = reConstructBinaryTree(right_pre,right_in);
        
        return head;
    }

    /**
     * 二叉树前序遍历
     */
    // 递归先序遍历
	void recursionPreorderTraversal(TreeNode* root) {
	    if (root != null) {
	        printf("%d", root->val);
	        recursionPreorderTraversal(root->left);
	        recursionPreorderTraversal(root->right);
	    }
	}
	// 非递归先序遍历
	void preorderTraversal(TreeNode *root) {
	    // 用来暂存节点的栈
	    Stack<TreeNode> treeNodeStack;
	    // 新建一个游标节点为根节点
	    TreeNode *node = root;
	    // 当遍历到最后一个节点的时候，无论它的左右子树都为空，并且栈也为空
	    // 所以，只要不同时满足这两点，都需要进入循环
	    while (node != null || !treeNodeStack.empty()) {
	        // 若当前考查节点非空，则输出该节点的值
	        // 由考查顺序得知，需要一直往左走
	        while (node != null) {
	            printf("%d ",node->val);
	            // 为了之后能找到该节点的右子树，暂存该节点
	            treeNodeStack.push(node);
	            node = node->left;
	        }
	        // 一直到左子树为空，则开始考虑右子树
	        // 如果栈已空，就不需要再考虑
	        // 弹出栈顶元素，将游标等于该节点的右子树
	        if (!treeNodeStack.empty()) {
	            node = treeNodeStack.pop();
	            node = node->right;
	        }
	    }
	}

	/**
	 * 二叉树中序遍历
	 * 
	 */
	// 递归中序遍历
	void recursionMiddleorderTraversal(TreeNode *root) {
	    if (root != null) {
	        recursionMiddleorderTraversal(root->left);
	        printf("%d ",root->val);
	        recursionMiddleorderTraversal(root->right);
	    }
	}
	// 非递归中序遍历
	void middleorderTraversal(TreeNode *root) {
	    Stack<TreeNode> treeNodeStack;
	    TreeNode *node = root;
	    while (node != null || !treeNodeStack.empty()) {
	        while (node != null) {
	            treeNodeStack.push(node);
	            node = node->left;
	        }
	        if (!treeNodeStack.empty()) {
	            node = treeNodeStack.pop();
	            printf("%d ",node->val);
	            node = node->right;
	        }
	    }
	}

    /**
     * 二叉树后序遍历
     */
    //递归遍历
    void PostTraRec(TreeNode * root){
        if(root != NULL){
            PostTraRec(root->left);
            PostTraRec(root->right);
            printf("%d\n",root->val);
        }
    }
    //非递归遍历
    /**
     * 后续遍历在决定是否可以输出当前节点的值的时候，
     * 需要考虑其左右子树是否都已经遍历完成.
     *
     * 设置一个lastVisit标志
     * 若lastVisit等于当前考察节点的右子树，
     * 表示该节点的左右子树都已经遍历完成，则可以输出当前节点
     * 并把lastVisit的节点设置成当前节点，将当前节点node设置为空，
     * 下一轮就可以访问栈顶元素。
     * 否则，需要接着考虑右子树，node = node->right
     */
    void PostTra(TreeNode *root){
        stack<TreeNode *> stack;
        TreeNode *node = root;
        TreeNode *lastVisit = root;
        while(node != NULL || !stack.empty()){
            while(node != NULL){
                stack.push(node);
                node = node->left;
            }

            //查看当前栈顶元素
            node = stack.top();
            //如果其右子树也为空，或者右子树已经访问
            //则可以直接输出当前节点的值
            if(node->right == NULL || node->right == lastVisit){
                printf("%d ", node->val);
                stack.pop();
                lastVisit = node;
                node = null;
            }else{
                //否则，继续遍历右子树
                node = node->right;
            }
        }
    }

    /**
     * 33
     * 二叉搜索树的后序遍历序列
     * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
     * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
     *
     * BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x(根结点)，
     * 如果去掉最后一个元素的序列T，那么T满足：T可以分为两段，
     * 前一段（左子树）小于x，后一段（右子树）大于x，
     * 且这两段（子树）都是合法的后序序列。
     */
    bool judge(vector<int>& a, int l, int r){
        if(l >= r) return true;
        int i = r;
        while(i > l && a[i - 1] > a[r]) 
            --i;
        for(int j = i - 1; j >= l; --j) 
            if(a[j] > a[r]) 
                return false;
        return judge(a, l, i - 1) && (judge(a, i, r - 1));
	}
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }

	/** 
	 * 34
	 * 二叉树中和为某一值的路径
	 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为
	 * 输入整数的所有路径。路径定义为从树的根结点开始往下
	 * 一直到叶结点所经过的结点形成的一条路径，
	 */
	vector<vector<int> >allRes;
    vector<int> tmp;
    void dfsFind(TreeNode * node , int left){
        tmp.push_back(node->val);
        if(left-node->val == 0 && !node->left && !node->right)
            allRes.push_back(tmp);
        else {
            if(node->left) 
                dfsFind(node->left, left-node->val);
            if(node->right) 
                dfsFind(node->right, left-node->val);
        }
        tmp.pop_back(); 
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfsFind(root, expectNumber);
        return allRes;
    }

	/** 
	 * 二叉搜索树与双向链表
	 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
	 * 要求不能创建任何新的节点，智能调整整树中结点指针的指向。
	 *
	 * 树的线索化
	 */
	TreeNode pre=null;
    TreeNode lastLeft=null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        if(pRootOfTree==null){
            return null;
        }
        Convert(pRootOfTree.left);
        pRootOfTree.left=pre;
        if(pre!=null)pre.right=pRootOfTree;
        pre=pRootOfTree;
        lastLeft=lastLeft==null?pRootOfTree:lastLeft;
        Convert(pRootOfTree.right);
        return lastLeft; 
    }

	/**
	 * 55
	 * 二叉树的深度
	 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
	 * 最长路径的长度为树的深度。
	 */
	int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        return max(1+TreeDepth(pRoot->left),1+TreeDepth(pRoot->right));
    }
    //offer
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        
        int nleft = TreeDepth(pRoot->left);
        int nright = TreeDepth(pRoot->right);
        
        return nleft>nright?(nleft+1):(nright+1);
    }

    /**
     * 56
     * 平衡二叉树
     * 输入一棵二叉树，判断该二叉树是否是平衡二叉树
     * 
     * 后序遍历二叉树，遍历过程中求子树高度，判断是否平衡
     */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot,dep);
    }
    bool IsBalanced(TreeNode *root,int &dep){
        if(root == NULL){
            return true;
        }
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right,right)){
            int dif = left-right;
            if(dif<-1 || dif >1) return false;
            dep = (left>right ? left:right)+1;
            return true;
        }
        return false;
    }

    /**
     * 二叉树的下一个结点
     * 给定一个二叉树和其中的一个结点，
     * 请找出中序遍历顺序的下一个结点并且返回。
     * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
     *
     * 	分两种情况：
     * 1.该节点存在右子节点，则下一个节点是右子树的最左节点。
     * 2.该节点不存在右子节点，则下一个节点是该节点的第一个父子关系为左的祖先节点中的父节点。
     */
    struct TreeLinkNode {
        int val;
        struct TreeLinkNode *left;
        struct TreeLinkNode *right;
        struct TreeLinkNode *next;
        TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
	};
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        if(pNode->right != NULL){ //有右子树
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        TreeLinkNode* p = pNode->next; //没有右子树，是父结点的左子树
        while(p && pNode == p->right){ //没有右子树，并且是父结点的右子树
            pNode = p;
            p = pNode->next;
        }
        return p;
    }

	/**
     * 27
	 * 二叉树的镜像
	 * 操作给定的二叉树，将其变换为源二叉树的镜像
	 */
	void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL){
            return;
        }
        TreeNode *tmp = pRoot -> left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    /**
     * 28
     * 对称的二叉树
     * 请实现一个函数，用来判断一颗二叉树是不是对称的。
     * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
     *
     */
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
           return true;
        
        return func(pRoot->left,pRoot->right);
    }
    bool func(TreeNode* left,TreeNode* right){
        if(left == NULL &&　right == NULL)
            return true;
        if(left != NULL && right != NULL)
            return (left->val == right->val) && func(left->left,right->right) && func(left->left,right->right);
        
        return false;
    }
    //offer
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot,pRoot);
    }
    bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1 == NULL && pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL || pRoot2 == NULL) //把遇到的NULL指针也考虑进来
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        
        return isSymmetrical(pRoot1->left,pRoot2->right) 
            && isSymmetrical(pRoot1->right,pRoot2->left);
    }

    /**
     * 从上往下打印二叉树
     * 从上往下打印出二叉树的每个结点，同层结点从左往右打印
     */
    vector<int> PrintFromTopToBottom(TreeNode *rt){
        queue<TreeNode*> q;
        q.push(rt);
        vector<int> r;
        while(!q.empty()){
            rt = q.front();
            q.pop();
            if(!rt) continue;
            r.push_back(rt->val);
            q.push(rt->left);
            q.push(rt->right);
        }
        return r;
    }

    /**
     * 按之字形顺序打印二叉树
     * 请实现一个函数按照之字形打印二叉树，
     * 即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
     * 第三行按照从左到右的顺序打印，其他行以此类推。
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;
        vector<TreeNode*> q1;
        vector<TreeNode*> q2;
        q1.push_back(pRoot);
        bool model = true;//ture表示方向从左向右
        while (!q1.empty()){
            q2 = q1;
            q1.clear();
            vector<int> row;
            while (!q2.empty()){//把当前层全部访问，并将孩子按一定顺序入栈
                TreeNode *temp = q2.back();
                q2.pop_back();
                row.push_back(temp->val);
                if (model == true){//turew为从左向右
                    if (temp->left) q1.push_back(temp->left);
                    if (temp->right) q1.push_back(temp->right);
                }
                else{//false为从右向左
                    if (temp->right) q1.push_back(temp->right);
                    if (temp->left) q1.push_back(temp->left);
                }
            }
            model = !model;//变换方向
            res.push_back(row);
        }
        return res;
    }

	/**
	 * 把二叉树打印成多行
	 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
	 */
	vector<vector<int> > Print(TreeNode* pRoot) {
            
        	vector<vector<int>> vec;
            if(pRoot == NULL) return vec;
            
            queue<TreeNode*> q;
            q.push(pRoot);
            
            while(!q.empty()){
                int i=0,size=q.size();
                vector<int> v;
                for(i;i<size;i++){
                    TreeNode *t = q.front();
                    v.push_back(t->val);
                    q.pop();
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right);
                }
                vec.push_back(v);
            }
            
            return vec;
     }

     /**
      * 序列化二叉树
      * 请实现两个函数，分别用来序列化和反序列化二叉树
      */
    TreeNode* decode(char *&str) {
        if(*str=='#'){
            str++;
            return NULL;
        }
        int num = 0;
        while(*str != ',')
            num = num*10 + (*(str++)-'0');
        str++;
        TreeNode *root = new TreeNode(num);
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
    char* Serialize(TreeNode *root) {    
        if(!root) return "#";
        string r = to_string(root->val);
        r.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left) + strlen(right) + r.size()];
        strcpy(ret, r.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        return decode(str);
    }

    /**
     * 二叉搜索树的第k个结点
     * 给定一颗二叉搜索树，请找出其中的第k大的结点。
     * 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
     *
     * 二叉搜索树按照中序遍历的顺序打印出来正好就是排序好的顺序。
     * 所以，按照中序遍历顺序找到第k个结点就是结果。
     */
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot){
            TreeNode *t = KthNode(pRoot->left,k);
            if(t) return t;
            if(++count==k)  return pRoot;
            t = KthNode(pRoot->right,k);
            if(t) return t;
        }
        return NULL;
    }
    //offer
    TreeNode* KthNodeRes(TreeNode *pRoot, int &k){
    	TreeNode *t = NULL;
    	if(pRoot->left != NULL)
    		t = KthNodeRes(pRoot->left,k);
    	if(t==NULL){
    		if(k==1)
    			t = pRoot;
    		k--;
    	}
    	if(pRoot->right != NULL && t==NULL)
    		t = KthNodeRes(pRoot->right,k);

    	return t;
    }
	TreeNode* KthNode(TreeNode* pRoot, int k)
    {
    	if(pRoot == NULL || k<=0)
    		return NULL;
    	return KthNodeRes(pRoot,k);
    }

	/** 
     * 树的子结构
	 * 输入两棵二叉树A，B，判断B是不是A的子结构。
     *（ps：我们约定空树不是任意一个树的子结构）
     */
    bool isSubtree(TreeNode* pRoota,TreeNode* pRootb){
        if(pRootb == NULL) return true;
        if(pRoota == NULL) return false;
        if(pRoota -> val == pRootb -> val){
            return isSubtree(pRoota->left,pRootb->left) && isSubtree(pRoota -> right,pRootb -> right);
        }else 
            return false;
    }
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        return isSubtree(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1 -> right,pRoot2);
    }
	
	/**
     * 树的子结构
     * 输入两棵二叉树A B，判断B是不是A的子结构。
     * 约定空树不是任意一个树的子结构
     *
	 * 1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
	 * 剩下的代码不会执行，如果匹配不成功，默认返回false
	 * 2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
	 * 如果根节点不相同，则判断tree1的左子树和tree2是否相同，
	 * 再判断右子树和tree2是否相同
	 * 3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
	 * DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
	 * tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
	 * （2）如果tree1为空，tree2为空，说明匹配。
     */
	public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        boolean result = false;
        if(root1 != null && root2 != null){
                if(root1.val == root2.val){
                    result = DoesTree1HaveTree2(root1,root2);
                }
                if(!result){result = HasSubtree(root1.left, root2);}
                if(!result){result = HasSubtree(root1.right, root2);}
            }
            return result;
    }
    public boolean DoesTree1HaveTree2(TreeNode root1,TreeNode root2){
            if(root1 == null && root2 != null) return false;
            if(root2 == null) return true;
            if(root1.val != root2.val) return false;
            return DoesTree1HaveTree2(root1.left, root2.left) && DoesTree1HaveTree2(root1.right, root2.right);
	}
    /** 
     * 36
     * 二叉搜索树与双向链表
     * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
     * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
     */
    TreeNode *pre = NULL;
    TreeNode *lastLeft = NULL; //表示已转换好的链表的最后一个结点
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;

        Convert(pRootOfTree->left);

        pRootOfTree->left = pre;
        if(pre != NULL)
            pre->right = pRootOfTree;
        pre = pRootOfTree;
        lastLeft = lastLeft==NULL?pRootOfTree:lastLeft;

        Convert(pRootOfTree->right);

        return lastLeft;
    }

    //判断两个浮点数是否相等
    bool Equal(double num1,double num2){
        if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
            return true;
        else 
            return false;
    }
}
 