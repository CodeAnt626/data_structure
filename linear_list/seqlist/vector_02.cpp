/*************************************************************************
	> File Name: vector_02.cpp
	> Author: CodeAnt626
	> Mail: PohZero_Luo@163.com
	> Created Time: Fri 13 Nov 2020 11:17:10 PM CST
 ************************************************************************/
/*
 * 输入格式
 *
 * 第一行输入一个正整数 m（1≤m≤100），代表一共有 m 个操作。
 *
 * 接下来输入 m 行，每行首先输入一个整数 t，分别代表以下操作：
 *
 * t=1，代表插入操作，输入两个整数 a 和 b（0≤a,b≤100），表示在 a 的位置上擦入元素 b，如果插入成功输出success，否则输出failed。
 * t=2，代表删除操作，输入一个整数 a（0≤a≤100），删除位置 a 上的元素，如果删除成功输出success，否则输出failed。
 * t=3，代表查找操作，输入一个整数 a（0≤a≤100），查找元素值为 a 的元素，如果查找成功输出success，否则输出failed。
 * t=4，代表遍历操作，输出当前顺序表的所有元素。
 *
 * 输出格式
 *
 * 对应每个操作，输出结果。对于前三个操作，如果操作成功输出success，否则输出failed；
 * 对于第四个操作，从下标为0的位置开始输出当前顺序表的所有元素，每两个整数之间一个空格，最后一个整数后面没有空格。
 *
 */
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size;
    int length;
    Type *data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, Type value) {
        if (loc < 0 || loc > length) {return false;}
        if (length >= size) {expand();}
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
    }
    bool search(const Type &value) {
        for (int i = 0; i < length; i++) {
            if (data[i] == value) { return true;}
        }
        return false;
    }
    bool remove(int loc) {
        if (loc < 0 || loc >= length) {return false;}
        for (int i = loc; i < length; i++) {
            data[i] = data[i + 1];
        }
        length--;
        return true;
    }
    void print() {
        for (int i = 0; i < length; i++) {
            cout<<data[i];
            if (i != length - 1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
};
int main() {
    Vector<int> v(20);
    int m;
    cin>>m;
    int t[m], a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin>>t[i];
        if (t[i] == 1) {
            cin>>a[i]>>b[i];
        } else if(t[i] == 4){
        } else {
            cin>>a[i];
        }
    }
    for (int i = 0; i < m; i++) {
        switch(t[i]) {
            case 1:
                if (v.insert(a[i], b[i])) {
                    cout<<"success"<<endl;
                } else {
                    cout<<"failed"<<endl;
                }
                break;
            case 2:
                if (v.remove(a[i])) {
                    cout<<"success"<<endl;
                } else {
                    cout<<"failed"<<endl;
                }
                break;
            case 3:
                if (v.search(a[i])) {
                    cout<<"success"<<endl;
                } else {
                    cout<<"failed"<<endl;
                }
                break;
            case 4:
                v.print();
                break;
        }
    }

    return 0;
}
