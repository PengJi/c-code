#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

using namespace std;

/*
 * 数组
 */

class Solution {
public:
	/*
	 * 二维数组中的查找
	 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
	 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，
	 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
	 *
	 * 
	 */
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int rows = array.size();
        int columns = array[0].size();
        int x = 0, y = columns - 1;
        while(x >= 0 && x < rows && y >= 0 && y < columns) {
            if(array[x][y] == target) {
                return true;
            }
            if(array[x][y] > target)
                y--;
            if(array[x][y] < target)
                x++;
        }
        return false;
    }

	/*
	 * 旋转数组的最小数字
	 * 把一个数组最开始的若干个元素搬到数组的末尾，
	 * 我们称之为数组的旋转。 
	 * 输入一个非递减排序的数组的一个旋转，
	 * 输出旋转数组的最小元素。 
	 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
	 * 该数组的最小值为1。 
	 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
	 */
	int minNumberInRotateArray(std::vector<int> rotateArray){
		int size = rotateArray.size();
		if(size==0)
			return 0;
		for(int i = 0;i<size-1;i++){
			if(rotateArray[i] > rotateArray[i+1]){
				return rotateArray[i+1];
			}
		}

		return rotateArray[0];
	}

	/*
	 * 调整数组顺序使奇数位于偶数前面
	 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
	 * 使得所有的奇数位于数组的前半部分，
	 * 所有的偶数位于位于数组的后半部分，
	 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
	 */
	void reOrderArray(vector<int> &array){
		int count = array.size();
		int tmp,idx,tmp1;
		for(int i=0;i<count;i++){
			if(array[i]%2==0 && array[i+1]%2 == 1){
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				idx = i;
				while(idx-1 >= 0 && array[idx]%2 == 1 && array[idx-1]%2 == 0){
					tmp1 = array[idx-1];
					array[idx-1] = array[idx];
					array[idx] = tmp1;
					idx = idx-1;
				}
			}
		}
	}

	/*
	 * 数组中出现次数超过一半的数字
	 * 数组中有一个数字出现的次数超过数组长度的一半，
	 * 请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
	 * 于数字2在数组中出现了5次，超过数组长度的一半，
	 * 因此输出2。如果不存在则输出0。
	 */
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		if(n==0) return 0;

		int num = numbers[0],count = 1;
		for(int i=1;i<n;i++){
			if(numbers[i] == num)
				count++;
			else
				count--;
			if(count == 0){
				num = numbers[i];
				count = 1;
			}
		}

		count = 0;
		for(int i=0;i<n;i++){
			if(numbers[i] == num)
				count++;
		}
		if(count * 2 > n)
			return num;
		return 0;
    }

    /*
     * 连续子数组的最大和
     * HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
     * 今天测试组开完会后,他又发话了:在古老的一维模式识别中,
     * 常常需要计算连续子向量的最大和,当向量全为正数的时候,
     * 问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
     * 并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
     * 连续子向量的最大和为8(从第0个开始,到第3个为止)。
     * 你会不会被他忽悠住？(子向量的长度至少是1)
     *
     * 动态规划
     */
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.empty())
    		return 0;
    	int sum = array[0],tempsum = array[0];
    	for(int i = 1;i<array.size();i++){
    		tempsum = (tempsum<0) ? array[i]:tempsum+array[i];
    		sum = (tempsum>sum)? tempsum :sum;
    	}
    	return sum;
    }

    /*
     * 把数组排成最小的数
     * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
     * 打印能拼接出的所有数字中最小的一个。
     * 例如输入数组{3，32，321}，
     * 则打印出这三个数字能排成的最小数字为321323。
     *
     * 对vector容器内的数据进行排序，
     * 按照 将a和b转为string后 
     * 若 a＋b<b+a a排在在前 的规则排序, 
     * 如 2 21 因为 212 < 221 所以 排序后为 21 2 
     * to_string() 可以将int转化为string
     */
    static bool cmp(int a,int b){
    	string A,AB;
    	string B,BA;
    	char a1[10];
    	char a2[10];
    	sprintf(a1,"%d",a);
    	sprintf(a2,"%d",b);
    	A = a1;
    	B = a2;
    	AB = A+B;
    	BA = B+A;

    	return AB<BA;
    }

    static bool cmp1(int a,int b){
         string A="";
         string B="";
         A+=to_string(a);
         A+=to_string(b);
         B+=to_string(b);
         B+=to_string(a);
          
         return A<B;
     }

    string PrintMinNumber(vector<int> numbers) {
    	string ans = "";
    	sort(numbers.begin(),numbers.end(),cmp);
    	for(int i=0;i<numbers.size();i++){
    		ans += to_string(numbers[i]);
    	}
    	return ans;
    }

    /*
     * 数组中只出现一次的数字
     * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
     * 请写程序找出这两个只出现一次的数字。
     *
     * 使用异或，但是与在出现的数字中查找一个单独的数字不同的是需要
     * 利用异或结果的最低位为1的flag将数组中的数字分为两类，一类是
     * 与flag按为与为0，另一类不为0，这样在分别异或一次就能够找出这两个数。
     */
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) { 
    	if(data.size()<2) return;
    	int myxor = 0;
    	int flag = 1;
    	for(int i=0;i < data.size();++i)
    		myxor ^= data[i];
    	while((myxor & flag) == 0 ) flag <<= 1;
    	*num1 = myxor;
    	*num2 = myxor;
    	for(int i = 0;i<data.size();++i){
    		if((flag & data[i]) == 0)
    			*num2 ^= data[i];
    		else
    			*num1 ^= data[i];
    	}
    }

    /*
     * 数组中重复的数字
     * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
     * 数组中某些数字是重复的，但不知道有几个数字是重复的。
     * 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
     * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
     * 那么对应的输出是第一个重复的数字2。
     *
     * 数组里数字的范围保证在0~n-1之间，所以可以开勇现有的数组设置标志，
     * 当一个数字被访问过后，可以设置对应位上的数+n，
     * 之后再遇到相同的数时，会发现对应位撒花姑娘的数已经大于等于n了，
     * 那么直接返回这个数即可。
。   */
    // Parameters:
	//        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
    	bool[] k = new bool[length];
    	for (int i = 0; i < length; ++i)
    	{
    		if(k[numbers[i]] == true){
    			*duplication = numbers[i];
    			return true;
    		}
    		k[numbers[i]] = true;
    	}
    	return false;
    }
};