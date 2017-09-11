/*
问题：
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
思路：
这道题有两种解法，第一种就是二分：
*/

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = (x / 2) + 1;
        while (left <= right) {
            long long mid = (left + right) / 2;           
            if (mid * mid == x) return mid;
            else if (mid * mid < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

/*
第二种方法就是利用牛顿迭代法，记得高数中好像讲到过这个方法，是用逼近法求方程根的神器，在这里也可以借用一下，可参见博客：
http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html

因为要求x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，可以求出递推式如下：
xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2
*/

class Solution {
public:
	int mySqrt(int x) {
	    long r = x;
        while(r*r>x){
            r = (r+x/r)/2;
        }
        return r;
	}
};
