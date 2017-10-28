class Solution {
public:
	/*
	 * 132. 
	 * Palindrome Partitioning II
	 *
	 * Given a string s, partition s such that every substring of the partition is a palindrome.
	 * Return the minimum cuts needed for a palindrome partitioning of s.
	 * For example, given s = "aab",
	 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
	 *
	 * Calculate and maintain 2 DP states:
	 * pal[i][j] , which is whether s[i..j] forms a pal
	 * d[i], which is the minCut for s[i..n-1]
	 * Once we comes to a pal[i][j]==true:
	 * 
	 * if j==n-1, the string s[i..n-1] is a Pal, minCut is 0, d[i]=0;
	 * else: the current cut num (first cut s[i..j] and then cut the rest
	 * s[j+1...n-1]) is 1+d[j+1], compare it to the exisiting minCut num
	 * d[i], repalce if smaller.
	 */
	int minCut(string s){
		if(s.empty())
			return 0;
		int n = s.size();
		vector<vector<bool>> pal(n,vector<bool>(n,false));
		vector<int> d(n);

		for(int i=n-1;i>=0;i--){
			d[i] = n-i-1;
			for(int j=i;j<n;j++){
				if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1])){
					pal[i][j]=true;
					if(j==n-1)
						d[i]=0;
					else if(d[j+1]+1<d[i])
						d[i]=d[j+1]+1;
				}
			}
		}
		return d[0];
	}

		/*
	 * 221. 
	 * Maximal Square
	 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

	 * https://leetcode.com/problems/maximal-square/discuss/
	 */
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
        	return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(m+1,0);
        int maxsize = 0, pre = 0;
        for(int j = 0;j<n;j++){
        	for(int i = 1;i<=m;i++){
        		int temp = dp[i];
        		if(matrix[i-1][j] == '1'){
        			dp[i] = min(dp[i],min(dp[i-1],pre)) + 1;
        			maxsize = max(maxsize,dp[i]);
        		}else
        			dp[i] = 0;
        		pre = temp;
        	}
        }
        return maxsize * maxsize;
    }
};