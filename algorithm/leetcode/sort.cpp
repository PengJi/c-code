/**
 * 排序
 */
class Solution {
public:
    /**
     * 23. Merge k Sorted Lists
     * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        ListNode *p = lists[0];
        for(int i = 1; i<lists.size(); i++){
            p = mergeTwoLists(p,lists[i]);
        }

        return p;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode head(-1);
        for(ListNode *p = &head; l1!=nullptr || l2 != nullptr; p = p->next){
            int val1 = l1==nullptr?INT_MAX:l1->val;
            int val2 = l2==nullptr?INT_MAX:l2->val;
            if(val1 <= val2){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2=l2->next;
            }
        }

        return head.next;
    }

    /**
     * 41. First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
     */
    /*
    桶排序，每当A[i]!=i+1的时候，将A[i]与A[A[i]-1]交换，直到无法交换为止，终止条件是A[i]==A[A[i]-1]。
     */
    int firstMissingPositive(vector<int>& nums) {
        buckct_sort(nums);

        for(int i=0; i<nums.size(); ++i)
            if(nums[i] != (i+1))
                return i+1;
        return nums.size()+1;
    }
    void buckct_sort(vector<int> &A){
        const int n = A.size();
        for(int i=0;i<n;i++){
            while(A[i] != i+1){
                if(A[i] <= 0 || A[i]>n || A[i]==A[A[i]-1])
                    break;
                swap(A[i],A[A[i]-1]);
            }
        }
    }

	/**
	 * 75. Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
	 */
	//第一种，计数排序，但需要扫描两遍
	void sortColors(vector<int>& nums) {
        int counts[3] = {0}; //记录每个颜色出现的次数

        for(int i=0; i<nums.size(); i++)
        	counts[nums[i]]++;

        for(int i=0, index = 0; i<3; i++)
        	for(int j=0; j<counts[i]; j++)
        		nums[index++] = i;
    }

    //第二种，双指针。由于只有三种颜色，可以设置两个index，一个是red的index,
    //一个是blue的index，两边往中间走。
    void sortColors(vector<int>& nums) {
    	int red = 0; //red的index
    	int blue = nums.size()-1; //blue的index

    	for(int i=0; i<blue+1;){
    		if(nums[i]==0)
    			swap(nums[i++],nums[red++]);
    		else if(nums[i] == 2)
    			swap(nums[i],nums[blue--]);
    		else
    			i++;
    	}
    }

    //第三种，利用快排的partition思想，第一次将数组按0分割，第二次按1分割，排序完毕
    //可以推广到n中颜色，每种颜色有重复元素的情况。
    void sortColors(vector<int>& nums) {
    	partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(),0)),
    		nums.end(), bind1st(equal_to<int>(), 1));
    }
    template<typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last,
    	UnaryPredicate pred) {
    	auto pos = first;

    	for (; first != last; ++first)
    		if (pred(*first))
    			swap(*first, *pos++);

    	return pos;
    }

	/**
	 * 88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
	 */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m-1, ib = n-1, icur = m+n-1;
        while(ia >= 0 && ib >= 0){
        	nums1[icur--] = nums1[ia]>=nums2[ib] ? nums1[ia--] : nums2[ib--];
        }
        while(ib >= 0){
        	nums1[icur--] = nums2[ib--];
        }
    }
};