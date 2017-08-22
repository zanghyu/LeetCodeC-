/*
问题：
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

/*
思路：
又是列出所有可能情况的题目，这种情况一般都是递归去做。
*/

class Solution {
public:
   vector<string> restoreIpAddresses(string s) {
      vector<string>res;
      restore(res, s, 4, "");
      return res;
   }
   void restore(vector<string>& res, string s, int k, string output) {
      if (k == 0) {
         if (s.empty())res.push_back(output);
      }
      else {
         for (int i = 1;i <= 3;i++) {
            if (s.size() >= i && isvalid(s.substr(0, i))) {
               if (k == 1)restore(res, s.substr(i), k - 1, output + s.substr(0, i));
               else restore(res, s.substr(i), k - 1, output + s.substr(0, i) + ".");
            }
         }
      }
   }
   bool isvalid(string s) {
      if (s.empty() || s.size() > 3 || (s.size() > 1 &&s[0] == '0'))return false;
      int ok = atoi(s.c_str());
      return ok <= 255 && ok >= 0;
   }
};