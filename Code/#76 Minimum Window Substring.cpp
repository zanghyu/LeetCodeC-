/*
问题：
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/*
思路：
这道题建议看discuss，里面有一个10行的模板值得学习。
在这里分析下代码：
首先这道题通过哈希表来做，构建一个哈希表，哈希表映射的是字母和出现频率。初始化之后，构造一个计数器，初始值为t的长度。从s字符串的第一个位置起，end指针后移，每次遇到一个t中的字母时，计数器-1。当计数器为0，也就是t中的字母全部出现过一次之后，更新最小的距离d和beg，并且移动start指针，当此时的start位置的字母是t中的字母时，计数器加一，弹出这个循环，end继续往后移；当此时的start位置的字母不是t中的字母时，就继续往后移动start。
*/

class Solution {
public:
   string minWindow(string s, string t) {
      vector<int>map(128, 0);
      for (auto c : t)map[c]++;
      int d = 1e8, end = 0, start = 0, counter = t.size(),beg;
      while (end < s.size()) {
         if (map[s[end++]]-- > 0)counter--;
         while (counter == 0) {
            if (end - start < d) {
               d = end - start;
               beg = start;
            }
            if (map[s[start++]]++ == 0)counter++;
         }
      }
      return d == 1e8 ? "" : s.substr(beg, d);
   }
};

/*
遇到这种找有限制条件的子串的模板如下
*/
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
}
