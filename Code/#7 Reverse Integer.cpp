/*
���⣺
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

*/

/*
˼·��
֮ǰ������ȼ��������λ����Ȼ��һλһλ��ת�������Ǻ����ǵ�д��һ��������
for (int i = 1;abs(x / i) >= 1;i *= 10)
  length++;
��x����10e9��ʱ����һ��iӦ�ñ�Ϊ10e10�������Ѿ�������int��Χ������i����˺���ֵ�������
��ѭ����ʱ������nowҲԽ�磬���Ҳ��һֱwa��
����֮��Ĵ������£�
*/

class Solution {
public:
    int reverse(int x) {
        long res = 0;
	int length = 0;
	for (long i = 1;abs(x / i) >= 10;i *= 10)
	    length++;
	length++;
	for (int i = 1;i <= length;i++) {
	    int now = x / (int)pow(10, length - i) % 10 * pow(10, i - 1);
	    if (now/ pow(10, i - 1) != x / (int)pow(10, length - i)%10)return 0;
	    res = res + (now>0 ? now : -now);
	    if (res<INT_MIN || res>INT_MAX)return 0;
	}
	int sum = 0;
	sum = res;
	if (x<0) sum = -sum;
	return sum;
    }
};

/*
�����������£�
*/
class Solution {

public:

    int reverse(int x) {

        long res = 0;

	while(x){

            res = res*10+x%10;

            x /=10;

        }

	if (res<INT_MIN || res>INT_MAX)return 0;

	return res;
    
    }

};

