/*
���⣺
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?


*/

/*
˼·��
�����Ĺؼ�����ֻ��o(k)�Ŀռ䣬�������ģ��ķ�ʽ���ռ�ͳ��ˡ����ÿ��ֻ�洢һ�����ݣ����ݵ�ǰ�в��ϸ�����ֵ��
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