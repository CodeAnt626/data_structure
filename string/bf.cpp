/*************************************************************************
	> File Name: bf.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Sat 28 Nov 2020 02:59:29 PM CST
 ************************************************************************/

// BF算法

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class StringPattern {
private:
    string value;
public:
    StringPattern(const string &input) {
        value = input;
    }
    int match(const string &buffer) const {
        for (int i = 0; i <= buffer.length() - value.length(); i++) {
            int j = 0;
            for (; j < value.length(); j++) {
                if (buffer[i+j] != value[j]) {
                    break;
                }
            }
            if (j == value.length()) {
                    return i;
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
