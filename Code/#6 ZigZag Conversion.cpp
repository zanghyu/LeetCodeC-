/*
问题：
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


*/

/*
思路1：
这道题也是17年北理夏令营的机试题第二题。我的思路就是把字母看成是位置，然后稍微推导一下就可以得出结论。
比如原题中的：
1      7
2    6   8
3  5       9
4           10
可以看出变化和列数有关，第一行每次+6，第二行按照+4 +2，第三行按照+2 +4，第四行按照+6
因此可以得出结论
*/

class Solution {
public:
    string convert(string s, int numRows) {
        string str = "";
        if (numRows==1)return s;
        for(int i = 0;i < numRows;i++) {
            int pos = i;
            int x = 2 * (numRows - 1) - 2 * i, y = 2 * i;
            str+=s[pos];
            while (true) {
                if (x != 0&&pos+x<s.size())str+=s[pos+x];
                pos = pos + x;
                if(pos > s.size())break;
                if (y != 0&&pos+y<s.size())str+=s[pos+y];
                pos += y;
                if (pos > s.size())break;
            }
        }
        return str;
    }
};

/*
思路2：
例子中的字符串可以被写成这种形式：
P.......A........H.......N
..A..P....L..S....I...I....G
....Y.........I........R

因此ABCD可以写成：
A....C
...B....D

*/
class Solution {
public:
   string convert(string s, int nRows) {
    
    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
   }
};