class Solution {
public:
    /*
     * 3. Longest Substring Without Repeating Characters
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

    /**
     * 14. Longest Common Prefix
     * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
     */
    //从位置0开始，对每一个位置比较所有字符串，直到遇到一个不匹配
    //纵向扫描，从位置0开始，对每一个位置比较所欲字符串，直到遇到一个不匹配
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        for(int idx=0; idx<strs[0].size(); ++idx){ //纵向扫描
            for(int i=1; i<strs.size(); ++i){
                if(strs[i][idx] != strs[0][idx])
                    return strs[0].substr(0,idx);
            }
        }

        return strs[0];
    }
    //横向扫描，每个字符串与地0个字符串，从左到右比较，直到遇到一个不匹配
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty())
            return "";

        int right_most = strs[0].size()-1;
        for(size_t i=1; i<strs.size(); i++)
            for(int j=0; j<=right_most; j++)
                if(strs[i][j] != strs[0][j])
                    right_most = j-1;

        return strs[0].substr(0, right_most+1);
    }

    /**
     * 28. Implement strStr()
     * Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
     */
    //暴力破解
    //还有KMP算法，Boyer-Mooer算法和Rabin-karp算法
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;

        const int N = haystack.size() - needle.size()+1;
        for(int i=0; i<N; i++){
            int j=i;
            int k=0;
            while(j<haystack.size() && k<needle.size() && haystack[j] == needle[k]){
                j++;
                k++;
            }
            if(k==needle.size())
                return i;
        }

        return -1;
    }
    //KMP
    int strStr(string haystack, string needle){
        return kmp(haystack.c_str(), needle.c_str());
    }
    //计算部分匹配表，即next数组，pattern模式串
    static void compute_prefix(const char *pattern, int next[]){
        int i;
        int j = -1;
        const int m = strlen(pattern);

        next[0] = j;
        for(i=1; i<m; i++){
            while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];

            if (pattern[i] == pattern[j + 1]) j++;
            next[i] = j;
        }
    }
    static int kmp(const char *text, const char *pattern){
        int i;
        int j=-1;

        const int n = strlen(text);
        const int m = strlen(pattern);
        if(n==0 && m==0)
            return 0;
        if(m==0)
            return 0;
        int *next = (int*) malloc(sizeof(int) * m);

        compute_prefix(pattern,next);

        for(i=0; i<n; i++){
            while (j > -1 && pattern[j + 1] != text[i]) j = next[j];

            if (text[i] == pattern[j + 1]) j++;
            if(j == m-1){
                free(next);
                return i-j;
            }  
            
        }

        free(next);
        return -1;
    }

    /**
     * 38. Count and Say
     * The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
     */
    string countAndSay(int n) {
        string s("1");

        while(--n)
            s = getNext(s);

        return s;
    }
    string getNext(const string &s){
        stringstream ss;
        for(auto i=s.begin(); i!=s.end();){
            auto j=find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss<<distance(i,j)<<*i;
            i=j;
        }

        return ss.str();
    }

    /**
     * 125. Valid Palindrome
     * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
     */
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while(left<right){
            if (!::isalnum(*left)) 
                ++left;
            else if (!::isalnum(*right)) 
                --right;
            else if (*left != *right) 
                return false;
            else{
                left++, right--;
            }
        }
        return true;
    }

};