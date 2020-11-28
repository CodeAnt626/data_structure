/*************************************************************************
	> File Name: kmp_review.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Sat 28 Nov 2020 03:54:49 PM CST
 ************************************************************************/

// 对KMP算法的复习

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class StringPattern {
private:
    string value;
    int *next;
public:
    StringPattern(const string &input) {
        value = input;
        next = new int[input.length() + 1];
        get_next();
    }
    ~StringPattern() {
        delete[] next;
    }
    void get_next() {
        next[0] = 0;
        int j = 0;      // j 表示前缀末尾 i 表示后缀末尾
        for (int i = 1; i < value.length(); i++) {
            while (j > 0 && value[i] != value[j]) {
                j = next[j - 1];
            }
            if (value[i] == value[j]) j++;
            next[i] = j;
        }
    }
    int find(const string &str) {
        for (int i = 0, j = 0; i < str.length(); i++) {
            while(j > 0 && value[j] != str[i]) {
                j = next[j - 1];
            }
            if (value[j] == str[i]) {
                j++;
            }
            if (j == value.length()) {
                return i - j + 1;
            }
        }
        return -1;
    }
};

int main() {
    string str;
    string val;
    cin >> str >> val;
    StringPattern str1(val);
    if (str1.find(str) != -1) {
        cout << "Yes" << endl << str1.find(str) << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
