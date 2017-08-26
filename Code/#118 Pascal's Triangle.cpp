/*
问题：
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/*
思路：
杨辉三角，直接模拟一下就行了
*/

class Solution {
public:
   vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res;
      if (numRows == 0) return res;
      vector<int> tmp;
      vector<int> last_v;
      last_v.push_back(1);
      res.push_back(last_v);
      for (int i = 1;i < numRows;i++) {
         tmp.push_back(1);
         for (int j = 0; j < last_v.size() - 1;j++) {
            tmp.push_back(last_v[j] + last_v[j + 1]);
         }
         tmp.push_back(1);
         res.push_back(tmp);
         last_v = tmp;
         tmp.clear();
      }
      return res;
   }
};