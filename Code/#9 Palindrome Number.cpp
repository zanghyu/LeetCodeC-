/*
问题：
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

/*
思路：
和之前两题依旧类似，但是需要考虑到的问题是越界负数
由于负数有个符号，因此负数不可能是回文数
而判断回文的时候可以只进行一半的计算而不全部翻转，这样保证了不会越界
由于结尾是0时开头也要是0才可以，因此结尾是0的数都不符合
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