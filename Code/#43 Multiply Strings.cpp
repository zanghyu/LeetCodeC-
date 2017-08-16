/*
问题：
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

/*
思路：
很简单的一道题，只要理清思路一步一步写就好。
*/

class Solution {
public:
   string addstr(string str1, string str2) {
      string str = "";
      int len = str1.length() > str2.length() ? str2.length() : str1.length();
      int add = 0;
      for (int i = 0;i < len;i++) {
         int num = (str2[i] - '0')+(str1[i] - '0');
         str += (char)((add + num) % 10 + '0');
         add = (add+num) / 10;
      }
      if (str1.length() > str2.length()) {
         for (int i = len;i < str1.length();i++) {
            str = str + (char)((add+str1[i]-'0')%10+'0');
            add = (add + str1[i]-'0') / 10;
         }
      }
      if (str1.length() < str2.length()) {
         for (int i = len;i < str2.length();i++) {
            str = str + (char)((add+str2[i]-'0')%10+'0');
            add = (add + str2[i]-'0') / 10;
         }
      }
      if (add != 0)str += (char)(add + '0');
      return str;
   }
   string multiply(string num1, string num2) {
      string res = "";
      string str = "";
      for (int i = num1.size() - 1;i > -1;i--) {
         int add = 0;
         for (int k = 0;k < num1.size() - 1 - i;k++) {
            str += "0";
         }
         for (int j = num2.size() - 1;j > -1;j--) {
            int num = (num2[j] - '0')*(num1[i] - '0');
            str += (char)((add + num) % 10 + '0');
            add = (add+num) / 10;
         }
         if (add != 0)str += (char)(add + '0');
         res = addstr(res, str);
         str = "";
      }
      reverse(res.begin(), res.end());
      int x = 0;
      for (;x < res.size();x++) {
         if (res[x] != '0')break;
      }
      if (x >= res.size())
         return "0";
      else res = res.substr(x, res.size() - x);
      return res;
   }
};