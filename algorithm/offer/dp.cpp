#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>

#define MAXN 100002

using namespace std;

class Solution{
    /*
     * 连续子数组的最大和
     * HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
     * 今天测试组开完会后,他又发话了:在古老的一维模式识别中,
     * 常常需要计算连续子向量的最大和,当向量全为正数的时候,
     * 问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
     * 并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
     * 连续子向量的最大和为8(从第0个开始,到第3个为止)。
     * 你会不会被他忽悠住？(子向量的长度至少是1)
     *
     * 动态规划
     */
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        int sum = array[0],tempsum = array[0];
        for(int i = 1;i<array.size();i++){
            tempsum = (tempsum<0) ? array[i]:tempsum+array[i];
            sum = (tempsum>sum)? tempsum :sum;
        }
        return sum;
    }

    /*
     * 求解一串数字中，和最大的子串
     */
    void subMax()
    {
        freopen("in", "r", stdin);                                                      
        freopen("out", "w", stdout);                            
        int cnt;                                                    
        scanf("%d", &cnt);  
        while(cnt--) {
            int n;
            scanf("%d", &n);
            int a[MAXN]={0};
            for(int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
     
            long long int last = a[0];
            long long int ans = a[0];
     
            for (int i = 1 ; i < n ; i++ ) {
                last = (0 > last ? 0 : last) + a[i];
                ans = (ans > last ? ans : last);
            }
            printf("%lld\n", ans);
        }
    }
};





