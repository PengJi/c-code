/**
 * 广度优先搜索
 */
class Solution {
public：
	/**
	 * 126. Word Ladder II
Given two words (beginWord and endWord), and a dictionary's word list, 
find all shortest transformation sequence(s) from beginWord to endWord, such that:
Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

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
	 */
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) { 
    }
	
	/**
	 * 127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time.
Each transformed word must exist in the word list. 
Note that beginWord is not a transformed word.

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
}
