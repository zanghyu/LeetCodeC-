/*
问题：
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

*/

/*
思路：
这道题是格雷码，算是一道模拟题吧。主要是知道格雷码的规律
关于格雷码的构造：
https://baike.baidu.com/item/%E6%A0%BC%E9%9B%B7%E7%A0%81/6510858?fr=aladdin&fromid=11296193&fromtitle=Gray+code
里面很详细。

格雷码的数学解：
从第0个开始，第i个gray code为：(i>>1)^i
*/

class Solution {
public:
   vector<int> grayCode(int n) {
      vector<int> res;
      for (int i = 0;i < (1 << n);i++) {
         res.push_back((i >> 1) ^ i);
      }
      return res;
   }
};