/*
问题：
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].

*/

/*
思路：
这道题看上去有难度，但是分析一下会发现， 1 1,2 2,3 3,4 4,5 5,6 5,7 7
由于复制粘贴每次都是按照一个整体进行，所以实际上问题是要我们把一个数进行因数分解。
也就是一个简单的递归函数
*/

class Solution {
public:
    int minSteps(int n) {
        const int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
			41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		if (n <= 5)return n == 1 ? 0 : n;
		for (auto i : prime)
			if (n%i==0)
				return i + minSteps(n / i);
		return n;
    }
};