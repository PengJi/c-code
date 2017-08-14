#include <stream>

using namespace std;

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

}
 