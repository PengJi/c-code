#include <iostream>
#include <cstdio>

using namespace std;

void inOrderTrav(TreeNode *root){
	stack<TreeNode *> stk;
	if(root == NULL)
		printf("%d ", -1);

	TreeNode *node = root;

	while(node != NULL || !stk.empty()){
		while(node){
			stk.push(node);
			node = node->left;
		}

		if(!stk.empty()){
			node = stk.pop();
			printf("%d ",node->val);
			node = node->right;
		}
	}
}

void preOrderTrav(TreeNode *root){
	stack<TreeNode *> stk;
	if(root == NULL){
		printf();
	}

	TreeNode *node = root;
	while(node != NULL || !stk.empty()){
		while(node){
			printf("%d", node->val);
			stk.push(node);
			node = node->left;
		}

		if(!stk.empty()){
			node = stk.pop();
			node = node->right;
		}
	}
}

void postOrderTrav(TreeNode *root){
	if(root == NULL)
		printf("%d ",-1);

	stack<TreeNode *> stk;
	TreeNode *node = root;
	TreeNode *lastVisit = root;

	while(node != NULL || !stk.empty()){
		while(node){
			stk.push(node);
			node = node->left;
		}

		node = stk.top();
		if(node->right == NULL || node->right == lastVisit){
			printf("%d ",node->val);
			stk.pop();
			lastVisit = node;
			node = NULL;
		}else{
			node = node->right;
		}
	}
}

int partition(int a[],int low,int high){
	int pivot = a[low];
	while(low < high){
		while(pivot < a[high])
			high--;
		swap(&a[low],&a[high]);
		while(pivot > a[low])
			low++;
		swap(&a[low],&a[high]);
	}

	return low;
}

void quickSort(int a[],int low,int high){
	if(low < high){
		int mid = partition(a,low,high);
		quickSort(a,low,mid-1);
		quickSort(a,mid+1,high);
	}
}

void heapAdjust(int H[],int s,int length){
	int child =2*s+1;
	int tmp = H[s];

	while(child < length){
		if(H[child] < H[child+1] && child < length)
			child++;

		if(H[s]<H[child]){
			H[s] = H[child];
			s = child;
			child = 2*s+1;
		}
		H[s] = tmp;
	}
}

void build(int H[],int length){
	for(int i = (length-1)/2;i>=0;i--){
		heapAdjust(H,i,length);
	}
}

void heapSort(int H[],length){
	build(H,length);

	for(int i=length-1;i>0;i--){
		swap(H[0],H[i]);
		heapAdjust(H,0,i);
	}
}

void GetLeaseNum(int *input,int n,int *output,int k){
	if(input == nullptr || output == nullptr || k>n || n<=0 || k<=0)
		return ;

	int start = 0;
	int end = n-1;
	int index = partition(input,n,start,end);
	while(index != k-1){
		if(index > k-1){
			end = index-1;
			index = partition(input,n,start,end);
		}else{
			satrt = index+1;
			index = partition(input,n,start,end);
		}
	}
	for(int i = 0;i<k;++i)
		output[i] = input[i];
}

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> res;
	vector<int> vec;

	int start = 1;
	int end = 2;
	int cur = start+end;
	int mid = sum/2;

	while(start<mid && end < sum){
		while(cur > sum){
			cur -= begin;
			begin++;
		}

		if(cur == sum){
			for(int i = begin;i<=end;i++){
				vec.push_back(i);
			}
			res.push_back(vec);
			vec.clear();
		}

		++end;
		cur += end;
	}
}

void preorderTraversal(TreeNode *root) {
	stack<TreeNode*> stk;
	TreeNode *node = root;
	while(node != NULL || !stk.empty()){
		while(node != NULL){
			printf("%d ",node->val);
			stk.push(node);
			node = node->left;
		}

		if(!stk.empty()){
			node = stk.pop();
			node = node->right;
		}
	} 
}

void middleorderTraversal(TreeNode *root) {
	stack<int> stk;
	TreeNode *node = root;
	while(node != NULL || stk.empty()){
		while(node != NULL){
			stk.push(node);
			node = node->left;
		}

		if(!stk.empty()){
			node = stk.pop();
			printf("%d ",node->val);
			node = node -> right;
		}
	}
}

