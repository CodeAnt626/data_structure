/*************************************************************************
	> File Name: solution.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Sat 28 Nov 2020 08:01:32 PM CST
 ************************************************************************/

// LeetCode 题28 实现strStr()

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) { return 0; }
        get_next(needle);
        for (int i = 0,j = 0; i < haystack.length(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.length()) {
                return i - j + 1;
            }
        }
        return -1;
    }
    void get_next(string s) {
        next = new int[s.length()];
        int j = 0;      // j 表示前缀末尾   i 表示后缀末尾
        next[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    ~Solution() {
        delete[] next;
    }
private:
    int *next;
};

int main() {
	Solution so;
    cout << so.strStr("mississippi", "issipi") << endl;
}
