/*
���⣺
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

/*
˼·��
��һ�����ϴ洢���֣��鵽һ�����ֺ���������ɾ�������ȸ����ִ�һ����Сһ���Ƿ��������У�����ھ�ɾ�������ĳ�����next-pre-1����������ġ�
*/

class Solution {
public:
   int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(),nums.end());
      int pre, next;
      int res = 0;
      for (int val : nums) {
         if (!s.count(val)) {
            continue;
         }
         s.erase(val);
         pre = val - 1, next = val + 1;
         while (s.count(pre)) {
            s.erase(pre);
            pre--;
         }
         while (s.count(next)) {
            s.erase(next);
            next++;
         }
         res = max(res, next - pre - 1);
      }
      return res;
   }
};