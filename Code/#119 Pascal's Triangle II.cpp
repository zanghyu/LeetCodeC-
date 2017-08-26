/*
问题：
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?


*/

/*
思路：
这道题的关键在于只用o(k)的空间，如果按照模拟的方式，空间就超了。因此每次只存储一行数据，根据当前行不断更改数值。
*/

class Solution {
public:
   vector<int> getRow(int rowIndex) {
      vector<int> vi(rowIndex + 1);
      vi[0] = 1;
      for (int i = 0; i <= rowIndex; ++i){
         for (int j = i; j > 0; --j){
            vi[j] = vi[j] + vi[j - 1];
         }
      }
      return vi;
   }
};