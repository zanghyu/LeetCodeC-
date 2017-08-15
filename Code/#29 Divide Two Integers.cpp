/*
问题：
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

/*
思路：
注意一点：当输入的int已经是边界值时，abs函数不起作用。因此应该用
long long dd=abs((long long)dividend)
这种形式

这道题是一道二分的题目，用二进制的移位操作可以得出结果。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
	long long dd = abs((long long)dividend), dr = abs((long long)divisor);
	long long result = 0;
	if (dividend == INT_MIN && divisor == -1)return INT_MAX;
	while (dd >= dr) {
	    long long tmp = dr;
	    long long cnt = 1;
	    while (tmp << 1 < dd) {
		tmp <<= 1;
		cnt <<= 1;
	    }
	    result += cnt;
	    dd -= tmp;
	}
	if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
	    return result;
	}
	else return -result;
    }
};