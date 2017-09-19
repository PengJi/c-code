#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int arr[] = {1,6,4,3,7,8};
	vector<int> v(arr,arr+6);
	vector<int>::iterator it;

	make_heap(v.begin(),v.end());

	cout<< "initial max heap " << v.front() << endl;

	//pop_heap()用于弹出堆中的第一个元素，并把它放到区间的最后一个位置，然后重新将前面的元素构建成一个堆。
	pop_heap(v.begin(),v.end());
	v.pop_back();
	cout<< "max heap after pop "<<v.front()<<endl;	

	v.push_back(10);
	//push_heap()用于将指定区间的最后一个元素加入堆中并使整个区间成为一个新的堆。注意前提是最后一个元素除外的所有元素已经构成一个堆。
	push_heap(v.begin(),v.end());
	cout<< "max heap after push "<<v.front()<<endl;

	sort_heap(v.begin(),v.end());

	cout<<"final sorted range:";

	for(int i = 0;i<v.size();++i)
		cout<<" "<<v[i];

	cout<<endl;

	return 0;
}
