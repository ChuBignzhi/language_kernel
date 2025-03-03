#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //删除string中的字符
    //成员函数erase()
    // string s1("hello worlld");
    // s1.erase(5);
    // cout << s1 << endl;
    // cout << s1.length() << endl;
    // cout << s1.size() <<endl; // 去掉下标 5 及之后的字符

    string s1("hello world");
    s1.replace(2,3,"haha");
    cout << s1 << endl;
}