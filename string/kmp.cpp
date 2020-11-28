/*************************************************************************
	> File Name: kmp.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Sat 28 Nov 2020 03:50:57 PM CST
 ************************************************************************/

// KMP算法

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
        next[0] = -1;
        for (int i = 1, match = -1; i < value.length(); i++) {
            while (match >= 0 && value[match + 1] != value[i]) {
                match = next[match];
            }
            if (value[match + 1] == value[i]) {
                match++;
            }
            next[i] = match;
        }
    }
    int match(const string &buffer) const {
        for (int i = 0, match = -1; i < buffer.length(); i++) {
            while (match >= 0 && value[match + 1] != buffer[i]) {
                match = next[match];
            }
            if (value[match + 1] == buffer[i]) {
                match++;
            }
            if (match == value.length() - 1) {
                return i - match;
            }
        }
        return -1;
    }
};

int main() {
    string str_buffer, str_pattern;
    cin >> str_buffer >> str_pattern;
    StringPattern pattern(str_pattern);
    int location = pattern.match(str_buffer);
    if (location != -1) {
        cout << "match success, location is " << location << endl;
    } else {
        cout << "match failed!" << endl;
    }
    return 0;
}
