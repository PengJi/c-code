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
     * 22. 
     * Generate Parentheses
     * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
     */
    vector<string> generateParenthesis(int n){
    	vector<string> allComb;
    	string comb;
    	findParenthesis(n,0,0,comb,allComb);
    	return allComb;
    }
    void findParenthesis(int n,int nleft,int nright,string &comb,vector<string> &allComb){
    	if(nleft==n && nright==n){
    		allComb.push_back(comb);
    		return;
    	}
    	if(nleft < n){
    		comb.push_back('(');
    		findParenthesis(n,nleft+1,nright,comb,allComb);
    		comb.pop_back();
    	}
    	if(nright < nleft){
    		comb.push_back(')');
    		findParenthesis(n,nleft,nright+1,comb,allComb);
    		comb.pop_back();
    	}
    }

    /**
     * 26. Remove Duplicates from Sorted Array
     * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
     */
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int index = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index+1;
    }
    //使用STL
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(),nums.end()));
    }
    //使用STL
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(),removeDuplicates(nums.begin(),nums.end(),nums.begin()));
    }
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output){
        while(first != last){
            *output++ = *first;
            first = upper_bound(first,last, *first);
        }
        return output;
    }

    /**
     * 33. Search in Rotated Sorted Array
     * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
     */
    //二分查找，难度在于左右边界的确定
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();

        while(first != last){
            const int mid = first + (last-first)/2;

            if(nums[mid] == target)
                return mid;
            if(nums[first] <= nums[mid]){
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid+1;
            }else{
                if(nums[mid] < target && target <= nums[last-1])
                    first = mid+1;
                else
                    last = mid;
            }
        }

        return -1;
    } 

    /*
     * 39. 
     * Combination Sum
     * Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
     * find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-combination-sum-i-ii.html
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > allSol;
        vector<int> sol;
        if(candidates.empty()) return allSol;
        sort(candidates.begin(),candidates.end());
        findCombSum(candidates, 0, target, sol, allSol);
        return allSol;
    }
    
    void findCombSum(vector<int> &candidates, int start, int target, vector<int> &sol, vector<vector<int>> &allSol) {
        if(target==0) {
            allSol.push_back(sol);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++) {
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target) {
                sol.push_back(candidates[i]);
                findCombSum(candidates, i, target-candidates[i], sol, allSol);
                sol.pop_back();
            }
        }
    }

    /*
     * 55. 
     * Jump Game
     * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-jump-game-i-ii.html
     */
	bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
        	if(i>maxIndex || maxIndex >= (n-1))
        		break;
        	maxIndex = max(maxIndex,i+nums[i]);
        }
        return maxIndex >= (n-1)?true:false;
    }

    /*
     * 56. 
     * Merge Intervals
     * Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-merge-intervals.html
     */
    struct compInterval {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.start<b.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(),compInterval());
        vector<Interval> ret;
        for(int i=0; i<intervals.size(); i++) {
            if(ret.empty() || ret.back().end < intervals[i].start)  // no overlap
                ret.push_back(intervals[i]);
            else   // overlap
                ret.back().end = max(ret.back().end, intervals[i].end);
        }
        return ret;
    }

    /**
     * 80. Remove Duplicates from Sorted Array II
     * Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.
     */
    /*
    加一个变量记录元素出现的次数。如果数据没有排序，则引入一个hashmap来记录出现次数。
     */
    //代码一
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();

        int index=2;
        for(int i=2; i<nums.size(); i++){
            if(nums[i] != nums[index-2])
                nums[index++] = nums[i];
        }

        return index;
    }
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int index = 0;
        for(int i=0;i<n;++i){
            if(i>0 && i<n-1 && nums[i] == nums[i-1] && nums[i] == nums[i+1])
                continue;

            nums[index++] = nums[i];
        }

        return index;
    }

    /**
     * 81. Search in Rotated Sorted Array II
     * Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
     */
    bool search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();

        while(first != last){
            const int mid = first + (last-first)/2;
            if(nums[mid] == target)
                return true;

            if(nums[first] < nums[mid]){
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid+1;
            }else if(nums[first] > nums[mid]){
                if(nums[mid] < target && target <= nums[last-1])
                    first = mid+1;
                else
                    last = mid;
            }else{
                first++;
            }
        }

        return false;
    }

	/*
	 * 287. 
	 * Find the Duplicate Number
	 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
     * prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
     * find the duplicate one.

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

	/*
	 * 347. Top K Frequent Elements
	 * Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
	 */
	vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};