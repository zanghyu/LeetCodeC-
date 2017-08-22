/*
���⣺
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
˼·��
������Ǹ����룬����һ��ģ����ɡ���Ҫ��֪��������Ĺ���
���ڸ�����Ĺ��죺
https://baike.baidu.com/item/%E6%A0%BC%E9%9B%B7%E7%A0%81/6510858?fr=aladdin&fromid=11296193&fromtitle=Gray+code
�������ϸ��

���������ѧ�⣺
�ӵ�0����ʼ����i��gray codeΪ��(i>>1)^i
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