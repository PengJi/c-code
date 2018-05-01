#include <iostream>
#include <cstdio>

using namespace std;

class Solution{
public:
	/**
	 * 57-1. 和为S的两个数字
	 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
	 * 是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
	 */
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		int size = array.size();
        int first = 0,second = size-1;
        vector<int> vec;

        if(size < 1 || sum < 0)
        	return vec;

        while(first < second){
        	if(array[first] + array[second] < sum)
        		first++;
        	else if(array[first] + array[second] > sum)
        		second--;
        	else{
        		vec.push_back(array[first]);
        		vec.push_back(array[second]);
        		break;
        	}
        }

        return vec;
    }

    /*
     * 57-2. 和为S的连续正数序列
     * 输入一个整数S，打印出所有和为S的连续正数序列（至少含有两个数），
     * 例如，输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以打印出3个连续序列
     * 1-5、4-6、7-8
     */
    vector<vector<int> > FindContinuousSequence(int sum) {
    	int start=1,end=2;
    	int cur = start+end;
    	int mid = (1+sum)/2;
    	vector<vector<int>> res;

    	if(sum < 3)
    		return res;

    	while(start < mid && end < sum){
    		if(cur < sum){
    			end++;
    			cur += end;
    		}else if(cur > sum){
    			cur -= start;
    			start++;
    		}else{
    			vector<int> vec;
    			for(int i = start;i<=end;++i){
    				vec.push_back(i);
    			}
    			res.push_back(vec);
                
                //扩大范围
                end++;
                cur += end;
    		}
    	}
        
        return res;
    }
    //offer
    vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> vec;
		vector<int> res;
		if(sum < 3)
			return vec;

		int mid = (1+sum)/2;
		int begin = 1;
		int end = 2;
		int cur = begin+end;

		while(begin<mid && end < sum){
			while(cur > sum){
				cur -= begin;
				begin++;
			}
            
			if(cur == sum){
				for(int i = begin;i<=end;i++)
					res.push_back(i);
				vec.push_back(res);
				res.clear();
			}
			end++;
			cur += end;
		}

		return vec;
    }
}