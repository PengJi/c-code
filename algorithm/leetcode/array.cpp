class Solution {
public:
	/*
	 * 1. 
	 * Two Sum
	 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
	 */
	vector<int> twoSum(vector<int> &numbers, int target){
		//Key is the number and value is its index in the vector.
		unordered_map<int,int> hash;
		vector<int> vec;

		for(int i = 0;i<numbers.size();i++){
			int numberToFind = target-numbers[i];
			//if numberToFind is found in map, return them
			if(hash.find(numberToFind) != hash.end()){
				vec.push_back(hash[numberToFind]);
				vec.push_back(i);
				return vec;
			}

			//number was not found. Put it in the map.
			hash[numbers[i]] = i;
		}
	}

	/*
	 * 287. 
	 * Find the Duplicate Number
	 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
	 */
	int findDuplicate3(vector<int>& nums)
	{
		if (nums.size() > 1)
		{
			int slow = nums[0];
			int fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}

			fast = 0;
			while (fast != slow)
			{
				fast = nums[fast];
				slow = nums[slow];
			}
			return slow;
		}
		return -1;
	}
};