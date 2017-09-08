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

/*
 * 动态规划
 */

class Solution{
    /*
     * 42
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

    /*
     * 48
     * 最长不含重复字符的子字符串
     * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
     * 假设字符串中只包含a-z的字符。
     * 例如，在字符串"arabcacfr"中，最长的不含重复字符的子字符串是"acfr"，长度是4。
     *
     * 动态规划
     */
    int longestSubstring(const string &str){
        int curLength = 0;
        int maxLength = 0;

        int *position = new int[26]; //用来存储字符上次出现的下标
        for(int i = 0;i<26;++i)
            position[i] = -1;

        for(int i = 0;i<str.length;++i){
            int prevIndex = position[str[i]-'a'];
            if(prevIndex<0 || i-prevIndex > curLength){ //之前没有出现过或者之前出现过但不在当前curLength
                ++curLength;
            }else{ //之前出现过也在curLength
                if(curLength>maxLength)
                    maxLength = curLength;
                curLength = i-prevIndex;
            }
            position[str[i]-'a'] = i;
        }

        if(curLength>maxLength)
            maxLength = curLengthl;

        delete[] position;
        return maxLength;
    }
};





