/*
问题：
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
思路：
二分
*/

class Solution {
public:
   int mySqrt(int x) {
      long long left = 0, right = x;
      if (x == 1)return 1;
      while (left < right) {
         int mid = (left + right) / 2;
         if (mid*mid < x) {
            left = mid;
            if (mid == (left + right) / 2)return left;
         }
         else if (mid*mid > x) {
            right = mid;
            if (mid == (left + right) / 2)return right;
         }
         else return mid;
      }
      return left;
   }
};