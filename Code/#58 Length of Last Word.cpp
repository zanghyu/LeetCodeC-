/*
问题：

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

/*
思路：
很简单的一道题
*/

class Solution {
public:
   int lengthOfLastWord(string s) {
      int tmp = 0;
      for (int i = s.length() - 1;i > -1;i--) {
         if (tmp &&s[i] == ' ')return tmp - 1 - i;
         else if (!tmp && s[i] != ' ')tmp = i + 1;
      }
      if (tmp)return tmp;
      return 0;
   }
};