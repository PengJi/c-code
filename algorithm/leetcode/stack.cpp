/**
 * 栈和队列
 */
class Solution {
public:
    /**
     * 20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
     */
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for(auto c : s){
            if(left.find(c) != string::npos){
                stk.push(c);
            }else{
                if(stk.empty() || stk.top() != left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }

        return stk.empty();
    }

    /**
     * 32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
     */
    int longestValidParentheses(string s) {
        int max_len = 0, last = -1; //the position of the last ')'
        stack<int> lefts; //keep track of the positions of non-matching '('

        for(int i = 0; i<s.size(); ++i){
            if(s[i] == '('){
                lefts.push(i);
            }else{
                if(lefts.empty()){
                    //no matching left
                    last = i; 
                }else{
                    //find a matching pair
                    lefts.pop();
                    if(lefts.empty()){
                        max_len = max(max_len, i-last);
                    }else{
                        max_len = max(max_len,i-lefts.top());
                    }
                }
            }
        }

        return max_len;
    }

    /**
     * 84. Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height 
where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:
Input: [2,1,5,6,2,3]
Output: 10
     */
    //对于每个柱子，左右扩展，知道碰到比自己矮的，计算这个矩形的面积，用一个变量记录最大的面积，复杂度O(n2)
    //如图所示，从左道友处理直方，当i=4时，小于当前栈顶（即直方3），对于直方3，无论后面还是前面的直方，
    //都不可能得到比目前栈顶元素更高的高度了，处理掉直方3（计算从直方3到直方4之间的矩形的面积，然后从栈里弹出）；
    //对于直方2也是如此，知道碰到比直方4更矮的直方1。
    //这意味着，可以维护一个递增的栈，每次比较栈顶与当前的元素。如果当前元素大于栈顶元素，则入栈，
    //否则合并现有栈，直至栈顶元素小于当前元素。
    //结尾时入栈元素0，重复合并一次。
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int result = 0;
        for(int i=0; i<heights.size(); ){
            if(s.empty() || heights[i] > heights[s.top()])
                s.push(i++);
            else{
                int tmp = s.top();
                s.pop();
                result = max(result, heights[tmp]*(s.empty()? i : i-s.top()-1));
            }
        }

        return result;
    }

	/*
	 * 150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
	 */
    int evalRPN(vector<string>& tokens) {
        int a,b;
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
        	if(tokens[i]=="+"){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                stk.push(a+b);
        	}else if(tokens[i] == "/"){
        		b = stk.top();
                stk.pop();
        		a = stk.top();
                stk.pop();
        		stk.push(a/b);
        	}else if(tokens[i] == "*"){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                stk.push(a*b);
        	}else if(tokens[i] == "-"){
        		b = stk.top();
                stk.pop();
        		a = stk.top();
                stk.pop();
        		stk.push(a-b);
        	}else{
        		stk.push(stoi(tokens[i]));
        	}
        }
        return stk.top();
    }
};