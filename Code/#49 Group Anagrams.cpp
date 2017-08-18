/*
���⣺
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

/*
˼·��
���Ƚ�ͬһ�����Sortͳһ��һ���ַ�����Ȼ��map��
*/






class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>res;
		unordered_map<string, multiset<string>> mp;
		for (int i = 0;i < strs.size();i++) {
			string t = strs[i];
			sort(t.begin(), t.end());
			mp[t].insert(strs[i]);
		}
		for (auto val : mp) {
			vector<string>tmp(val.second.begin(),val.second.end());
			res.push_back(tmp);
		}
		return res;
	}
};