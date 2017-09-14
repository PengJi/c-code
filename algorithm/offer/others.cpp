class Solution{
public:
	/**
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

    /**
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
    
    /**
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

    /**
     * 43
     * 整数中1的出现次数(从1到n整数中1出现的次数)
     * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
     * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
     * 但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
     * 可以很快的求出任意非负整数区间中1出现的次数。
     *
     * 主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析 
     * 根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i 
     * 当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1 
     * 当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1 
     * 当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30） 
     * 综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1 
     * 之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
     */
	int NumberOf1Between1AndN_Solution(int n)
    {   
		int count=0; 
		long long i=1; 
		for(i=1;i<=n;i*=10) { 
          //i表示当前分析的是哪一个数位 
			int a = n/i,b = n%i; 
			count=count+(a+8)/10*i+(a%10==1)*(b+1); 
		} 
		return count;   	
    }

    /**
     * 57
     * 和为S的连续正数序列
     * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,
     * 他马上就写出了正确答案是100。但是他并不满足于此,
     * 他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
     * 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
     * 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
     *
     * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，
     * 序列间按照开始数字从小到大的顺序
     *
     * 思路：
	 * 用两个数字begin和end分别表示序列的最大值和最小值，
	 * 首先将begin初始化为1，end初始化为2.
	 * 如果从begin到end的和大于s，我们就从序列中去掉较小的值(即增大begin),
	 * 相反，只需要增大end。
	 * 终止条件为：一直增加begin到(1+sum)/2并且end小于sum为止
     */
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> vec;
		vector<int> res;
		if(sum < 3)
			return vec;

		int mid = (1+sum)/2;
		int begin = 1;
		int end = 2;
		int cur = begin+end;

		while(begin<mid && end < sum){
			while(cur > sum){
				cur -= begin;
				begin++;
			}
			if(cur == sum){
				for(int i = begin;i<=end;i++)
					res.push_back(i);
				vec.push_back(res);
				res.clear();
			}
			end++;
			cur += end;
		}

		return vec;
    }

    /**
     * 57
     * 和为S的两个数字
     * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
     * 他们的和正好是S，如果有多对数字的和等于S，
     * 输出两个数的乘积最小的。
     *
     * 对应每个测试案例，输出两个数，小的先输出。
     *
	 * 数列满足递增，设两个头尾两个指针i和j， 
	 * 若ai + aj == sum，就是答案（相差越远乘积越小） 
  	 * 若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1 
  	 * 若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
     */
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int n = array.size();
        int i = 0, j = n-1;
        while(i < j){
        	if(array[i] + array[j] == sum){
        		res.push_back(array[i]);
        		res.push_back(array[j]);
        		break;
        	}
        	while(i<j && array[i]+array[j] > sum) --j;
        	while(i<j && array[i]+array[j] < sum) ++i;
        }
        return res;
    }    

    /**
     * 翻转单词顺序咧
     * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
     * 为简单起见，标点符号和普通字母一样处理。
     * 如理输入字符串"I am a student."则输出"student. a am I"
     */
	string ReverseSentence(string str) {
        string res = "",tmp = "";
        for(int i = 0;i<int(str.size());++i){
        	if(str[i] == ' '){
        		res = " " + tmp + res;
        		tmp = "";
        	}else{
        		tmp += str[i];
        	}
        }
        if(tmp.size())
        	res = tmp+res;
        
        return res;
    }
};