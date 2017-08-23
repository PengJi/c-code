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
 * 求解一串数字中，和最大的子串  
 */
 
int main()
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
    return 0;
}
