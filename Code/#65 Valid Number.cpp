/*
问题：
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

*/

/*
思路：
这道题的写法很值得学习……直接贴discuss中的代码了
*/

class Solution {
public:
   bool isNumber(string s) {
      int i = 0;
      for (;s[i] == ' ';i++) {}
      if (s[i] == '+' || s[i] == '-')i++;
      int num, dot;
      for (num = 0, dot = 0;(s[i] >= '0'&&s[i] <= '9') || s[i] == '.';i++) {
         s[i] == '.' ? dot++ : num++;
      }
      if (dot > 1 || num < 1)return false;
      if (s[i] == 'e') {
         i++;
         if (s[i] == '+' || s[i] == '-')i++;
         for (num = 0;s[i] >= '0'&&s[i] <= '9';i++) {
            num++;
         }
         if (num < 1)return false;
      }
      for (;s[i] == ' ';i++) {}
      return s[i] == 0;
   }
};