/*
问题：
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

/*
思路：
我们的思路是把1放在数组第一个位置A[0]，2放在第二个位置A[1]，即需要把A[i]放在A[A[i] - 1]上，那么我们遍历整个数组，如果A[i] != i + 1, 而A[i]为整数且不大于n，另外A[i]不等于A[A[i] - 1]的话，我们将两者位置调换，如果不满足上述条件直接跳过，最后我们再遍历一遍数组，如果对应位置上的数不正确则返回正确的数
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n) {
            if (A[i] != i + 1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            } 
            else {
                ++ i;
            }
        }
        for (i = 0; i < n; ++i) {
            if (A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};