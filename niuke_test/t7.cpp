#include <stdio.h>
// int main() { 
//     int i, n = 0;
//     float x = 1, y1 = 2.1 / 1.9, y2 = 1.9 / 2.1;
//     for ( i = 1; i < 22; i++)
//         x = x * y1;
//     while ( x != 1.0 ) {
//         x = x * y2; n++;   
//     }
//     printf( "%d\n", n );
//     return 0; 
// }
// #include <iostream>
// using namespace std;
// int main() {
//     float a = 1;
//     cout << boolalpha << ((int)a == (int &)a);
//     cout << (int)a << (int&)a << endl;
//     float b = 0;
//     cout << boolalpha << ((int)b == (int &)b);
//     cout << (int)b << (int&)b << endl;
// }
// int f1(int x, int y) {
//     return x > y ? x : y;
// }
// int f2(int x, int y) {
//     return x > y ? y : x;
// }
// int main() {  
//     int a = 4, b = 3, c = 5, d = 2, e, f, g;
//     e = f2(f1(a, b), f1(c, d));
//     f = f1(f2(a, b), f2(c, d));
//     g = a + b + c + d - e - f;
//     printf("%d, %d, %d\n", e, f, g);
//     return 0;
// }
// #include <stdio. h>
int fun( int a )
{
    int b = 0;
    static int c = 3;
    a = ( c++,b++);
    return ( a );
}
main( )
{
    int a = 2,i,k;
    for( i = 0;i<2;i++ )
        k = fun(a++);
    printf("%d\n",k );
}