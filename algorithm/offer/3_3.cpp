#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution{
public:
	/**
	 * 16
	 * 数值的整数次方
	 * 实现函数 double Power(double base, int exponent)，求 base 的 exponent 次方，
	 * 不能使用库函数，同时不需要考虑大数问题
	 */
	double Power(double base, int exponent){
        long p = abs(exponent);
        double r = 1.0;
        while(p){
            if(p & 1)
                r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent<0?1/r:r;
    }
    
}