#include <iostream>
#include <queue>

using namespace std;

/**
 * priority_queue调用STL里面的make_heap(), pop_heap(), push_heap()算法实现
 * 是堆的另外一种形式。
 *
 * priority_queue<Type, Container, Functional>
 * Type 数据类型
 * Container 保存数据的容器
 * Functional 元素的比较方式
 *
 * Container必须使用数组实现的容器，比如 vector, deuque但不能用list
 */

struct Node{
	int x,y;
	Node(int a=0,int b=0):x(a),y(b){}
};

struct cmp{
	bool operator()(Node a,Node b){
		if(a.x == b.x)
			return a.y>b.y;

		return a.x>b.y;
	}
};

int main(){
	// 默认排序，大顶堆
	priority_queue<int> q;
	int a[]={3,5,9,6,2};
	for(int i = 0;i < 5; i++)
			q.push(a[i]);

	for(int j = 0; j < 5; j++){
		cout<<q.top()<<" ";
		q.pop();
	}

	// 小顶堆
	priority_queue<Node,vector<Node>,cmp> q2;
	for(int i = 0;i<10;i++)
		q2.push(Node(i+1,i+2));

	while(!q2.empty()){
		cout << q2.top().x << " " << q2.top().y << endl;
		q2.pop();
	}

	return 0;
}
