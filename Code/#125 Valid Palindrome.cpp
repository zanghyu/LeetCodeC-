/*
问题：
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

/*
思路：
只保留字母和数字，其他字符都去掉，剩下的判断一下是否回文
*/

class Solution {
public:
   bool isPalindrome(string s) {
      if (s.empty())return true;
      string str;
      for (int i = 0;i < s.length();i++) {
         if (s[i] >= 'a'&&s[i] <= 'z') {
            str += s[i];
         }
         else if (s[i] >= 'A'&&s[i] <= 'Z') {
            str += (char)(s[i]+32);
         }
         else if (s[i] >= '0'&&s[i] <= '9') {
            str += s[i];
         }
      }
      string t = "";
      for (int i = str.length() - 1;i > -1;i--) {
         t += str[i];
      }
      return str == t ? true : false;
   }
};