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

	/**
	 * 35. Search Insert Position
	 * Given a sorted array and a target value, return the index if the target is found. If not, 
	 * return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
	 */
	//重新实现 lower_bound
	int searchInsert(vector<int>& nums, int target) {
        return distance(nums.begin(),lower_bound(nums.begin(),nums.end(),target));
    }
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last, T value){
    	while(first != last){
    		auto mid = next(first, distance(first, last)/2);

    		if(value > *mid)
    			first = ++mid;
    		else 
    			last = mid;
    	}

    	return first;
    }
};