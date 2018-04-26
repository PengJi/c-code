/**
 * 细节实现题
 * 不同特定算法，考察代码熟练 程度
 */
class Solution{
public:
	/**
	 * 7. Reverse Integer
	 * Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer 
range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
	 */
	//考虑 1. 负数的情况 2. 溢出的情况 (正溢出 && 负移除 x = -2147483648(即-2^31) )
	int reverse(int x){
		long long r=0;
		long long t=x;
		t = t>0?t:-t;

		for(;t;t/=10)
			r = r*10 + t%10;

		bool sign = x>0?false:true;
		if(r>2147483647 || (sign && r>2147483648)){
			return 0;
		}else{
			if(sign)
				return -r;
			else
				return r;
		}
	}

	/**
	 * 9. Palindrome Number
	 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
	 */
	//不断地区第一位和最后一位进行比较，相等则取第二位和倒数第二位，知道完成比较或者找到了不一致的位
	bool isPalindrome(int x){
		if(x<0)
			return false;

		int d=1;
		while(x/d >= 10)
			d *= 10;

		while(x>0){
			int q = x/d;
			int r = x%10;
			if(q != r)
				return false;
			x = x%d/10;
			d /= 100;
		}

		return true;
	}

	/**
	 * 50. Pow(x, n)
	 * 
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
	 */
	//二分法，$x^n = x^{n/2} * x^{n/2} * x^{n\%2}$
	double myPow(double x, int n){
		if(n<0)
			return 1.0/power(x,-n);
		else
			return power(x,n);
	}
	double power(double x, int n){
		if(n==0)
			return 1;

		double v = power(x,n/2);

		if(n%2 == 0)
			return v*v;
		else 
			return v*v*x;
	}

	/**
	 * 54. Spiral Matrix
	 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
	 */
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if(matrix.empty())
			return result;

		int beginX=0, endX=matrix[0].size()-1;
		int beginY=0, endY=matrix.size()-1;

		while(true){
			//from left to right
			for(int j=beginX; j<=endX; ++j)
				result.push_back(matrix[beginY][j]);
			if(++beginY > endY)
				break;
			//from top to bottom
			for(int i=beginY; i<=endY; ++i)
				result.push_back(matrix[i][endX]);
			if(beginX > --endX)
				break;
			//from right to left
			for(int j=endX; j>=beginX; --j)
				result.push_back(matrix[endY][j]);
			if(beginY > --endY)
				break;
			//from bottom to top
			for(int i=endY; i>=beginY; --i)
				result.push_back(matrix[i][beginX]);
			if(++beginX > endX)
				break;
		}

		return result;
	}

	/**
	 * 57. Insert Interval
	 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
	 */
	/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval>::iterator it = intervals.begin();

		while(it != intervals.end()){
			if(newInterval.end < it->start){
				intervals.insert(it, newInterval);
				return intervals;
			}else if(newInterval.start > it->end){
				it++;
				continue;
			}else{
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}

		intervals.insert(intervals.end(), newInterval);
		return intervals;
	}

	/**
	 * 59. Spiral Matrix II
	 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
	 */
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n));
		int begin=0, end=n-1;
		int num=1;

		while(begin<end){
			for(int j=begin; j<end; ++j)
				matrix[begin][j] = num++;
			for(int i=begin; i<end; ++i)
				matrix[i][end] = num++;
			for(int j=end; j>begin; --j)
				matrix[end][j] = num++;
			for(int i=end; i>begin; --i)
				matrix[i][begin] = num++;
			++begin;
			--end;
		}

		if(begin == end)
			matrix[begin][begin]=num;

		return matrix;
	}
	vector<vector<int>> generateMatrix(int n){
		vector<vector<int>> matrix(n, vector<int>(n));
		if(n==0)
			return matrix;
		int beginX=0, endX=n-1;
		int beginY=0, endY=n-1;
		int num=1;

		while(true){
			for(int j=beginX; j<=endX; ++j)
				matrix[beginY][j] = num++;
			if(++beginY > endY)
				break;
			for(int i=beginY; i<=endY; ++i)
				matrix[i][endX] = num++;
			if(beginX > --endX)
				break;
			for(int j=endX; j>=beginX; --j)
				matrix[endY][j] = num++;
			if(beginY > --endY)
				break;
			for(int i=endY; i>=beginY; --i)
				matrix[i][beginX] = num++;
			if(++beginX > endX)
				break;
		}

		return matrix;
	}

	/**
	 * 78. Subsets
	 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
	 */
	vector<vector<int>> subsets(vector<int> &nums){
		sort(nums.begin(), nums.end());
		int elem_num = nums.size();
		int subset_num = pow(2,elem_num);
		vector<vector<int>> subset_set(subset_num, vector<int>());
		for(int i=0; i<elem_num; i++)
			for(int j=0; j<subset_num; j++)
				if((j >> i) & 1)
					subset_set[j].push_back(nums[i]);

		return subset_set;
	}

	/**
	 * 118. Pascal's Triangle
	 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
	 */
	//可以用队列，计算下一行时，给上一行左右各加一个0，然后下一行的每个元素，就等于左上角和右上角之和。
	//另一种思路，下一行的第一个元素和最后一个元素赋值为1，中间的每个元素，等于上一行的左上角和右上角元素之和。
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;

		if(numRows == 0)
			return result;

		result.push_back(vector<int>(1,1)); //first row

		for(int i=2; i<=numRows; ++i){
			vector<int> currrent(i,1); //本行
			const vector<int> &prev = result[i-2]; //上一行

			for(int j=1; j<i-1; ++j){
				currrent[j] = prev[j-1] + prev[j]; //左上角和右上角之和
			}
			result.push_back(currrent);
		}

		return result;
	}
	//从右到左
	vector<vector<int>> generate(int numRows){
		vector<vector<int>> result;
		vector<int> array;

		for(int i=1; i<=numRows; i++){
			for(int j=i-2; j>0; j--){
				array[j] = array[j-1] + array[j];
			}
			array.push_back(1);
			result.push_back(array);
		}

		return result;
	}

	/**
	 * 119. Pascal's Triangle II
	 * 
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
	 */
	//滚动数组
	vector<int> getRow(int rowIndex){
		vector<int> array;

		for(int i=0; i<=rowIndex; i++){
			for(int j=i-1; j>0; j--)
				array[j] = array[j-1] + array[j];
			array.push_back(1);
		}

		return array;
	}

	/**
	 * 152. Maximum Product Subarray
	 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
	 */
	int maxProduct(vector<int> &nums){
		int n = nums.size();

		if(n==1)
			return nums[0];

		int pMax=0, nMax=0, m=0;

		for(int i=0; i<n; i++){
			if(nums[i]<0)
				swap(pMax, nMax);

			pMax = max(pMax*nums[i], nums[i]);
			nMax = min(nMax*nums[i], nums[i]);
			m = max(m, pMax);
		}

		return m;
	}
	
}