/*
问题：
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/*
思路：
和上一道题基本一样，唯一不同是这道题中如果用上一道题的解法可能会产生重复的结果，因此在计算之后排序，将重复的部分删除就好了。
需要留意的是vector的删除重复部分的方法：
sort(res.begin(), res.end());
res.erase(unique(res.begin(), res.end()), res.end());

*/


class Solution {
public:
   int num = 0;
   void check(vector<int>& candidates, int target,vector<vector<int>>& res, vector<int>& now_res,int beg) {
      if (target == 0) {
         res.push_back(now_res);
         return;

      }
      for (int i = beg;i < candidates.size();i++) {
         if (candidates[i] > target)break;
         now_res.push_back(candidates[i]);
         check(candidates, target - candidates[i], res, now_res,i+1);
         now_res.pop_back();
      }
      return;
   }
   vector<vector<int>> combinationSum2(vector<int>& candidates, int target)  {
      vector<vector<int>> res;
      vector<int> now_res;
      sort(candidates.begin(),candidates.end());
      check(candidates, target, res, now_res,0);
      sort(res.begin(), res.end());
      res.erase(unique(res.begin(), res.end()), res.end());
      return res;
   }
};