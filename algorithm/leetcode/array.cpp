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
	 * 4. 
	 * Median of Two Sorted Arrays
	 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
	 */
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if(N1 < N2)
        	return findMedianSortedArrays(nums2,nums1); // Make sure A2 is the shorter one.

        int lo = 0, hi = N2 * 2;
        while(lo <= hi){
        	int mid2 = (lo+hi)/2; // Try Cut 2 
        	int mid1 = N1+N2-mid2; // Calculate Cut 1 accordingly

        	double L1 = (mid1 == 0)?INT_MIN:nums1[(mid1-1)/2];
        	double L2 = (mid2 == 0)?INT_MIN:nums2[(mid2-1)/2];
        	double R1 = (mid1 == N1*2)?INT_MAX:nums1[mid1/2];
        	double R2 = (mid2 == N2*2)?INT_MAX:nums2[mid2/2];

        	if(L1 > R2)
        		lo = mid2+1; // A1's lower half is too big; need to move C1 left (C2 right)
        	else if(L2 > R1)
        		hi = mid2-1; // A2's lower half too big; need to move C2 left.
        	else 
        		return (max(L1,L2) + min(R1,R2))/2; // Otherwise, that's the right cut.

        }

        return -1;
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