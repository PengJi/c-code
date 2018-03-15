class Solution {
public:
    /*
    20. Valid Parentheses
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

	/*
	 * 150
	 * Evaluate Reverse Polish Notation
	 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
	 * 
	 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
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