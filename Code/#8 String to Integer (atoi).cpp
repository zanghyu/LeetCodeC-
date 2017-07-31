/*
���⣺
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

*/

/*
˼·��
�������ʵ����һ�����࡭�����ǿ���atoi��Ҫ����
1.��ͷ�Ŀո�ȫ����ȥ
2.ֻ����һ��+�Ż�-�ţ�������һ����Ϊ0
3.����м��з����ֲ��֣���ò���֮�����ȥ
4.Խ�紦��

*/

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
	int j = 0;
	string strtmp = "";
	for (;j < str.size();j++) {
	    if (str[j] != ' ')break;
	}
	str = str.substr(j,str.size()-j);
	j = 0;
	for (;str[j] == '+' || str[j] == '-';j++) {
	    if (str[j] == '-')sign = -sign;
	}
	str = str.substr(j, str.size() - j);
	if (str == ""||j>1)return 0;
	strtmp = "";
	j = 0;
	for (;j < str.size();j++) {
	    if (str[j] >'9'||str[j]<'0')break;
	}
	str = str.substr(0, j);
	long long res = 0;
	long long tmp = 1;
	int flag = 0;
	for (int i = str.size()-1;i > -1;i--) {
	    res += (str[i] - '0')*tmp;
	    if (res > INT_MAX) {
		flag = 1;
		break;
	    }
   	    tmp *= 10;
	}
	if (sign==-1)res = -res;
	if (res <= INT_MIN&&flag)return INT_MIN;
	if (flag)return INT_MAX;
	return res;
    }
};
