// #include<bits/stdc++.h>
// using namespace std;
// class CA
// {
// public:
//     virtual void f1()
//     {
//         cout<<"CA::f1( )"<<endl;
//         f2();
//     }
//     void f2()
//     {
//         cout<<"CA::f2( )"<<endl;
//     }
// };
// class CB : public CA
// {
// public:
//     void f1()
//     {
//         cout<<"CB::f1( )"<<endl;
//         f2();
//     }
//     void f2()
//     {
//     cout<<"CB::f2( )"<<endl;
//     }
// };
// class CC:public CB
// {
// public:
//     virtual void f2()
//     {
//         cout<<"CC:f2()"<<endl;
//     }
// };
// int main()
// {
//     CC c;
//     CA *pA = &c ;
//     pA->f1();
//     return 0;
// }

#include <stdio.h>
void g1(int *a, int n, int i){
    while (2 * i <= n){
        int j = 2 * i;
        int v = a[j - 1];
        if (j < n && v < a[j]){
            v = a[j];
            j += 1;
        }
        if (a[i - 1] < v){
            int tmp = a[i - 1];
            a[i - 1] = v;
            a[j - 1] = tmp;
            i = j;
        } else{
            break;
        }
    }
}
int g2(int *a, int n, int m){
    int i;
    for (i = n / 2; i > 0; --i)
        g1(a, n, i);
    for (i = 0; i < n && a[i] != m; ++i);
    int j = 0;
    for (++i; i > 0; i /= 2)
        ++j;
    return j;
}
int main(int argc, char* argv[]){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d", g2(a, n, 8));
    return 0;
}