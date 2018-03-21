class Solution {
public:
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
};