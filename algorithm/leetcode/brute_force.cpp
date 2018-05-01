/**
 * 暴力枚举法
 */
class Solution {
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
	 * 90. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
	 */
	//递归
	//增量构造法,版本1
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		vector<int> path;

		dfs(nums, nums.begin(), path, result);

		return result;
	}
	static void dfs(const vector<int> &nums, vector<int>::iterator start,
		vector<int> &path, vector<vector<int>> &result){
		result.push_back(path);

		for(auto i=start; i<nums.end(); i++){
			if(i != start && *i == *(i-1)) continue;
			path.push_back(*i);
			dfs(nums, i+1, path, result);
			path.pop_back();
		}
	}
	//增量构造法，版本2
	vector<vector<int>> subsetsWithDup(vector<int> &nums){
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());

		unordered_map<int, int> count_map; //记录每个元素的出现次数
		for_each(nums.begin(), nums.end(), [&count_map](int e){
			if(count_map.find(e) != count_map.end())
				count_map[e]++;
			else
				count_map[e] = 1;
		});

		//将map里的pair拷贝到一个vector里
		vector<pair<int, int>> elems;
		for_each(count_map.begin(), count_map.end(),
			[&elems](const pair<int, int> &e){
				elems.push_back(e);
			});

		sort(elems.begin(), elems.end());
		vector<int> path; //中间结果

		subsets(elems, 0, path, result);
		return result;
	}
	static void subsets(const vector<pair<int, int>> &elems, 
		size_t step, vector<int> &path, vector<vector<int>> &result){
		if(step == elems.size()){
			result.push_back(path);
			return;
		}

		for(int i=0; i<=elems[step].second; i++){
			for(int j=0; j<i; ++j){
				path.push_back(elems[step].first);
			}
			subsets(elems, step+1, path, result);
			for(int j=0; j<i; ++j){
				path.pop_back();
			}
		}
	}
	//位向量法
	vector<vector<int>> subsetsWithDup(vector<int> &nums){
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());
		vector<int> count(nums.back() - nums.front() + 1, 0);

		//计算所有元素的个数
		for(auto i:nums){
			count[i - nums[0]]++;
		}

		//每个元素选择了多少个
		vector<int> selected(nums.back() - nums.front()+1, -1);

		subsets(nums, count, selected, 0, result);
		return result;
	}
	static void subsets(const vector<int> &nums, vector<int> &count,
		vector<int> &selected, size_t step, vector<vector<int>> &result){
		if(step == count.size()){
			vector<int> subset;

			for(size_t i=0; i<selected.size(); i++){
				for(int j=0; j<selected[i]; j++){
					subset.push_back(i+nums[0]);
				}
			}

			result.push_back(subset);
			return;
		}

		for(int i=0; i<=count[step]; i++){
			selected[step] = i;
			subsets(nums, count, selected, step+1, result);
		}
	}

	//迭代
	//增量构造法
	vector<vector<int>> subsetsWithDup(vector<int> &nums){
		sort(nums.begin(), nums.end());
		vector<vector<int>> result(1);

		size_t previous_size = 0;
		for(size_t i=0; i<nums.size(); ++i){
			const size_t size = result.size();
			for(size_t j=0; j<size; ++j){
				if(i==0 || nums[i]!=nums[i-1] || j>=previous_size){
					result.push_back(result[j]);
					result.back().push_back(nums[i]);
				}
			}
			previous_size = size;
		}

		return result;
	}
	//二进制法
	vector<vector<int>> subsetsWithDup(vector<int> &nums){
		sort(nums.begin(), nums.end());

		//用set去重，不能用unordered_set，因为输出要求有序
		set<vector<int>> result;
		const size_t n = nums.size();
		vector<int> v;

		for(size_t i=0; i<1U << n; ++i){
			for(size_t j=0; j<n; ++j){
				if(i & 1<<j)
					v.push_back(nums[j]);
			}
			result.insert(v);
			v.clear();
		}

		vector<vector<int>> real_result;
		copy(result.begin(), result.end(), back_inserter(real_result));
		return real_result;
	}
};