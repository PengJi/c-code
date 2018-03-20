class Solution {
public:
	/**
	 * 34. Search for a Range
	 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
	 */
	//二分查找
	vector<int> searchRange(vector<int>& nums, int target) {
	    int idx1 = lower_bound(nums, target);
	    int idx2 = lower_bound(nums, target+1)-1;
	    if (idx1 < nums.size() && nums[idx1] == target)
	        return {idx1, idx2};
	    else
	        return {-1, -1};
	}

	int lower_bound(vector<int>& nums, int target) {
	    int l = 0, r = nums.size()-1;
	    while (l <= r) {
	        int mid = (r-l)/2+l;
	        if (nums[mid] < target)
	            l = mid+1;
	        else
	            r = mid-1;
	    }
	    return l;
	}
};