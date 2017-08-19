/*
问题：
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

/*
思路：
很简单的题
*/

class Solution {
public:
   vector<int> plusOne(vector<int>& digits) {
      int add = 1;
      for (int i = digits.size() - 1;i > -1;i--) {
         int tmp = (digits[i] + add) / 10;
         digits[i] = (digits[i] + add) % 10;
         add = tmp;
      }
      if (add) {
         digits.insert(digits.begin(), add);
      }
      return digits;
   }
};