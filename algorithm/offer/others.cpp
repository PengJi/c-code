class Solution{
public:
	/*
	 * 65
	 *  不用加减乘除做加法
	 * 写一个函数，求两个整数之和，
	 * 要求在函数体内不得使用+、-、*、/四则运算符号。
	 */
	int Add(int num1, int num2)
    {
    	int sum,carry;
    	do{
    		sum = num1 ^ num2;
    		carry = (num1 & num2) << 1;
    		num1 = sum;
    		num2 = carry;
    	}while(num2 != 0);

    	return sum;
    }

    /*
     * 64
     * 求1+2+3+...+n
     * 求1+2+3+...+n，要求不能使用乘除法、
     * for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
     *
     * 利用构造函数
     */
    class Temp{
    public:
    	Temp(){++N;Sum += N;}

    	static void Reset(){N=0;Sum = 0;}
    	static unsigned int GetSum(){return Sum;}
    private:
    	static unsigned int N;
    	static unsigned int Sum;
    };

    unsigned int Temp::N = 0;
    unsigned int Temp::Sum = 0;

    int Sum_Solution(int n) {
    	Temp::Reset();

        Temp *a = new Temp[n];

        delete[] a;
        a = NULL;

        return Temp::GetSum();
    }
    
    /*
     * 40
     * 最小的k个数
     * 输入n个整数，找出其中最小的K个数。
     * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
     *
     * 通过红黑树
     */
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		multiset<int, greater<int>> leastNumbers;
		multiset<int, greater<int>>::iterator setIterator;

		leastNumbers.clear();

		if(k < 1 || input.size() < k)
			return vector<int>();

		vector<int>::const_iterator iter = input.begin();
		for(;iter != input.end(); ++iter){
			if(leastNumbers.size() < k)
				leastNumbers.insert(*iter);
			else
			{
				setIterator = leastNumbers.begin();

				if(*iter < *(leastNumbers.begin())){
					leastNumbers.erase(setIterator);
					leastNumbers.insert(*iter);
				}
			}
		}
		vector<int> a(leastNumbers.begin(),leastNumbers.end());
		return a;
    }

    /*
     * 43
     * 整数中1的出现次数(从1到n整数中1出现的次数)
     * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
     * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
     * 但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
     * 可以很快的求出任意非负整数区间中1出现的次数。
     */
	int NumberOf1Between1AndN_Solution(int n)
    {   
//主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析 
//根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i 
     
//当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1 
     
//当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1 
     
//当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30） 
     
//综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1 
     
//之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
		int count=0; 
		long long i=1; 
		for(i=1;i<=n;i*=10) { 
          //i表示当前分析的是哪一个数位 
			int a = n/i,b = n%i; 
			count=count+(a+8)/10*i+(a%10==1)*(b+1); 
		} 
		return count;   	
    }
};