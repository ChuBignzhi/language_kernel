#include <iostream>
using namespace std;

int foo(int n) {
    if(n<2)return n;
    return foo(n-1)+foo(n-2);
}

int Function(unsigned int n) { 
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
}

int main()
{
//	cout << foo(5) << endl;
// 	int i = 3; 
//// 	cout << ++i << ++i << endl;
// 	cout << ++i << i++ << ++i << i++; 
	cout << Function(197);
	 return 0 ;
}
