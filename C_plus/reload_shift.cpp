#include <iostream>
using namespace std;


class CStudent{
    public: 
        int nAge;
};

ostream & operator<<(ostream & o, const CStudent & s)
{
    o << s.nAge;
    return o;
}

int main() {
    CStudent s;
    s.nAge = 5;
    cout<< s << "hello";
    //cout已经被写成ostream类了无法增加成员函数
    //故而只能将<<重载为全局函数
    return 0;
}
