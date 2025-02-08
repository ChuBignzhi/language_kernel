// #include<iostream>
// using namespace std;
 
// int n = 300;
// int solve(int x) {
//     return x * (n - x);
// }
// int main() {
//     int l = 1, r = n;
//     int mid1, mid2;
//     int t = 50;
//     while (t--) {
//         mid1 = l + r >> 1;
//         mid2 = mid1 + r >> 1;
//         if (solve(mid1) > solve(mid2)) {
//             r = mid2;
//         } else {
//             l = mid1;
//         }
//     }
//     cout << l << endl;
//     return 0;
// }
#include <iostream>
using namespace std;
// int i = 0;
// int fun(int n) {
//     static int a = 2;
//     a++;
//     return (a * n);
// }
 
// int main() {
//     int k = 5;
//     {
//         int i = 2;
//         k += fun(i);
//     }
//     k += fun(i);
//     cout << k;
//     return (0);
// }
// int main(){
//     int total = 0;
//     for (int i = 0, j = 5; total < 10 || j > 3; ++i, --j) {
//         cout<<total<<" "<<i<<" "<< j<<endl;
//         total += (i + j);
//     }
//     cout <<total <<endl;
//     return 0;
// }
// class A
// {
// public:
//     void foo()
//     {
//         printf("1");
//     }
//     virtual void fun()
//     {
//         printf("2");
//     }
// };
// class B: public A
// {
// public:
//     void foo()
//     {
//         printf("3");
//     }
//     void fun()
//     {
//         printf("4");
//     }
// };
// int main(void)
// {
//     A a;
//     B b;
//     A *p = &a;
//     p->foo();
//     p->fun();
//     p = &b;
//     p->foo();
//     p->fun();
//     A *ptr = (A *)&b;
//     ptr->foo();
//         ptr->fun();
//     return 0;
// }

struct st_t {
    int status;
    short *pdata;
    char errstr[32];
};

int main() {
	// int n[][3] = { 10,20,30,40,50,60 };
	// int (*p)[3];
	// p = n;
	// cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
	// //cout << *(* (p + 1))<< endl;
    st_t st[16];
    char *p = (char *)(st[2].errstr + 32);
    printf("%d", (p - (char *)(st)));
}
