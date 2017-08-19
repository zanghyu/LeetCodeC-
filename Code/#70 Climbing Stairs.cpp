/*
���⣺
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

/*
˼·��
����ÿ��ֻ����1��2�������f(n) = f(n-1)+f(n-2)��������쳲��������С����������ݹ��д����TLE�����õݹ��д������AC��
*/

class Solution {
public:
	int f(int n) {
		int num1 = 1;
		int num2 = num1;
		int num3 = num1;
		while (n > 2) {
			num3 = num1 + num2;
			num1 = num2;
			num2 = num3;
			n--;
		}
		return num3;
	}
	int climbStairs(int n) {
		return f(n+1);
	}
};