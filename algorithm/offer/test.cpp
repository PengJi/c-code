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