/**
 * 暴力枚举法
 */
class Solution {
	/**
	 * 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

[图]

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
	 */
	//递归
	const vector<string> keyboard {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if(digits.empty())
			return result;

		dfs(digits, 0, "", result);

		return result;
	}
	void dfs(const string &digits, size_t cur, string path,
		vector<string> &result){
		if(cur == digits.size()){
			result.push_back(path);
			return;
		}

		for(auto c : keyboard[digits[cur] - '0']){
			dfs(digits, cur+1, path+c, result);
		}
	}

	//迭代
	const vector<string> keyboard {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> letterCombinations(string digits){
		if(digits.empty())
			return vector<string>();

		vector<string> result(1, "");
		for(auto d:digits){
			const size_t n = result.size();
			const size_t m = keyboard[d - '0'].size();

			result.resize(n * m);
			for(size_t i = 0; i<m; ++i)
				copy(result.begin(), result.begin()+n, result.begin()+n*i);

			for(size_t i=0; i<m; ++i){
				auto begin = result.begin();
				for_each(begin+n*i, begin+n*(i+1), [&](string &s){
					s += keyboard[d-'0'][i];
				});
			}
		}

		return result;
	}

	/**
	 * 46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
	 */
	//1. 使用next_permutation()
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());

		do{
			result.push_back(nums);
		}while(next_permutation(nums.begin(), nums.end()));

		return result;
	}

	//重新实现next_permutation()
	vector<vector<int>> permute(vector<int> &nums){
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());

		do{
			result.push_back(nums);
		}while(next_permutation(nums.begin(), nums.end()));

		return result;
	}
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last) {
		// Get a reversed range to simplify reversed traversal.
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);
		// Begin from the second last element to the first element.
		auto pivot = next(rfirst);
		// Find `pivot`, which is the first element that is no less than its
		// successor. `Prev` is used since `pivort` is a `reversed_iterator`.
		while (pivot != rlast && *pivot >= *prev(pivot))
		++pivot;
		// No such elemenet found, current sequence is already the largest
		// permutation, then rearrange to the first permutation and return false.
		if (pivot == rlast) {
			reverse(rfirst, rlast);
			return false;
		}
		// Scan from right to left, find the first element that is greater than
		// `pivot`.
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		swap(*change, *pivot);
		reverse(rfirst, pivot);
		return true;
	}

	//2. 递归
	//扩展节点，每次从左到右，选一个没有出现过的元素
	//本题不需要判重，因为状态转换图是一颗有层次的树。收敛条件是当前走到了最后一个元素
	vector<vector<int>> permute(vector<int> &nums){
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		vector<int> path; //中间结果

		dfs(nums, path, result);

		return result;
	}
	void dfs(const vector<int> &nums, vector<int> &path,
		vector<vector<int>> &result){
		if(path.size() == nums.size()){ //收敛条件
			result.push_back(path);
			return;
		}

		//扩展状态
		for(auto i:nums){
			//查找i是否在path中出现过
			auto pos = find(path.begin(), path.end(), i);

			if(pos == path.end()){
				path.push_back(i);
				dfs(nums, path, result);
				path.pop_back();
			}
		}
	}

	/**
	 * 47. Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
	 */
	//递归
	//递归函数permute()的参数p，是中间结果，它的长度又能标记当前走到了哪一步，用于判断收敛条件
	//扩展节点，每次从小到大，选一个没有被用光的元素，直到所有元素被用光
	//本题不需要判重，因为状态转换是一颗有层次的树
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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
		for_each(count_map.begin(), count_map.end(), [&elems](const pair<int, int> &e){
			elems.push_back(e);
		});

		vector<vector<int>> result; //最终结果
		vector<int> p; //中间结果

		n = nums.size();
		permute(elems.begin(), elems.end(), p, result);

		return result;
	}
	size_t n;
	typedef vector<pair<int, int>>::const_iterator iter;
	void permute(iter first, iter last, vector<int> &p, 
		vector<vector<int>> &result){
		if(n == p.size()){ //收敛条件
			result.push_back(p);
		}

		//扩展状态
		for(auto i=first; i!=last; i++){
			int count = 0; //统计*i在p中出现过多少次

			for(auto j=p.begin(); j!=p.end(); j++){
				if(i->first == *j){
					count++;
				}
			}

			if(count < i->second){
				p.push_back(i->first);
				permute(first, last, p, result);
				p.pop_back();
			}
		}
	}

	/**
	 * 77. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
	 */
	//递归
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> path;

		dfs(n, k, 1, 0, path, result);
		return result;
	}
	static void dfs(int n, int k, int start, int cur, 
		vector<int> &path, vector<vector<int>> &result){
		if(cur == k){
			result.push_back(path);
		}

		for(int i=start; i<=n; ++i){
			path.push_back(i);
			dfs(n, k, i+1, cur+1, path, result);
			path.pop_back();
		}
	}
	
	//迭代
	vector<vector<int>> combine(int n, int k){
		vector<int> values(n);
		iota(values.begin(), values.end(), 1);

		vector<bool> select(n, false);
		fill_n(select.begin(), k, true);
		vector<vector<int>> result;
		do{
			vector<int> one(k);
			for(int i=0, index=0; i<n; ++i)
				if(select[i])
					one[index++] = values[i];
				result.push_back(one);
		}while(prev_permutation(select.begin(), select.end()));
		return result;
	}

	/**
	 * 78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).

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