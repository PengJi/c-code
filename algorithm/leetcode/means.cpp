class Solution {
public:
	/**
     * 7. Reverse Integer
     * Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
     */
    //考虑 1. 负数的情况 2. 溢出的情况 (正溢出 && 负移除 x = -2147483648(即-2^31) )
	int reverse(int x) {
        long long r=0;
        long long t=x;
        t = t>0?t:-t;

        for(;t;t/=10)
        	r= r*10 + t%10;

        bool sign = x>0?false:true;
        if(r > 2147483647 || (sign && r>2147483648)){
        	return 0;
        }else{
        	if(sign)
        		return -r;
        	else
        		return r;
        }
	}

	/**
	 * 50. Pow(x, n)
	 * Implement pow(x, n).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
	 */
	//二分法，$x^n = x^{n/2} * x^{n/2} * x^{n\%2}$
    double myPow(double x, int n) {
        if(n<0)
        	return 1.0/power(x,-n);
        else 
        	return power(x,n);
    }
    double power(double x,int n){
    	if(n==0)
    		return 1;
    	double v = power(x,n/2);
    	if(n%2==0)
    		return v*v;
    	else
    		return v*v*x;
    }

    /**
     * 119. Pascal's Triangle II
     * Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
     */
    vector<int> getRow(int rowIndex) {
        
    }
    
};