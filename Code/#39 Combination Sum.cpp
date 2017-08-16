/*
���⣺
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

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
*/

/*
˼·��
�����Ҳ�ǿ���ݹ飬�ص�������ô���ܱ�֤ÿ�������¼��һ��vector�������������Ҫ�ظ������Ρ�����ʼλ����Ϊ�������뵽ѭ�������У�ֵ�����⡣

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
         check(candidates, target - candidates[i], res, now_res,i);
         now_res.pop_back();
      }
      return;
   }
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> now_res;
      sort(candidates.begin(),candidates.end());
      check(candidates, target, res, now_res,0);
      return res;
   }
};