/*
问题：

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
思路：
和#15 3Sum 思路基本类似

*/

class Solution {
public:
	int threeSumClosest(vector<int>& num, int target) {
            if(num.size()==3)return num[0]+num[1]+num[2];
            if(num.size()<3)return 0;
	    int res;
	    sort(num.begin(), num.end());
	    int Min = 1e8;
	    for (int i = 0;i < num.size()-2;i++) {
		int front = i + 1;
		int back = num.size() - 1;
		while (front < back) {
		    int sum = num[front] + num[back] + num[i];
                    if (abs(sum - target) < Min) {
			Min = abs(sum - target);
			res = sum;
		    }
                    if(sum == target)return sum;
		    if (sum > target) {
			back--;
		    }
		    else if (sum < target) {
			front++;
		    }
				
	        }
                while(i>0&&num[i+1]==num[i])i++;
	    }
	    return res;

	}
};