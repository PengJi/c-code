/*
 * 分解让复杂的问题简单化
 * 
 */
class Solution{
public:
	/*
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

    /*
     * 35
     * 复杂链表的复制
     * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
     * 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
     */
    /*
	struct RandomListNode {
    	int label;
    	struct RandomListNode *next, *random;
    	RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
	*/
    RandomListNode* Clone(RandomListNode* pHead){
    	RandomListNode *pNode  = pHead;
    	while(pNode != NULL){
    		RandomListNode *pCloned = pNode->next;
    		if(pNode->random != NULL){
    			pCloned = pNode->random->next;
    		}
    		pNode = pCloned->next;
    	}
    }

}