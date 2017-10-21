class Solution {
public:
	/*
	 * 132. 
	 * Palindrome Partitioning II
	 *
	 * Given a string s, partition s such that every substring of the partition is a palindrome.
	 * 
	 * Return the minimum cuts needed for a palindrome partitioning of s.
	 *
	 * For example, given s = "aab",
	 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
	 */
    int minCut(string s) {
    }

    int minCut(string s)
    {
        int len = s.length();
        vector<int> minCuts(len+1);
        for(int i=0;i<=len;i++)
           minCuts[i] = i-1;
         bool dp[len][len];
        fill_n(&dp[0][0],len*len,false);
        for(int j=1;j<len;j++)
        {
            for(int i=j;i>=0;i--)
            {
                if(s[i] == s[j] && (dp[i+1][j-1] || (j-i)<2))
                {
                   dp[i][j] = true;
                   minCuts[j+1] = min(minCuts[j+1],1+minCuts[i]);
                }   
            }
        }
       return minCuts[len];
    }
};