/*
问题：
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
思路：
这道题本身不难，难在理解题意上。
题目意思是说第n个串代表的是上一个串的读法，比如对于3来说，串2:11，代表2个1，因此是21。
对于4来说，3的读法是1个2,1个1，因此是1211
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