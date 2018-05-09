/**
 * 字符串
 */
class Solution {
public:
    /*
     * 3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

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
     * 8. String to Integer (atoi)
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
     */
    int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;

        while(str[i] == ' ' && i<n)
            i++;

        if(str[i] == '+'){
            i++;
        }else if(str[i] == '-'){
            sign = -1;
            i++
        }

        for(; i<n; i++){
            if(str[i]<'0' || str[i]>'9')
                break;
            if(num > INT_MAX/10 || (num == INT_MAX/10 && (str[i]-'0')>INT_MAX%10)){
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            num = num * 10 + str[i]-'0';
        }

        return num * sign;
    }

    /**
     * 10. Regular Expression Matching
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
     */
    //递归版
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char *s, const char *p){
        if(*p == '\0')
            return *s = '\0';

        //next char is not '*', then must match current character
        if(*(p+1) != '*'){
            if(*p == *s || (*p == '.' && *s != '\0'))
                return isMatch(s+1, p+1);
            else 
                return false;
        }else{ //next char is '*'
            while(*p == *s || (*p == '.' && *s != '\0')){
                if(isMatch(s,p+2))
                    return true;

                s++;
            }

            return isMatch(s, p+2);
        }
    }

    /**
     * 12. Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. The same principle applies to the number nine, 
which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
     */
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
            "IX", "V", "IV", "I"};

        string roman;
        for(size_t i = 0; num>0; ++i){
            int count = num / radix[i];
            num %= radix[i];
            for(; count>0; --count)
                roman += symbol[i];
        }
        return roman;
    }

    /**
     * 13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number etwenty sevn is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
     */
    //从前往后扫描，用一个临时变量记录分段数字。
    //如果当前比前一个大，说明这一段的值应该是当前值减去一个值。
    //比如：IV = 5-1; 
    //否则，将当前值加入到结果中，然后开始下一段记录。
    //比如：VI = 5+1， II=1+1;
    inline int map(const char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for(size_t i = 0; i<s.size(); i++){
            if(i>0 && map(s[i]) > map(s[i-1])){
                result += (map(s[i]) - 2*map(s[i-1]));
            }else{
                result += map(s[i]);
            }
        }

        return result;
    }

    /**
     * 14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

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
Implement strStr().

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
The count-and-say sequence is the sequence of integers with the first five terms as following:
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
     * 49. Group Anagrams
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
     */
    //回文构词法实质打乱字母顺序从而得到新的单词
    //回文构词法有一个特点：单词里的字母的种类和数目没有改变，
    //只是改变了字母的排列顺序，因此，将几个单词按照字幕顺序排序后，若它们相等，则它们属于同一组anagrams。
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> result;
        map<string, int> test;
        int nums = strs.size();

        for(int i=0; i<nums; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(test.count(temp) == 0){
                test[temp] = result.size();
                vector<string> v;
                v.push_back(strs[i]);
                result.push_back(v);
            }else{
                result[test[temp]].push_back(strs[i]);
            }
        }

        return result;
    }

    /**
     * 44. Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false
     */
    //主要是'*'的匹配问题，p没遇到过一个'*'，就保留当前'*'的坐标和s的坐标，
    //然后s从前往后扫描，如果不成功，则s++，重新扫描
    //递归版（超时）
    bool isMatch(string s, string p){
        return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char *s, const char *p){
        if(*p == '*'){
            while(*p == '*')
                ++p; //skip continuous '*'
            if(*p == '\0')
                return true;
            while(*s != '\0' && !isMatch(s,p))
                ++s;

            return *s != '\0';
        }else if(*p == '\0' || *s == '\0'){
            return *p == *s;
        }else if(*p == *s || *p =='?'){
            return isMatch(++s, ++p);
        }else
            return false;
    }
    //迭代版
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char *s, const char *p){
        bool star = false;
        const char *str, *ptr;
        for(str=s, ptr=p; *str != '\0'; str++, ptr++){
            switch(*ptr){
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while(*p == '*')
                        p++; //skip continuous '*'
                    if(*p == '\0')
                        return true;
                    str = s-1;
                    ptr = p-1;
                    break;
                default:
                    if(*str != *ptr){
                        if(!star)
                            return false;
                        s++;
                        str = s-1;
                        ptr = p-1;
                    }
            }
        }

        while(*ptr == '*')
            ptr++;
        return (*ptr == '\0');
    }

    /**
     * 65. Valid Number
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. 
If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

Solution:
http://www.cnblogs.com/grandyang/p/4084408.html
     */
    bool isNumber(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        bool eExisted = false;
        bool dotExisted = false;
        bool digitExisited = false;
        // Delete spaces in the front and end of string
        while (s[left] == ' ') ++left;
        while (s[right] == ' ') --right;
        // If only have one char and not digit, return false
        if (left >= right && (s[left] < '0' || s[left] > '9')) return false;
        //Process the first char
        if (s[left] == '.') dotExisted = true;
        else if (s[left] >= '0' && s[left] <= '9') digitExisited = true;
        else if (s[left] != '+' && s[left] != '-') return false;
        // Process the middle chars
        for (int i = left + 1; i <= right - 1; ++i) {
            if (s[i] >= '0' && s[i] <= '9') digitExisited = true;
            else if (s[i] == 'e' || s[i] == 'E') { // e/E cannot follow +/-, must follow a digit
                if (!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisited) eExisted = true;
                else return false;
            } else if (s[i] == '+' || s[i] == '-') { // +/- can only follow e/E
                if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;                
            } else if (s[i] == '.') { // dot can only occur once and cannot occur after e/E
                if (!dotExisted && !eExisted) dotExisted = true;
                else return false;
            } else return false;
        }
        // Process the last char, it can only be digit or dot, when is dot, there should be no dot and e/E before and must follow a digit
        if (s[right] >= '0' && s[right] <= '9') return true;
        else if (s[right] == '.' && !dotExisted && !eExisted && digitExisited) return true;
        else return false;
    }

    /**
     * 67. Add Binary
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
     */
    string addBinary(string a, string b) {
        string result;
        const size_t n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for(size_t i=0; i<n; i++){
            const int ai = i < a.size() ? a[i] - '0' : 0;
            const int bi = i < b.size() ? b[i] - '0' : 0;
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val+'0');
        }

        if(carry == 1){
            result.insert(result.begin(), '1');
        }

        return result;
    }

    /**
     * 71. Simplify Path
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
     */
    string simplifyPath(string path) {
        vector<string> dirs;

        for(auto i=path.begin(); i!=path.end();){
            ++i;

            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);

            if(!dir.empty() && dir != "."){
                if(dir == ".."){
                    if(!dir.empty()){
                        dirs.pop_back();
                    }
                }else{
                    dirs.push_back(dir);
                }
            }
            i=j;
        }

        stringstream out;
        if(dirs.empty()){
            out << "/";
        }else{
            for(auto dir : dirs)
                out<<'/'<<dir;
        }

        return out.str();
    }

    /**
     * 125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

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