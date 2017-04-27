class Solution{
public:
	//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
	int Numberof1(int n){
		int count = 0;
		while(n){
			n &= n-1;
			count++;
		}
		return count;
	}

	//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
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
};



