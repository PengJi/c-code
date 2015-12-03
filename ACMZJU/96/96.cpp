//����������

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
	int n;//�༶����
	int c;//�γ�����
	double xf;//ѧ��
	vector<double> vxf;//ѧ������
	int p;//�༶����
	string name;//����
	double score;//�ɼ�
	student xs;
	vector<student> vxs;
	cin>>n;//n����
	for(int i=0;i<n;i++)//����ÿ����
	{
		cin>>c;//����γ�����
		for(int j=0;j<c;j++){
			cin>>xf;
			vxf.push_back(xf);
		}
		cin>>p;//�༶����
		for(int k=0;k<p;k++){
			cin>>name;
			xs.s=name;
			xf=0.0;
			for(int m=0;m<c;m++){
				cin>>score;
				if(score<60)
					continue;
				xf=xf+(score-50)/10*vxf[m];//������ѧ��
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