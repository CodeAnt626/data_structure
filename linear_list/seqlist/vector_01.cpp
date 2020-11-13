/*************************************************************************
	> File Name: vector.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Fri 13 Nov 2020 09:58:49 PM CST
 ************************************************************************/

/*
 * 顺序表构造、插入、扩容
 *
 *
 * 输入格式
 *  
 * 第一行输入一个整数 n（1≤n≤100），表示一共有 n 个插入操作。
 * 接下来输入 n 行，每行输入两个整数 p，q（0≤p,q≤100），p 代表元素插入顺序表的位置，q 代表插入元素的值，之间用一个空格隔开。
 *  
 * 输出格式
 *  
 * 输出若干行，对应每一个插入操作。如果一个元素正确插入到顺序表中后，程序输出success，否则输出failed。如果插入过程中有执行了扩容操作，程序需要额外输出expand。
 */

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size, length;
    Type *data;
public:
    Vector(int size_num) {
        size = size_num;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, Type value) {
        if (loc < 0 || loc > length) { return false; }
        if (length >= size) { expand(); }
        for (int i = length; i > loc; i--) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void expand() {
        Type *old_data;
        old_data = data;
        size = size * 2;
        data = new Type[size];
        for (int i = 0; i < length; i++) {
            data[i] = old_data[i];
        }
        delete[] old_data;
        cout<<"expand"<<endl;
    }
};
int main() {
    Vector<int> a(5);
    int n;
    cin>>n;
    int p, q;
    for (int i = 0; i < n; i++) {
        cin>>p>>q;
        if (a.insert(p, q)) {
            cout<<"success"<<endl;
        } else {
            cout<<"failed"<<endl;
        }
        
    }

    return 0;
}
