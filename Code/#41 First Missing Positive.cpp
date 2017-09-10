/*
���⣺
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

/*
˼·��
���ǵ�˼·�ǰ�1���������һ��λ��A[0]��2���ڵڶ���λ��A[1]������Ҫ��A[i]����A[A[i] - 1]�ϣ���ô���Ǳ����������飬���A[i] != i + 1, ��A[i]Ϊ�����Ҳ�����n������A[i]������A[A[i] - 1]�Ļ������ǽ�����λ�õ����������������������ֱ����������������ٱ���һ�����飬�����Ӧλ���ϵ�������ȷ�򷵻���ȷ����
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