#include <iostream>

using namespace std;

/*
 * 树的算法
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
public:
 	/*
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
            left_pre.push_back(pre[i+1]);
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

    /*
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

	/*
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

    /*
     * 从上往下打印二叉树
     * 从上往下打印出二叉树的每个结点，同城结点从左往右打印
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

    /*
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
        while(i > l && a[i - 1] > a[r]) --i;
        for(int j = i - 1; j >= l; --j) if(a[j] > a[r]) return false;
        return judge(a, l, i - 1) && (judge(a, i, r - 1));
	}
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }

	/*
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
            if(node->left) dfsFind(node->left, left-node->val);
            if(node->right) dfsFind(node->right, left-node->val);
        }
        tmp.pop_back(); 
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfsFind(root, expectNumber);
        return allRes;
    }

	/*
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

	/*
	 * 二叉树的深度
	 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
	 * 最长路径的长度为树的深度。
	 */
	int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        return max(1+TreeDepth(pRoot->left),1+TreeDepth(pRoot->right));
    }

    /*
     * 平衡二叉树
     * 输入一棵二叉树，判断该二叉树是否是平衡二叉树
     * 
     * 后续遍历二叉树，遍历过程中求子树高度，判断是否平衡
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

    /*
     * 二叉树的下一个结点
     * 给定一个二叉树和其中的一个结点，
     * 请找出中序遍历顺序的下一个结点并且返回。
     * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
     *
     * 	分两种情况：
     * 1.该节点存在右子节点，则下一个节点是右子树的最左节点。
     * 2.该节点不存在右子节点，则 下一个节点是 该节点的第一个父子关系为左的祖先节点中的父节点。
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

    /*
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

    /*
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

	/*
	 * 把二叉树打印成多行
	 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
	 * 
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

     /*
      * 系列化二叉树
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

    /*
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

    /*
     * 41
     * 数据流中的中位数
     * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
     * 那么中位数就是所有数值排序之后位于中间的数值。
     * 如果从数据流中读出偶数个数值，
     * 那么中位数就是所有数值排序之后中间两个数的平均值。
     *
     * 利用堆实现
     */
    priority_queue<int,vector<int>,less<int>> p; //小顶堆
    priority_queue<int,vector<int>,greater<int>> q; //大顶堆
    void Insert(int num)
    {
        if(p.empty() || num <= p.top())
            p.push(num);
        else 
            q.push(num);
        if(p.size() == q.size() + 2){
            q.push(p.top());
            p.pop();
        }
        if(p.size()+1 == q.size()){
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    { 
        return p.size()==q.size()?(p.top()+q.top())/2.0:p.top();
    }
}
 