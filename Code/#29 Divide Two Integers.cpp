/*
���⣺
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

/*
˼·��
ע��һ�㣺�������int�Ѿ��Ǳ߽�ֵʱ��abs�����������á����Ӧ����
long long dd=abs((long long)dividend)
������ʽ

�������һ�����ֵ���Ŀ���ö����Ƶ���λ�������Եó������
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