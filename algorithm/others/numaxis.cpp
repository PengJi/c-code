#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*
 * 数轴上从左到右有n个点a[0],a[1],...,a[n-1]，给定一根长度为L的绳子，
 * 求绳子最多能覆盖其中的几个点。
 */

class Solution{
public:
    int RopeCover(vector<int> points,int len){
        int start = 1,end = 0;
        int tmpLen=1,maxLen = 1;
        int size = points.size();

        if(size < 1){
            return 0;
        }

        while(start<size || start==end){
            if(points[start] - points[end] <= len){
                tmpLen++;
                start++;
                if(tmpLen>maxLen)
                    maxLen = tmpLen;
            }else{
                tmpLen--;
                end++;
            }
        }

        return maxLen;
    }
};

int main(){
    Solution s;
    int n[] = {-1,3,4,9,11,25};
    vector<int> points(n,n+6);
    int L = 8;
    int result = s.RopeCover(points,L);

    cout << result <<endl;

    return 0;
}

//http://blog.csdn.net/sunnyyoona/article/details/43635773
    #include <iostream>
    #include <vector>
    #include <cstring>
    #include <algorithm>
    using namespace std;

    class Solution {
    public:
        // points 给定点 L 绳子长度
        int RopeCover(vector<int> points,int L) {
            int size = points.size();
            if(size <= 0){
                return 0;
            }//if
            // 所能覆盖的最多点数
            int max = 0;
            int start = 1,end = 0;
            int maxS = 0,maxE = 0;
            while(end < start){
                if(points[start] - points[end] <= L){
                    if(start - end + 1 > max){
                        max = start - end + 1;
                        maxS = end;
                        maxE = start;
                    }//if
                    // 头向前移动一格
                    ++start;
                }//if
                else{
                    // 尾巴向前移动一格
                    ++end;
                }
            }//while
            cout<<"起点->"<<maxS<<" 终点->"<<maxE<<endl;
            return max;
        }
    };

    int main(){
        Solution s;
        vector<int> points = {-1,3,4,9,11,25};
        int L = 8;
        int result = s.RopeCover(points,L);
        // 输出
        cout<<result<<endl;
        return 0;
    }