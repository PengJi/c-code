//按绩点排名

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct student{
	string s;
	double d;
};

bool Comp(const student &s1,const student &s2){
	if(s1.d != s2.d)
		return s1.d>s2.d;
	if(s1.s != s2.s)
		return s1.s<s2.s;
}

int main(){
	int n;//班级数量
	int c;//课程数量
	double xf;//学分
	vector<double> vxf;//学分向量
	int p;//班级人数
	string name;//姓名
	double score;//成绩
	student xs;
	vector<student> vxs;
	cin>>n;//n个班
	for(int i=0;i<n;i++)//处理每个班
	{
		cin>>c;//读入课程数量
		for(int j=0;j<c;j++){
			cin>>xf;
			vxf.push_back(xf);
		}
		cin>>p;//班级人数
		for(int k=0;k<p;k++){
			cin>>name;
			xs.s=name;
			xf=0.0;
			for(int m=0;m<c;m++){
				cin>>score;
				if(score<60)
					continue;
				xf=xf+(score-50)/10*vxf[m];//计算总学分
			}
			xs.d = xf/10;
			vxs.push_back(xs);
		}
		cout<<(i?"\n":"");
		cout<<"class "<<i+1<<":"<<endl;
		sort(vxs.begin(),vxs.end(),Comp);
		for(vector<student>::iterator it = vxs.begin();it<vxs.end();it++){
			cout<<fixed<<setprecision(2);
			cout<<left<<setw(11);
			cout<<(*it).s<<(*it).d<<endl;
		}
		vxf.clear();
		vxs.clear();
	}
	return 0;
}