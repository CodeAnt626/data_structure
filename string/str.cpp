/*************************************************************************
	> File Name: str.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Thu 19 Nov 2020 07:16:23 PM CST
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

/*
const int maxSize = 100;

// 串的定长存储结构
typedef struct
{
    char str[maxSize + 1];
    int length;
}Str1;
*/
// 串的变长存储结构
typedef struct
{
    char *ch;
    int length;
}Str;

// 取串长度
int strLength(Str str);
// 串的赋值
int strAssign(Str& str, char* ch);
// 串的比较
int strCompare(Str s1, Str s2);
// 串的连接
int concat(Str& str, Str str1, Str str2);
// 求子串
int subString(Str& substr, Str str, int pos, int len);
// 清空串
int clearString(Str& str);
int main(){
    char str[20];
    char str2[20];
    strcpy(str, "Hello World!");
    strcpy(str2, "Hello World!");
    Str s;
    strAssign(s, str);
    cout << s.ch << endl;
    cout << strLength(s) << endl;
    return 0;
}

// 赋值操作
int strAssign(Str& str, char* ch) {
    if(str.ch) {
        free(str.ch);
    }
    int len = 0;
    char *c = ch;
    while(*c) {
        ++len;
        ++c;
    }
    if (len == 0) {
        str.ch = NULL;
        str.length = 0;
        return 1;
    } else {
        str.ch = (char *)malloc(sizeof(char) * (len + 1));
        if (str.ch == NULL) {
            return 0;
        } else {
            c = ch;
            for (int i = 0; i <= len; ++i, ++c) {
                str.ch[i] = *c;
            }
            str.length = len;
            return 1;
        }
    }
}

// 取长度
int strLength(Str str) {
    return str.length;
}

// 串的比较
int strCompare(Str s1, Str s2) {
    for (int i = 0; i < s1.length && i < s2.length; i++) {
        if (s1.ch[i] != s2.ch[i]) {
            return s1.ch[i] - s2.ch[i];
        }
    }
    return s1.length - s2.length;
}

// 串的连接
int concat(Str& str, Str str1, Str str2) {
    if(str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *)malloc(sizeof(char) * (str1.length + str2.length + 1));
    if (!str.ch) {
        return 0;
    }
    int i = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    for (int j = 0; j <= str2.length; j++) {
        str.ch[i + j] = str2.ch[j];
    }
    str.length = str1.length + str2.length;
    return 1;
}

// 求子串
// 从str串中取一个以pos为起点，长度为len的子串
int subString(Str& substr, Str str, int pos, int len) {
    if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)
        return 0;
    if (substr.ch) {
        free(substr.ch);
        substr.ch = NULL;
    }
    if (len == 0) {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    } else {
        substr.ch = (char *)malloc(sizeof(char) * (len + 1));
        int i = pos;
        int j = 0;
        while(i < pos + len) {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}

// 清空串
int clearString(Str& str) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    printf("ehl");
    return 1;
}
