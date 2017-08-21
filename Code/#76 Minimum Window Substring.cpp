/*
���⣺
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/*
˼·��
����⽨�鿴discuss��������һ��10�е�ģ��ֵ��ѧϰ��
����������´��룺
���������ͨ����ϣ������������һ����ϣ����ϣ��ӳ�������ĸ�ͳ���Ƶ�ʡ���ʼ��֮�󣬹���һ������������ʼֵΪt�ĳ��ȡ���s�ַ����ĵ�һ��λ����endָ����ƣ�ÿ������һ��t�е���ĸʱ��������-1����������Ϊ0��Ҳ����t�е���ĸȫ�����ֹ�һ��֮�󣬸�����С�ľ���d��beg�������ƶ�startָ�룬����ʱ��startλ�õ���ĸ��t�е���ĸʱ����������һ���������ѭ����end���������ƣ�����ʱ��startλ�õ���ĸ����t�е���ĸʱ���ͼ��������ƶ�start��
*/

class Solution {
public:
   string minWindow(string s, string t) {
      vector<int>map(128, 0);
      for (auto c : t)map[c]++;
      int d = 1e8, end = 0, start = 0, counter = t.size(),beg;
      while (end < s.size()) {
         if (map[s[end++]]-- > 0)counter--;
         while (counter == 0) {
            if (end - start < d) {
               d = end - start;
               beg = start;
            }
            if (map[s[start++]]++ == 0)counter++;
         }
      }
      return d == 1e8 ? "" : s.substr(beg, d);
   }
};

/*
�����������������������Ӵ���ģ������
*/
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
}
