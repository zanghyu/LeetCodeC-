/*
���⣺
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

/*
˼·��
дһ���ַ���ƥ���ʵ�ֺ��������õ���ͨ����ʵ�ֵģ���Ȼ��������kmp,sunday�ȷ�ʽʵ�֡�
�����Ǽ򵥽��ܼ����ַ���ƥ�䷽���Ĳ��ͣ�
http://doc.okbase.net/Syhawk/archive/110838.html
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
	if (needle.size() == 0)return 0;
	int pos = -1;
	for (int i = 0;i < haystack.size();i++) {
	    int j = 0;
	    for (;j < needle.size();j++) {
		if (haystack[i + j] != needle[j])break;
	    }
	    if (j == needle.size()) 
		pos = i;
	    if (pos!= -1)break;
	}
	return pos;
    }
};

/*
������sunday�㷨��ʵ�֣�
*/

class Solution {
public:
    int strStr(string hay, string need) {
        char* haystack = new char[hay.size()];
	char* needle = new char[need.size()];
	strcpy(haystack, hay.c_str());
	strcpy(needle, need.c_str());
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
	int charStep[256];
	for (int i = 0; i < 256; ++i)
	    charStep[i] = -1;
	for (int i = 0; i < len2; ++i)
	    charStep[(int)needle[i]] = i;
	    for (int i = 0; i <= len1 - len2;){
	        int j = 0;
		while (j < len2) {
		    if (haystack[i] == needle[j]) {
			++i;
			++j;
		    } else {
		    	char* p = haystack + i + len2 - j;
		    	if (charStep[(int)*p] == -1) {
			    i = p - haystack + 1;
		    	} else {
			    i = p - charStep[(int)*p] - haystack;
		        }
		        break;
		    }
		}
		if (j == len2) {
		    return i - len2;
		}
	}
	return -1;
    }
};