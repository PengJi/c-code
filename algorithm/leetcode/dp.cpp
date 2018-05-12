/**
 * 动态规划
 */
class Solution {
public:
    /**
     * 5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"

solution:
dp(i, j) represents whether s(i ... j) can form a palindromic substring, 
dp(i, j) is true when s(i) equals to s(j) and s(i+1 ... j-1) is a palindromic substring. 
When we found a palindrome, check if it's the longest one. Time complexity O(n^2).

Solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-longest-palindromic-substring.html
     */
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;

        int start = 0,maxLen = 1, n = s.size();
        bool isPal[1000][1000] = {false};

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]){
                    isPal[i][j] = true;
                    if(j-i+1>maxLen){
                        maxLen = j-i+1;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start,maxLen);
    }

    /**
     * 53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
     */
    //最大连续子序列和
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN, f=0;
		for(int i=0; i<nums.size(); i++){
			f = max(f+nums[i], nums[i]);
			result = max(result,f);
		}

		return result;
	}

	/**
	 * 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
	 */
	//设状态为f[i][j]，表示从起点(0,0)到达(i,j)的最小路径和，
	//则状态转移方程为:f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
	//备忘录法
    int minPathSum(vector<vector<int>>& grid) {
    	const int m = grid.size();
    	const int n = grid[0].size();
    	this->f = vector<vector<int>> (m, vector<int>(n, -1));
    	return dfs(grid, m-1, n-1);
    }
    vector<vector<int>> f; //缓存
    int dfs(const vector<vector<int>> &grid, int x, int y){
    	if(x<0 || y<0) //越界，终止条件
    		return INT_MAX;

    	if(x==0 && y==0) //回到起点，收敛条件
    		return grid[0][0];

    	return min(getOrUpdate(grid, x-1, y), getOrUpdate(grid, x, y-1))+grid[x][y];
    }
    int getOrUpdate(const vector<vector<int>> &grid, int x, int y){
    	if(x<0 || y<0)
    		return INT_MAX;
    	if(f[x][y] >= 0)
    		return f[x][y];
    	else
    		return f[x][y] = dfs(grid,x,y);
    }
    //动态规划
    int minPathSum(vector<vector<int>> &grid){
    	if(grid.size() == 0)
    		return 0;
    	const int m = grid.size();
    	const int n = grid[0].size();

    	int f[m][n];
    	f[0][0] = grid[0][0];
    	for(int i=1; i<m; i++){
    		f[i][0] = f[i-1][0] + grid[i][0];
    	}
    	for(int i=1; i<n; i++){
    		f[0][i] = f[0][i-1] + grid[0][i];
    	}

    	for(int i=1; i<m; i++){
    		for(int j=1; j<n; j++){
    			f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
    		}
    	}

    	return f[m-1][n-1];
    }
    //动态规划+滚动数组
    int minPathSum(vector<vector<int>> &grid){
    	const int m = grid.size();
    	const int n = grid[0].size();

    	int f[n];
    	fill(f, f+n, INT_MAX);
    	f[0] = 0;

    	for(int i=0; i<m; i++){
    		f[0] += grid[i][0];
    		for(int j=1; j<n; j++){
    			//左边的f[j]，表示更新后的f[j]，与公式中的f[i][j]对应
    			//右边的f[j]，表示老的f[j]，与公式中的f[i-1][j]对应
    			f[j] = min(f[j-1], f[j]) + grid[i][j];
    		}
    	}

    	return f[n-1];
    }

    /**
     * 85. Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
     */
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty())
			return 0;

		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> H(n,0);
		vector<int> L(n,0);
		vector<int> R(n,n);

		int ret = 0;
		for(int i=0; i<m; ++i){
			int left = 0, right = n;
			//calculate L(i,j) from left to right
			for(int j=0; j<n; ++j){
				if(matrix[i][j] == '1'){
					++H[j];
					L[j] = max(L[j],left);
				}else{
					left = j+1;
					H[j] = 0; L[j]=0; R[j]=n;
				}
			}

			//calculate R(i,j) from right to left
			for(int j=n-1; j>=0; --j){
				if(matrix[i][j] == '1'){
					R[j] = min(R[j],right);
					ret = max(ret, H[j]*(R[j]-L[j]));
				}else{
					right = j;
				}
			}
		}

		return ret;
	}

	/**
	 * 91. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be deodced as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
	 */
	int numDecodings(string s) {
		if(s.empty() || s[0]=='0')
			return 0;

		int prev = 0;
		int cur = 1;

		//长度为n的字符串，有n+1个阶梯
		for(size_t i=1; i<=s.size(); ++i){
			if(s[i-1] == '0')
				cur = 0;

			if(i<2 | !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
				prev = 0;

			int tmp = cur;
			cur = prev+cur;
			prev = tmp;
		}

		return cur;
	}

	/**
	 * 97. Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
	 */
	//设状态f[i][j]，表示s1[0,i]和s2[0,j], 匹配s3[0, i+j]。
	//如果s1的最后一个字符等于s3的最后一个字符，则f[i][j] = f[i-1][j]；
	//如果s2的最后一个字符等于s3的最后一个字符，则f[i][j] = f[i][j-1]。
	//状态转移方程如下：
	//f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j]) || (s2[j-1] == s3[i+j-1] && f[i][j-1])
	//动态规划
	bool isInterleave(string s1, string s2, string s3) {
		if(s3.length() != s1.length() + s2.length()){
			return false;
		}

		vector<vector<bool>> f(s1.length() + 1, vector<bool>(s2.length()+1, true));

		for(size_t i=1; i<=s1.length(); ++i){
			f[i][0] = f[i-1][0] && s1[i-1] == s3[i-1];
		}

		for(size_t i=1; i<=s2.length(); ++i){
			f[0][i] = f[0][i-1] && s2[i-1] == s3[i-1];
		}

		for(size_t i=1; i<=s1.length(); ++i){
			for(size_t j=1; j<=s2.length(); ++j){
				f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j])
					|| (s2[j-1] == s3[i+j-1] && f[i][j-1]);
			}
		}

		return f[s1.length()][s2.length()];
	}
	//动态规划+滚动数组
	bool isInterleave(string s1, string s2, string s3){
		if(s1.length() + s2.length() != s3.length())
			return false;

		if(s1.length() < s2.length())
			return isInterleave(s2, s1, s3);

		vector<bool> f(s2.length()+1, true);

		for(size_t i=1; i<=s2.length(); ++i)
			f[i] = s2[i-1] == s3[i-1] && f[i-1];

		for(size_t i=1; i<=s1.length(); ++i){
			f[0] = s1[i-1] == s3[i-1] && f[0];

			for(size_t j=1; j<=s2.length(); ++j){
				f[j] = (s1[i-1] == s3[i+j-1] && f[j])
					|| (s2[j-1] == s3[i+j-1] && f[j-1]);
			}
		}

		return f[s2.length()];
	}

    /**
     * 120. Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
     */
	int minimumTotal(vector<vector<int>>& triangle) {
		for(int i=triangle.size()-2; i>=0; --i)
			for(int j=0; j<i+1; ++j)
				triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);

		return triangle[0][0];
	}

	/**
	 * 123. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
	 */
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2)
			return 0;

		const int n = prices.size();
		vector<int> f(n,0);
		vector<int> g(n,0);

		for(int i=1, valley=prices[0]; i<n; ++i){
			valley = min(valley, prices[i]);
			f[i] = max(f[i-1], prices[i]-valley);
		}

		for(int i=n-2, peak=prices[n-1]; i>=0; --i){
			peak = max(peak, prices[i]);
			g[i] = max(g[i], peak-prices[i]);
		}

		int max_profit = 0;
		for(int i=0; i<n; ++i)
			max_profit = max(max_profit, f[i]+g[i]);

		return max_profit;
	}
	
	/*
	 * 132. 
	 * Palindrome Partitioning II
	 *
	 * Given a string s, partition s such that every substring of the partition is a palindrome.
	 * Return the minimum cuts needed for a palindrome partitioning of s.
	 * For example, given s = "aab",
	 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
	 *
	 * Solution:
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

	/**
	 * 221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

Solution:
https://leetcode.com/problems/maximal-square/discuss/
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