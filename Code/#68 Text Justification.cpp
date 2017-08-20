/*
���⣺
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

/*
˼·��
������ǵ�ģ����⣬��Ҫ������жϡ����ȷ������࣬ĩ�кͷ�ĩ�У�Ȼ��ĩ�����е��ʼ��һ���ո�����油��ո񣻷�ĩ���ٷ����࣬���ֻ��һ�����ʾͿ���ţ��ұ߲��ո�����ж�����ʣ��������м������num�ͼ�������Ŀո�extra����ÿ�������ʼ�һ���ո������ģ���ÿ������ٶ෽extra/num����ǰextra%num������ٶ�Ÿ��ո�
*/

class Solution {
public:
   vector<string> fullJustify(vector<string>& words, int maxWidth) {
      if (words.empty())return{};
      if (maxWidth == 0)return words;
      int n = words.size();
      int sumWidth = 0;
      vector<vector<string>> spl;
      vector<string>res;
      vector<string>tmp;
      for (int i = 0;i < n;i++) {
         if (sumWidth + words[i].length() > maxWidth) {
            spl.push_back(tmp);
            sumWidth = 0;
            tmp.clear();
         }
         sumWidth += words[i].length()+1;
         tmp.push_back(words[i]);
      }
      if (!tmp.empty())spl.push_back(tmp);
      for (int i = 0;i < spl.size();i++) {
         if (spl[i].empty())continue;
         sumWidth = 0;
         for (int j = 0;j < spl[i].size();j++) {
            sumWidth += spl[i][j].length();
         }
         int spaceWidth = maxWidth - sumWidth;
         int eachspaceWidth;
         if (spl[i].size() != 1) {
            eachspaceWidth = spaceWidth / (spl[i].size() - 1);
         }
         else eachspaceWidth = spaceWidth;
         string str = "";
         if (i == spl.size() - 1) {
            for (int j = 0;j < spl[i].size();j++) {
               str += spl[i][j];
               if (j == spl[i].size() - 1)break;
               str += " ";
               spaceWidth -= 1;
            }
            for (int k = 0;k < spaceWidth;k++)str += " ";
            res.push_back(str);
            break;
         }
         int num = spaceWidth - eachspaceWidth* (spl[i].size() - 1);
         for (int j = 0;j < spl[i].size()-1;j++) {
            str += spl[i][j];
            for (int k = 0;k < eachspaceWidth;k++)str += " ";
            if (j < num)str += " ";
         }
         str += spl[i][spl[i].size() - 1];
         if (spl[i].size() == 1) {
            for (int k = 0;k < eachspaceWidth;k++)str += " ";
         }
         res.push_back(str);
      }
      return res;
   }
};