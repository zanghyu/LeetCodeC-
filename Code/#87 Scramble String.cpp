/*
问题：
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/*
思路：
遇到这种需要遍历所有情况的题一般都是递归。这道题也是，s1和s2串各分两部分，然后再往下两两比较。
*/

class Solution {
public:
   bool isScramble(string s1, string s2) {
      if (s1.empty() && s2.empty())return true;
      if (s1 == s2)return true;
      string str1 = s1, str2 = s2;
      sort(str1.begin(), str1.end());
      sort(str2.begin(), str2.end());
      if (str1 != str2)return false;
      for (int i = 1;i < s1.size();i++) {
         if (isScramble(s1.substr(0, i), s2.substr(0, i))
            && isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) return true;
         else if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i,i))
            && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i))) return true;
      }
      return false;
   }
};