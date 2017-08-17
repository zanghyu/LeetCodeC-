/*
问题：

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/

/*
思路：
这道题涉及到了字符串匹配的问题。最开始我的做法如下：

class Solution {
public:
   bool match(string s, string p, int i, int j) {
      if (i == s.size() && j == p.size())return true;
      else if (i == s.size()) {
         for (int k = j;k < p.size();k++) {
            if (p[k] != '*')return false;
         }
         return true;
      }
      else if (j == p.size())return false;
      if (p[j] != '*'&&p[j] != '?') {
         if (s[i] != p[j])return false;
         else return match(s, p, i + 1, j + 1);
      }
      else if (p[j] == '*') {
         while (p[++j] == '*');
         for (int k = i;k < s.size();k++) {
            if (match(s, p, k, j))return true;
         }
         return match(s, p, s.size(), j);
      }
      else if (p[j] == '?') {
         return match(s, p, i+1, j+1);
      }
      return false;
   }
   bool isMatch(string s, string p) {
      return match(s, p, 0, 0);
   }
};


这个方法理论上是正确的，但是由于数据量很大，所以会TLE。因此采用了如下做法。
下面的做法来自博客：
http://www.cnblogs.com/felixfang/p/3708999.html
里面有详解
*/

bool isMatch(const char *s, const char *p) {
        const char *presp = NULL, *press = NULL;    //previous starting comparison place after * in s and p.
        bool startFound = false;
        while(*s != '\0'){
            if(*p == '?'){++s; ++p;}
            else if(*p == '*'){
                presp = ++p;
                press = s;
                startFound = true;
            }else{
                if(*p == *s){
                    ++p;
                    ++s;
                }else if(startFound){
                    p = presp;
                    s = (++press);
                }else return false;
            }
        }
        while(*p == '*') ++p;
        return *p == '\0';
}