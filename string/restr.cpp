/*************************************************************************
	> File Name: restr.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Sat 28 Nov 2020 09:24:44 PM CST
 ************************************************************************/

// LeetCode题459：重复的子字符串

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.length() == 0) return false;
        get_next(s);
        int len = s.length();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
    void get_next(string s) {
        next = new int[s.length()];
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.length(); i++) {
            while (j >= 0 && s[j + 1] != s[i]) {
                j = next[j];
            }
            if (s[j + 1] == s[i]) {
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
