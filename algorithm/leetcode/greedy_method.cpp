/**
 * 贪心算法
 */
class Solution {
public:
    /**
     * 11. Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
     */
    //每个容器的面积，取决于最短的木板
	int maxArea(vector<int>& height) {
		int start = 0;
		int end = height.size()-1;
		int result = INT_MIN;

		while(start < end){
			int area = min(height[end], height[start]) * (end-start);
			result = max(result, area);
			if(height[start] <= height[end]){
				start++;
			}else{
				end--;
			}
		}

		return result;
	}

	/**
	 * 121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
	 */
	//贪心法，分别找到价格最低和最高的一天，低进高出，注意最低的一天要在最高的一天之前。
	//把原始价格序列编程差分序列，本题也可以做是最大m子段和，m=1。
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2)
			return 0;

		int profit = 0; //差价，就是利润
		int cur_min = prices[0]; //当前最小

		for(int i=1; i<prices.size(); ++i){
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]);
		}

		return profit;
	}

	/**
	 * 122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
	 */
	//贪心法，低进高出，把所有正的价格差价相加起来。
	//把原始价格序列编程差分序列，本题也可以是最大m子段和，m=数组长度。
	int maxProfit(vector<int>& prices) {
		int sum = 0;
		for(int i=1; i<prices.size(); i++){
			int diff = prices[i] - prices[i-1];
			if(diff > 0)
				sum += diff;
		}

		return sum;
	}
};