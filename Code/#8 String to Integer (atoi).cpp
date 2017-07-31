/*
问题：
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

*/

/*
思路：
这道题其实和上一道题差不多……但是坑在atoi的要求上
1.开头的空格全部略去
2.只能有一个+号或-号，若多余一个则为0
3.如果中间有非数字部分，则该部分之后的略去
4.越界处理

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
