/*
���⣺
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/

/*
˼·��
����Ȿ���ѣ�������������ϡ�
��Ŀ��˼��˵��n�������������һ�����Ķ������������3��˵����2:11������2��1�������21��
����4��˵��3�Ķ�����1��2,1��1�������1211
*/

class Solution {
public:
   string result(string last) {
      string str = "";
      int number = 1;
      for (int i = 0;i < last.size()-1;i++) {
         if (last[i] == last[i + 1]) {
            number++;
         }
         else {
            str = str + (char)(number + '0') + last[i];
            number = 1;
         }
      }
      str = str + (char)(number + '0') + last[last.size()-1];
      return str;
   }
   string countAndSay(int n) {
      string str;
      str = "1";
      for (int i = 0;i < n-1;i++) {
         str = result(str);
      }
      return str;
   }
};