class Solution {
public:
	/**
	 * 62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28

problem:
https://leetcode.com/problems/unique-paths/description/
	 */
	//深搜,小集合可以过，大集合超时
	int uniquePaths(int m, int n) {
		if(m < 1 || n<1) return 0; //终止条件

		if(m==1 && n==1) return 1; //收敛条件

		return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }

    //备忘录法，对前面的深搜加缓存
    int uniquePaths(int m, int n){
    	f = vector<vector<int>> (m, vector<int>(n, 0)); //f[x][y]表示从(0,0)到(x,y)的路径条数
    	f[0][0] = 1;
    	return dfs(m-1, n-1);
    }
    vector<vector<int>> f; //缓存
    int dfs(int x, int y){
    	if(x<0 || y<0) return 0;

    	if(x==0 && y==0) return f[0][0]; 

    	if(f[x][y] > 0){
    		return f[x][y];
    	}else{
    		return f[x][y] = dfs(x-1,y) + dfs(x,y-1);
    	}
    }
    //动规
    int uniquePaths(int m, int n){
    	vector<int> f(n, 0);
    	f[0] = 1;
    }

	/**
	 * 131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:
Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

problem:
https://leetcode.com/problems/palindrome-partitioning/description/

solution:
https://leetcode.com/problems/palindrome-partitioning/discuss/41964/Clean-C++-backtracking-solution
	 */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;

        vector<string> path; //一种partition方案
        dfs(0, s, path, res);

        return res;
    }
    void dfs(int index, string &s, vector<string>& path, vector<vector<string>> &res){
    	if(index == s.size()){
    		res.push_back(path);
    		return;
    	}
    	for(int i=index; i<s.size(); ++i){
    		if(isPalindrome(s, index, i)){
    			path.push_back(s.substr(index, i-index+1));
    			dfs(i+1, s, path, res); //继续往下搜索
    			path.pop_back(); //撤销上上行
    		}
    	}
    }
    bool isPalindrome(const string& s, int start, int end){
    	while(start <= end){
    		if(s[start++] != s[end--])
    			return false;
    	}

    	return true;
    }
};