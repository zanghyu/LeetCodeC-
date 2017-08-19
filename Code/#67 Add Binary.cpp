/*
���⣺
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
˼·��
��Ҫ����������ν�intת���ɶ������ַ����������Ͽ���һ��˼·�� ����ʮ����ת�����ƵĹ��̣�����2�����������λ���ϵĶ���������
�������ֱ�ӽ��м��㵽�ܴ��ʱ���TLE������÷��ε�˼�봦��
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