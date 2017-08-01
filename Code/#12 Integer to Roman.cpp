/*
���⣺
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/

/*
˼·��
���������е�4��9��Ҫ�ü�����ʾ��С���ڴ����ұ߱�ʾ�ӣ���߱�ʾ������������һ����7����ĸ��
һ���򵥵ĵݹ��⡣
*/

class Solution {
public:
    string res = "";
    string intToRoman(int num) {
	if (num == 0)return "";
	const int n[7] = { 1,	5,	10,	50,	100, 500, 1000 };
	const string c[7] = { "I","V","X","L","C","D","M" };
	int length = 0;
	for (;num / pow(10, length) >= 1;length++) {}
	for (int i = 6;i > -1;i--) {
	    int tmp = (int)(num / pow(10, length - 1));
	    if (num - n[i] >= 0 && (tmp %5 != 4)) {
		res += c[i];
		intToRoman(num - n[i]);
		break;
	    }
	    else if (tmp%5==4) {
		res += c[2 * length - 2];
		res += c[2 * length + tmp / 5 - 1];
		intToRoman(num - tmp*pow(10, length - 1));
		break;
	    }
	}
	return res;
    }
};