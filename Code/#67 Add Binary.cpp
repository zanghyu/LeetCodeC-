/*
问题：
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
思路：
主要的问题在如何将int转化成二进制字符串，从网上看到一个思路是 利用十进制转二进制的过程，除以2，余数代表该位置上的二进制数。
但是如果直接进行计算到很大的时候回TLE，因此用分治的思想处理。
*/

class Solution {
public:
   string addBinary(string a, string b) {
      int i = a.size() - 1, j = b.size() - 1;
      string res = "";
      int c = 0;
      while (i >= 0 || j >= 0 || c == 1) {
         c += i >= 0 ? (int)(a[i--] - '0') : 0;
         c += j >= 0 ? (int)(b[j--] - '0') : 0;
         res = (char)(c % 2 + '0') + res;
         c = c / 2;
      }
      return res;
   }
};