void postorderTraversal(TreeNode *root) {
	stack<int> stk;
	TreeNode node = root;
	TreeNode lastVisit = root;
	while(node != NULL || !stk.empty()){
		while(node != NULL){
			stk.push(node);
			node = node->left;
		}

		node = stk.top();
		if(node->right == NULL || node->right == lastVisit){
			printf("%d ",node->val);
			stk.pop();
			node = NULL;
			lastVisit = node;
		}else{
			node = node->right;
		}
	}
}

int count = 0;
TreeNode* KthNode(TreeNode* pRoot, int k){
	if(pRoot){
		TreeNode *t = KthNode(pRoot->left,k);
		if(t) return t;
		if(++count == k) return pRoot;
		t = KthNode(pRoot->right,k);
		if(t) return t;
	}
	return NULL;
}

int partition(int a[], int low, int high){
	int pivot = a[log];
	while(low < high){
		while(low < high && a[high] >= pivot) --high;
		swap(&a[low],&a[high]);
		while(low < high && a[low] <= pivot) ++low;
		swap(&a[low],&a[high]);
	}
	return low;
}
void quickSort(int a[],int low,int high){
	if(low < high){
		int pivot = partition(a,low,high);
		quickSort(a,low,pivot-1);
		quickSort(a,pivot+1,high);
	}
}

void heapAdjust(int H[],int s,int lenght){
	int tmp = H[s];
	int child = 2*s+1;
	while(child < length){
		if(child+1 < length && H[child] < H[child+1])
			child++;

		if(H[s] < H[child]){
			H[s] = H[child];
			s = child;
			child = 2*s+1;
		}else{
			break;
		}

		H[s] = tmp;
	}
}
vodi BuildHeap(int H[],int length){
	for(int i = (length-1)/2;i>=0;i--){
		heapAdjust(H,i,length);
	}
}
vodi HeapAdjust(int H[],int length){
	BuildHeap(H,length);
	for(int i = length-1;i>0;i--){
		int temp = H[i];
		H[i] = H[0];
		H[0] = temp;
		HeapAdjust(H,0,i);
	}
}

vector<vector<int>> allRes;
vector<int> tmp;
vodi dfsFind(TreeNode *node,int left){
	tmp.push_back(node->val);
	if(left-node->val == 0 && !node->left && !node->right)
		allRes.push_back(tmp);
	else{
		if(node->left)
			dfsFind(node->left,left-node->val);
		if(node->right)
			dfsFind(node->right,left-node->val);
	}
	tmp.pop_back();
}
vector<vector<int>> FindPath(TreeNode *root,int expectNumber){
	if(root)
		dfsFind(root,expectNumber);
	return allRes;
}

vecotr<int> PrintFromtoBottom(TreeNode *rt){
	queue<TreeNode* > q;
	q.push(rt);
	vector<int> r;
	while(!q.empty()){
		rt = q.front();
		q.pop();
		r.push_back(rt->val);
		q.push(rt->left);
		q.push(rt->right);
	}
}

vector<vector<int>> Print(TreeNode *root){
	if(root == NULL)
		return vec;
	vector<vector<int>> vec;

	queue<TreeNode *> q;
	q.push(root);

	while(!q.empty()){
		int i = 0;
		int size = q.size();
		for(i;i<szie;i++){
			TreeNode *t = q.front();
			v.push_back(t->val);
			q.pop();
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
}

vector<vector<int>> Print(TreeNode *root){
	vector<vector<int>> res;
	if(root == NULL)
		return res;
	stack<TreeNode*> stk1;
	stack<TreeNode *> stk2;

	bool mode = true;
	while(!stk1.empty()){
		stk2 = stk1;
		stk1.clear();
		vector<int> row;

		while(!stk2.empty()){
			TreeNode *tmp = stk2.top();
			stk2.pop();
			row.push_back(tmp->val);
			if(model == true){
				if(tmp->left)
					stk1.push(tmp->left);
				if(tmp->right)
					stk2.push(tmp->right);
			}else{
				if(tmp->right)
					stk1.push(tmp->right);
				if(tmp->left)
					stk1.push(tmp->left);
			}
		}
		model = !model;
		res.push_back(row);
	}

	return res;
}


