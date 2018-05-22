/**
 * 广度优先搜索
 */
class Solution {
public：
	/**
	 * 广度优先搜索模板
	 */

	/**
	 * 126. Word Ladder II
Given two words (beginWord and endWord), and a dictionary's word list, 
find all shortest transformation sequence(s) from beginWord to endWord, such that:
1. Only one letter can be changed at a time
2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

problem:
https://leetcode.com/problems/word-ladder-ii/description/
	 */
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) { 
		vector<vector<string>> ans;
		unordered_set<string> dict(wordList.begin(), wordList.end());

		if(!dict.count(endWord)) return ans;
		vector<string> visited;
		queue<vector<string>> q;
		q.push({beginWord});

		while(!q.empty()){
			int n = q.size();
			for(int i=0; i<n; ++i){
				auto cur = q.front();
				q.pop();
				auto s = cur.back();

				for(auto&c : s){
					const char origin = c;
					for(c='a'; c<='z'; ++c){
						if(!dict.count(s))
							continue;
						auto path = cur;
						path.push_back(s);
						visited.push_back(s);
						if(s==endWord) ans.push_back(path);
						else q.push(path);
					}

					c = origin;
				}
			}

			for(auto& w : visited) dict.erase(w);
			visited.clear();
		}

		return ans;
    }
	
	/**
	 * 127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time.
1. Each transformed word must exist in the word list. 
2. Note that beginWord is not a transformed word.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

problem:
https://leetcode.com/problems/word-ladder/description/
	 */
	//求最短路径，用广搜
	//双队列
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
			return 0;

		set<string> visit; //存储遍历过的单词
		queue<string> q;
		queue<int> lev;
		q.push(beginWord);
		visit.insert(beginWord);
		lev.push(1);

		while(!q.empty()){ //BFS搜索
			string s = q.front();
			int lay = lev.front();
			q.pop();
			lev.pop();
			if(s == endWord) return lay;
			for(int i=0; i<wordList.size(); i++){ //遍历wordList
				if(nextTo(s, wordList[i]) && visit.find(wordList[i]) == visit.end()){ //if next to each other and not visit, add to the queue
					q.push(wordList[i]);
					lev.push(lay+1);
					visit.insert(wordList[i]);
				}
			}
		}

		return 0;
	}
	bool nextTo(string a, string b){ //判断两个单词是否相邻
		int res = 0;
		for(int i=0; i<a.length(); i++){
			if(a[i] != b[i]) res++;
			if(res>1) return false;
		}
		return res == 1;
	}

	/**
	 * 130. Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, 
which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
	 */
	void solve(vector<vector<char>>& board) {
        
    }
}
