/* �����ûɶ��˵�ģ����Ǽ򵥵�����ѭ��
*  ֵ���������vector���÷���vector����ֵ�ǵ���insert����
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size();i++) {
			for (int j = 0;j < i; j++) {
				if (nums.at(i) + nums.at(j) == target) {
					vector<int> res;
					res.insert(res.end(),j);
					res.insert(res.end(),i);
					return res;
				}
			}
		}
    }
};