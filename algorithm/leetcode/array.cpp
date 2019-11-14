/**
 * 线性表
 * 数组
 */
class Solution {
public:
    /**
     * 1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

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
     * 4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

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

    /**
     * 15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
     */
    //先排序，然后夹逼，跳过重复的数
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;

        sort(nums.begin(),nums.end());
        const int target = 0;

        auto last = nums.end();
        for(auto i = nums.begin(); i<last-2; ++i){
            auto j = i+1;
            if(i>nums.begin() && *i == *(i-1))
                continue;

            auto k=last-1;
            while(j<k){
                if(*i +  *j + *k < target){
                    ++j;
                    while(*j == *(j-1) && j<k)
                        ++j;
                }else if(*i + *j + *k > target){
                    --k;
                    while(*k == *(k+1) && j<k)
                        --k;
                }else{
                    result.push_back({*i,*j,*k});
                    ++j;
                    --k;
                    while(*j == *(j-1) && *k == *(k+1) && j<k)
                        ++j;
                }
            }
        }

        return result;
    }

    /**
     * 16. 3Sum Closest
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
     */
    //先排序，然后左右夹逼
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;

        sort(nums.begin(), nums.end());

        for(auto a=nums.begin(); a!=prev(nums.end(),2); ++a){
            auto b=next(a);
            auto c=prev(nums.end());

            while(b<c){
                const int sum = *a+*b+*c;
                const int gap = abs(sum-target);

                if(gap< min_gap){
                    result = sum;
                    min_gap = gap;
                }

                if(sum < target) ++b;
                else --c;
            }
        }

        return result;
    }

    /**
     * 18. 4Sum
Given an array S of n integers, are there elements a, b, c, 
and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
     */
    //先排序，然后左右夹逼
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;

        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for(auto a = nums.begin(); a<prev(last,3); ++a){
            for(auto b = next(a); b<prev(last,2); ++b){
                auto c = next(b);
                auto d = prev(last);
                while(c<d){
                    if(*a + *b + *c + *d < target){
                        ++c;
                    }else if(*a+*b+*c+*d > target){
                        --d;
                    }else{
                        result.push_back({*a,*b,*c,*d});
                        ++c;
                        --d;
                    }
                }
            }
        }

        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    //map做缓存
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        sort(nums.begin(),nums.end());

        unordered_map<int, vector<pair<int,int>>> cache;
        for(size_t a = 0; a<nums.size(); ++a){
            for(size_t b = a+1; b<nums.size(); ++b){
                cache[nums[a]+nums[b]].push_back(pair<int,int>(a,b));
            }
        }

        for(int c=0; c<nums.size();++c){
            for(size_t d=c+1;d<nums.size();++d){
                const int key = target-nums[c] - nums[d];
                if(cache.find(key) == cache.end())
                    continue;

                const auto& vec = cache[key];
                for(size_t k = 0; k<vec.size();++k){
                    if(c<=vec[k].second)
                        continue;

                    result.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
                }
            }
        }

        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    //用一个hashmap先缓存两个数的和
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;
        sort(nums.begin(),nums.end());

        unordered_multimap<int, pair<int,int>> cache;
        for(int i=0; i+1<nums.size();++i)
            for(int j=i+1; j<nums.size();++j)
                cache.insert(make_pair(nums[i]+nums[j], make_pair(i,j)));

        for(auto i = cache.begin(); i!= cache.end();++i){
            int x = target-i->first;
            auto range = cache.equal_range(x);
            for(auto j = range.first; j!=range.second; ++j){
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if(a!=c && a!=d && b != c && b != d){
                    vector<int> vec = {nums[a],nums[b],nums[c],nums[d]};
                    sort(vec.begin(),vec.end());
                    result.push_back(vec);
                }
            }
        }

        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    //先排序，然后左右夹逼
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        sort(nums.begin(),nums.end());

        auto last = nums.end();
        for(auto a=nums.begin(); a<prev(last,3); a=upper_bound(a,prev(last,3),*a)){
            for(auto b=next(a); b < prev(last,2); b=upper_bound(b,prev(last,2),*b)){
                auto c = next(b);
                auto d = prev(last);
                while(c<d){
                    if(*a+*b+*c+*d < target){
                        c = upper_bound(c,d,*c);
                    }else if(*a+*b+*c+*d > target){
                        d = prev(lower_bound(c,d,*d));
                    }else{
                        result.push_back({*a,*b,*c,*d});
                        c = upper_bound(c,d,*c);
                        d = prev(lower_bound(c,d,*d));
                    }
                }
            }
        }

        return result;
    }

    /*
     * 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

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
Given a sorted array, remove the duplicates in-place such that each element appear only once 
and return the new length.

Do not allocate extra space for another array, you must do this by 
modifying the input array in-place with O(1) extra memory.

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
     * 27. Remove Element
Given an array and a value, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
     */
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != val){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
    //使用remove
    int removeElement(vector<int>& nums, int val){
        return distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }

    /**
     * 31. Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest 
possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

problem:
https://leetcode.com/problems/next-permutation/description/
     */
    void nextPermutation(vector<int>& nums) {
        next_Permutation(nums.begin(), nums.end());
    }
    template<typename BidiIt>
    bool next_Permutation(BidiIt first, BidiIt last){
        //get a reversed range to simplify reversed traversal.
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);

        //begin from the second last element to the first element
        auto pivot = next(rfirst);

        //find 'pivot', which is the first element that is no less than its successor.
        //'prev' is used since 'pivot' is a 'reversed_iterator'.
        while(pivot != rlast && *pivot >= *prev(pivot))
            ++pivot;

        //no such elements found, current sequence is already the largest
        //permutation, then rearrange to the first permutation and return false
        if(pivot == rlast){
            reverse(rfirst, rlast);
            return false;
        }

        //scan from right to left, find the first element that is greater than 'pivot'
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

        swap(*change, *pivot);
        reverse(rfirst, pivot);

        return true;
    }

    /**
     * 33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
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

    /**
     * 36. Valid Sudoku
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be 
validated according to the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];

        for(int i=0; i<9; ++i){
            fill(used, used+9, false);

            for(int j=0; j<9; ++j) //检查行
                if(!check(board[i][j], used))
                    return false;

            fill(used, used+9, false);

            for(int j=0; j<9; ++j) //检查列
                if(!check(board[j][i], used))
                    return false;
        }

        for(int r=0; r<3; ++r) //检查9个格子
            for(int c=0; c<3; ++c){
                fill(used, used+9, false);

                for(int i=r*3; i<r*3+3; ++i)
                    for(int j=c*3; j<c*3+3; ++j)
                        if(!check(board[i][j], used))
                            return false;
            }

        return true;
    }
    bool check(char ch, bool used[9]){
        if(ch =='.') return true;
        if(used[ch - '1']) return false;

        return used[ch-'1'] = true;
    }

    /*
     * 39. Combination Sum
Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

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

    void findCombSum(vector<int> &candidates, int start, int target,
                     vector<int> &sol, vector<vector<int>> &allSol) {
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

    /**
     * 42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
     */
    //对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的面积就是min(max_left,max_right)-height。
    //所以
    //1. 从左往右扫描一遍，对于每个柱子，求去左边最大值
    //2. 从右往左扫描一遍，对于每个柱子，求最大右值
    //3. 再扫描一遍，把每个柱子的面积并累加
    //也可以
    //1. 扫描一遍，找到最高的柱子，这个柱子将数组分为两半
    //2. 处理左边一半
    //3. 处理右边一半
    //思路一
    int trap(vector<int>& height) {
        const int n = height.size();
        int *max_left = new int[n]();
        int *max_right = new int[n]();

        for(int i=1; i<n; i++){
            max_left[i] = max(max_left[i-1], height[i-1]);
            max_right[n-1-i] = max(max_right[n-i], height[n-i]);
        }

        int sum = 0;
        for(int i=0; i<n; ++i){
            int h = min(max_left[i], max_right[i]);
            if(h > height[i]){
                sum += h - height[i];
            }
        }

        delete[] max_left;
        delete[] max_right;

        return sum;
    }

    //思路二
    int trap(vector<int>& height){
        const int n = height.size();
        int max=0; //最高的柱子，将数据分为两半
        for(int i=0; i<n; i++)
            if(height[i]>height[max])
                max = i;

        int water = 0;
        for(int i=0, peak=0; i<max; i++)
            if(height[i] > peak)
                peak = height[i];
            else
                water += peak-height[i];

        for(int i=n-1, top=0; i>max; i--){
            if(height[i] > top)
                top = height[i];
            else
                water += top-height[i];
        }

        return water;
    }


    /**
     * 48. Rotate Image
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
     */
    //思路一
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for(int i=0; i<n; ++i)//沿着副对角线反转
            for(int j=0; j<n-i; ++j)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);

        for(int i=0; i<n/2; ++i)//沿着水平中线反转
            for(int j=0; j<n; ++j)
                swap(matrix[i][j], matrix[n-1-i][j]);
    }
    //思路二
    void rotate(vector<vector<int>>& matrix){
        const int n = matrix.size();

        for(int i=0; i<n/2; ++i)//沿着水平中线反转
            for(int j=0; j<n; ++j)
                swap(matrix[i][j], matrix[n-1-i][j]);

        for(int i=0; i<n; ++i) //沿着主对角线反转
            for(int j=i+1; j<n; ++j)
                swap(matrix[i][j],matrix[j][i]);
    }

    /*
     * 55. Jump Game
     *
     * Given an array of non-negative integers,
     * you are initially positioned at the first index of the array.
     *
     * Each element in the array represents your maximum jump length at that position.
     * Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

problem:
     https://leetcode.com/problems/jump-game/

solution:
http://bangbingsyb.blogspot.ca/2014/11/leetcode-jump-game-i-ii.html
     */
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i > maxIndex || maxIndex >= (n-1))
                break;
            maxIndex = max(maxIndex,i+nums[i]);
        }
        return maxIndex >= (n-1);
    }

    /*
     * 56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

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
     * 60. Permutation Sequence
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, 
we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"

problem:
https://leetcode.com/problems/permutation-sequence/description/
     */
    //康托编码
    string getPermutation(int n, int k) {
        string s(n, '0');
        string result;

        for(int i=0; i<n; ++i)
            s[i] += i+1;

        return kth_permutation(s,k);
    }
    int factorial(int n){
        int result = 1;
        for(int i=1; i<=n; ++i)
            result *= i;

        return result;
    }
    template<typename Sequence>
    Sequence kth_permutation(const Sequence &seq, int k){
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;

        int base = factorial(n-1);
        --k;

        for(int i=n-1; i>0; k%=base, base/=i, --i){
            auto a = next(S.begin(), k/base);
            result.push_back(*a);
            S.erase(a);
        }

        result.push_back(S[0]);
        return result;
    }

    /**
     * 66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
     */
    //代码一
    vector<int> plusOne(vector<int>& digits) {
        add(digits,1);
        return digits;
    }
    void add(vector<int>& digits,int digit){
        int c = digit; //进位

        for(auto it=digits.rbegin(); it != digits.rend(); ++it){
            *it += c;
            c = *it/10;
            *it %= 10;
        }

        if(c>0)
            digits.insert(digits.begin(),1);
    }
    //代码二
    vector<int> plusOne(vector<int> &digits){
        add(digits,1);
        return digits;
    }
    void add(vector<int> &digits, int digit){
        int c = digit; //进位

        for_each(digits.rbegin(), digits.rend(), [&c](int &d){
            d += c;
            c = d/10;
            d %= 10;
        });

        if(c>0)
            digits.insert(digits.begin(),1);
    }

    /**
     * 70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
     */
    //设f(n)表示爬n阶楼梯的不同方法数，为了爬到第n阶楼梯，有两个选择：
    //从第n-1阶前进1步
    //从第n-1阶前进2步
    //因此，有f(n) = f(n-1) + f(n-2)
    //斐波那契数列
    //迭代
    int climbStairs(int n) {
        int prev = 0;
        int cur = 1;

        for(int i=1; i<=n; ++i){
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }

        return cur;
    }

    /**
     * 73. Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
     */
    //O(m+n)空间的方法很简单，设置两个bool数组，记录每行和每列是否存在0。
    //想要常数空间，可以服用第一行和第一列
    //代码一，时间复杂度O(m*n)，空间复杂度O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();

        vector<bool> row(m, false); //标记该行是否存在0
        vector<bool> col(n, false); //标记该列是否存在0

        for(size_t i=0; i<m; i++){
            for(size_t j=0; j<n; j++){
                if(matrix[i][j] == 0)
                    row[i] = col[j] = true;
            }
        }

        for(size_t i=0; i<m; ++i){
            if(row[i])
                fill(&matrix[i][0], &matrix[i][0]+n, 0);
        }
        for(size_t j=0; j<n; ++j){
            if(col[j]){
                for(size_t i=0; i<m; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //代码二，时间复杂度O(m*n)，空间复杂度O(1)
    void setZeroes(vector<vector<int>> &matrix){
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        bool row_has_zero = false; //第一行是否存在0
        bool col_has_zero = false; //第一列是否存在0

        for(size_t i=0; i<n; i++)
            if(matrix[0][i] == 0){
                row_has_zero = true;
                break;
            }

        for(size_t i=0; i<m; i++)
            if(matrix[i][0] == 0){
                col_has_zero = true;
                break;
            }

        for(size_t i=1; i<m; i++)
            for(size_t j=1; j<n; j++)
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for(size_t i=1; i<m; i++)
            for(size_t j=1; j<n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if(row_has_zero)
            for(size_t i=0; i<n; i++)
                matrix[0][i] = 0;

        if(col_has_zero)
            for(size_t i=0; i<m; i++)
                matrix[i][0] = 0;
    }

    /**
     * 80. Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
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
Follow up for "Search in Rotated Sorted Array":
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

    /**
     * 89. Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
     */
    //自然二进制转格雷码
    //格雷码转自然二进制
    vector<int> grayCode(int n) {
        vector<int> result;
        const size_t size = 1<<n; //2^n
        result.reserve(size);
        for(size_t i=0; i<size; ++i)
            result.push_back(binary_to_gray(i));

        return result;
    }
    unsigned int binary_to_gray(unsigned int n){
        return n^(n>>1);
    }
    //Reflect-and-prefix method
    vector<int> grayCode(int n){
        vector<int> result;
        result.reserve(1<<n);
        result.push_back(0);
        for(int i=0; i<n; ++i){
            const int highest_bit = 1 << i;
            for(int j=result.size()-1; j>=0; j--){
                result.push_back(highest_bit | result[j]);
            }
        }

        return result;
    }

    /**
     * 128. Longest Consecutive Sequence
Given an unsorted array of integers, 
find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.
     */
    //如果允许O(nlogn)的复杂度，那么可以先排序，但本题要求O(n)
    //由于序列里的元素是无序的，有要求O(n)，首先要想到用哈希表
    //用于哈希表unordered_map<int, bool> used记录每个元素是否使用，
    //对每个元素，以该元素为中心，往左右扩展，知道不连续为止，记录下最长的长度
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int ,bool> used;

        for(auto i : nums)
            used[i] = false;

        int longest = 0;

        for(auto i:nums){
            if(used[i]) continue;

            int length = 1;

            used[i] = true;

            for(int j=i+1; used.find(j) != used.end(); ++j){
                used[j] = true;
                ++length;
            }

            for(int j=i-1; used.find(j) != used.end(); --j){
                used[j] = true;
                ++length;
            }

            longest = max(longest, length);
        }

        return longest;
    }

    /**
     * 134. Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel 
from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once 
in the clockwise direction, otherwise return -1.

Note:
If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.

Example 1:
Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: 
gas  = [2,3,4]
cost = [3,4,3]
Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
     */
    //O(N)的解法是，设置两个变量，sum判断当前的指针的有效性
    //total则判断整个数组是否有解，有就返回通过sum得到的下标，没有则返回-1
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int j = -1;
        for(int i=0, sum=0; i<gas.size(); ++i){
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if(sum < 0){
                j=i;
                sum = 0;
            }
        }

        return total >= 0 ? j+1 : -1;
    }

    /**
     * 135. Candy
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
     */
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> increment(n);

        //左右各扫描一遍
        for(int i=1, inc=1; i<n; i++){
            if(ratings[i] > ratings[i-1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        for(int i=n-2, inc=1; i>=0; i--){
            if(ratings[i]>ratings[i+1])
                increment[i] = max(inc++, increment[i]);
            else
                inc=1;
        }

        return accumulate(&increment[0], &increment[0]+n,n);
    }
    //递归版
    int candy(const vector<int>& ratings){
        vector<int> f(ratings.size());
        int sum=0;
        for(int i=0; i<ratings.size(); ++i)
            sum += solve(ratings, f, i);
        return sum;
    }
    int solve(const vector<int>& ratings, vector<int>& f, int i){
        if(f[i] == 0){
            f[i]=1;
            if(i>0 && ratings[i] > ratings[i-1])
                f[i] = max(f[i], solve(ratings, f, i-1)+1);
            if(i<ratings.size()-1 && ratings[i]>ratings[i+1])
                f[i] = max(f[i], solve(ratings, f, i+1)+1);
        }

        return f[i];
    }

    /**
     * 136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
     */
    //异或，不仅能处理两次的情况，只要出现偶数次，都可以清零
    //代码1
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto i:nums){
            x ^= i;
        }
        return x;
    }
    //代码2
    int singleNumber(vector<int> & nums){
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }

    /**
     * 137. Single Number II
Given a non-empty array of integers, every element appears three times except for one, 
which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it 
without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3

Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99
     */
    //考察位运算
    //方法1：创建一个长度为sizeof(int)的数组count[sizeof(int)]，count[i]表示在i位出现1的次数。
    //如果count[i]是3的整数倍，则忽略；否则就把该位取出来组成答案
    //方法2：用one记录为当前处理的元素为止，二进制1出现1次(mod3之后的1)的有哪些二进制位；
    //用two记录当前计算的变量为止,二进制1出现2次(mod3之后)的有哪些二进制位。
    //用one和two中的某一位同时为1时表示该二进制位上1出现了3次，此时需要清零。
    //即用二进制模拟三进制运算。最终one记录的最终结果
    //代码1
    int singleNumber(vector<int>& nums) {
        const int W = sizeof(int) * 8; //一个整数的bit数，即整数字长
        int count[W]; //count[i]表示在i位出现的1的次数
        fill_n(&count[0], W, 0);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<W; j++){
                count[j] += (nums[i] >> j) & 1;
                count[j] %= 3;
            }
        }

        int result = 0;
        for(int i=0; i<W; ++i){
            result += (count[i] << i);
        }

        return result;
    }
    //代码2
    int singleNumber(vector<int>& nums){
        int one = 0, two=0, three=0;
        for(auto i : nums){
            two |= (one & i);
            one ^= i;
            three = ~(one & two);
            one &= three;
            two &= three;
        }

        return one;
    }

    /**
     * 169. Majority Element
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element 
always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

problem:
https://leetcode.com/problems/majority-element/description/

solution:
https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C++-with-Explanations
     */
    //hash table
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(++counts[nums[i]] > n/2)
                return nums[i];
        }
    }
    //moore voting algorithm
    int majorityElement(vector<int>& nums){
        int major, counts=0, n=nums.size();
        for(int i=0; i<n; i++){
            if(!counts){
                major = nums[i];
                counts = 1;
            }else{
                counts += major == nums[i]?1:-1;
            }
        }

        return major;
    }
    //Bit Manipulation
    int majorityElement(vector<int>& nums){
        int major=0, n=nums.size();
        for(int i=0, mask=1; i<32; i++, mask<<=1){
            int bitCounts = 0;
            for(int j=0; j<n; j++){
                if(nums[j] & mask) bitCounts++;
                if(bitCounts > n/2){
                    major |= mask;
                    break;
                }
            }
        }

        return major;
    }

    /**
     * 215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

problem:
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

solution:
https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/4-C++-Solutions-using-Partition-Max-Heap-priority_queue-and-multiset-respectively
     */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
    //quicksort
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int l = left+1, r = right;
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int> &nums, int k){
        int left = 0, right = nums.size()-1;
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k-1) return nums[pos];
            if(pos > k-1) right = pos-1;
            else left = pos+1;
        }
    }
    //use priority_queue
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=0; i<k-1; i++)
            pq.pop();

        return pq.top();
    }
    //use multiset
    int findKthLargest(vector<int>& nums, int k){
        multiset<int> mset;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mset.insert(nums[i]);
            if(mset.size() > k)
                mset.erase(mset.begin());
        }

        return *mset.begin();
    }

    /**
     * 218. The Skyline Problem
A city's skyline is the outer contour of the silhouette formed by all 
the buildings in that city when viewed from a distance. Now suppose 
you are given the locations and height of all the buildings as shown 
on a cityscape photo (Figure A), write a program to output the 
skyline formed by these buildings collectively (Figure B).

Buildings  Skyline Contour
The geometric information of each building is represented by a triplet 
of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the 
left and right edge of the ith building, respectively, and Hi is its height. 
It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
You may assume all buildings are perfect rectangles grounded on an absolutely 
flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded 
as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the 
format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 
A key point is the left endpoint of a horizontal line segment. Note that the 
last key point, where the rightmost building ends, is merely used to mark the 
termination of the skyline, and always has zero height. Also, the ground in 
between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], 
[7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:
The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. 
For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: 
[...[2 3], [4 5], [12 7], ...]
     */
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int> coords;
        for(const vector<int> &building : buildings){
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }

        multiset<int> heights = {0};
        vector<pair<int, int>> corners;
        int x = -1;
        int y = 0;
        for(const pair<int, int>& p : coords){
            if(x >= 0 && (p.first != x) && (corners.empty() || (corners.rbegin()->second != y))){
                corners.emplace_back(x, y);
            }

            if(p.second >= 0){
                heights.insert(p.second);
            }else{
                heights.erase(heights.find(-p.second));
            }

            x = p.first;
            y = *heights.rbegin();
        }

        if(!corners.empty()){
            corners.emplace_back(x, 0);
        }

        return corners;
    }

    /*
     * 287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
find the duplicate one.

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
Given a non-empty array of integers, return the k most frequent elements.

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