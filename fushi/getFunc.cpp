// #include <iostream>
// using namespace std;

// int main()
// {
//     cout<<"what year your house built?"<<endl;
//     int year;
//     cin>>year;
//     cin.get();
//     cout<<"adress?"<<endl;
//     char ad[80];
//     cin.getline(ad, 80);
//     cout << year << endl;
//     cout << ad << endl;
// }
// #include<iostream>
// using namespace std;
 
// int main(int argc, char * * argv)
// {
//     cout << "welcome to sogou" << endl;
//     int x = 064;
//     x = ~ x ^ x << 2 & x;
//     cout << oct << x << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

class Solution {
public:
    int return_value(int a) const {
        return a * 10;
    }

    int return_value2(int a) {
        return a * 100;
    }
};

int main() {
    // Solution s;
    // int a = 10;
    // int b = 1;
    // int value;
    // value = s.return_value(a); // value 是右值，不能被赋值
    // cout << value << endl;
    // value = 108; // 正确，因为 value 是右值
    // value = s.return_value2(b); // 错误，因为 value 是左值，不能被赋值
    // cout << value << endl;
    // return 0;

    char str[][6]={"hello", "fuck", "you"};
    cout << str[0] << " " << str[1] << " " << str[2] << endl;
    
    cout << *str[0] << " " << *str[1] << " " << *str[2] << endl;

    return 0;
}
