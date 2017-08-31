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
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *currNode = pHead;
        while(currNode){
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while(currNode){ //复制链表
            RandomListNode *node = currNode->next;
            if(currNode->random){               
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        //拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }

    /*
     * 38
     * 字符串的排列
     * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
     * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
     * 
     * 输入描述:
     * 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
     */
    vector<string> Permutation(string str) {
        vector<string> vec;
        if(str.size() == 0)
            return vec;
        Permutation(vec,str,0);
        sort(vec.begin(),vec.end());
        return vec;
    }
    void Permutation(vector<string> &vec,string str,int begin){
        if(begin == str.size()-1)
            vec.push_back(str);
        for(int i = begin; i<=str.size()-1; ++i){
            if(i != begin && str[i] == str[begin])
                continue;
            swap(str[i],str[begin]);
            Permutation(vec,str,begin+1);
            swap(str[i],str[begin]);
        }
    }

}