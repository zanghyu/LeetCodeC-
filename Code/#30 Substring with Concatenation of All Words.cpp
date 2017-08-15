/*
问题：
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
思路：
这道题用到了unordered_map，用一个map保存每个word出现的次数，若所有的均连续出现，则将该初始位置放入数组。
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
	vector<int>res;
	unordered_map<string, int> counts;
	for (string word : words) {
	    counts[word]++;
	}
	int num = words.size(), length = words[0].length();
	for (int i = 0;i < s.length() - num*length + 1;i++) {
	    int j = 0;
	    unordered_map<string, int>show;
	    for (;j < num;j++) {
		string str = s.substr(i + j*length, length);
		if (counts.find(str) != counts.end()) {
		    show[str]++;
		    if (show[str] > counts[str]) break;
		}
		else break;
	    }
	    if (j == num)res.push_back(i);
	}
	return res;
    }
};