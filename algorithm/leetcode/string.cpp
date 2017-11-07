class Solution {
public:
    /*
     * 3. 
     * Longest Substring Without Repeating Characters
     * Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
     */
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1); //存储字符串元素的下标
        int maxLen = 0, start = -1;
        for(int i=0;i != s.length(); i++){
            if(dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }

    /*
     * 5. 
     * Longest Palindromic Substring
     * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

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
     */
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        vector<vector<bool> > dp(n,vector<bool>(n,0));
        
        for(int i = n-1; i>=0; i--){
            for(int j=i;j<n;j++){
                dp[i][j] = s[i]==s[j] && (j-i<3 || dp[i+1][j-1]);
                
                if(dp[i][j] && (res.empty() || j-i+1>res.size())){
                    res = s.substr(i,j);
                }
            }
        }
        
        return res;
    }

    string longestPalindrome(string s) {
        if(s.size()<=1) return s; 
        int start = 0, maxLen = 1, n = s.size();
        bool isPal[1000][1000] = {false};
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]) {
                    isPal[i][j] = true;
                    if(j-i+1>maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};