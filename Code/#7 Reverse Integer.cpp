/*
问题：
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

*/

/*
思路：
之前想的是先计算该数的位数，然后一位一位反转……但是很弱智的写了一个函数：
for (int i = 1;abs(x / i) >= 1;i *= 10)
  length++;
当x大于10e9的时候，下一次i应该变为10e10，但是已经超过了int范围，所以i变成了很奇怪的数……
在循环的时候由于now也越界，因此也在一直wa。
改完之后的代码如下：
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
精简版代码如下：
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
