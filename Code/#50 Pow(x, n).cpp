/*
问题：
Implement pow(x, n).
*/

/*
思路：
二分
*/

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)return 1;
		int t = abs(n);
		int k = 1;
		double res = x;
		while (t > 1) {
			res *= res;
			t /= 2;
			k *= 2;
		}
		res *= myPow(x, abs(n) - k);

		if (n < 0)res = 1 / res;
		return res;
	}
};