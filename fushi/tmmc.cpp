// #include <iostream>
// using namespace std;

// int main() {
//     cout << "/*";
//     cout << "*/";
//     // cout << /* "*/" */;
//     cout << /* "*/" /* "/*" */;
// }

#include <iostream>
#include <iomanip>
#include <functional>
using namespace std;

inline int Max(int&& a, int&& b) {
    return a>b ? a:b;
}

int Power(int a, int b) {
    if(b < 0) {
        if(a == 0) {
            cout << "0的负指数" << endl;
            return -1;
        }
        a = 1/a;
        b = -b;
    }
    if(b == 0)  return 1;
    
    int res = 1;
    while(b > 0) {
        if(b%2 == 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

double Power(double a, int b) {
    if(b < 0) {
        if(a == 0) {
            cout << "0的负指数" << endl;
            return -1;
        }
        a = 1/a;
        b = -b;
    }
    if(b == 0)  return 1;
    
    double res = 1;
    while(b > 0) {
        if(b%2 == 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

int main(){
    // const double pi=3.1415926;
    // cout<<setprecision(3)<<pi<<endl
    //     <<setiosflags(ios::fixed)<<pi<<endl
    //     <<setprecision(8)<<setfill('*')<<setw(12)<<pi<<endl;
    // return 0;

    // cout << Max(10, 20) << endl;
    // return 0;

    // auto fibonacci = [](int n) {
    //     function<int(int)> fib = [&](int n) -> int {
    //         if(n<=1)    return n;
    //         return fib(n-1) + fib(n-2);
    //     };
    //     return fib(n);
    // };

    // function<int(int)> fib = [&fib](int n) -> int {
    //     return n <= 1 ? n : fib(n-1)+fib(n-2);
    // };

    // int n=10;
    // cout << fib(n) << endl;
    
    cout << Power(5, 2) << endl;
    cout << Power(2, 5) << endl;
    cout << Power(2.0, -2) << endl;
}
