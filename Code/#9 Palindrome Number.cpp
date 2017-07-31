/*
���⣺
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

/*
˼·��
��֮ǰ�����������ƣ�������Ҫ���ǵ���������Խ�縺��
���ڸ����и����ţ���˸����������ǻ�����
���жϻ��ĵ�ʱ�����ֻ����һ��ļ������ȫ����ת��������֤�˲���Խ��
���ڽ�β��0ʱ��ͷҲҪ��0�ſ��ԣ���˽�β��0������������
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x!=0&&x%10==0))return false;
        int res=0;
        while(x>res){
            res=res*10+x%10;
            x = x/10;
        }
        return (x==res)||(x==res/10);
    }
};