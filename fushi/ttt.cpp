// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // class CA
// // // {
// // // public:
// // //     virtual void f1()
// // //     {
// // //         cout<<"CA::f1( )"<<endl;
// // //         f2();
// // //     }
// // //     void f2()
// // //     {
// // //         cout<<"CA::f2( )"<<endl;
// // //     }
// // // };
// // // class CB : public CA
// // // {
// // // public:
// // //     void f1()
// // //     {
// // //         cout<<"CB::f1( )"<<endl;
// // //         f2();
// // //     }
// // //     void f2()
// // //     {
// // //     cout<<"CB::f2( )"<<endl;
// // //     }
// // // };
// // // class CC:public CB
// // // {
// // // public:
// // //     virtual void f2()
// // //     {
// // //         cout<<"CC:f2()"<<endl;
// // //     }
// // // };
// // // int main()
// // // {
// // //     CC c;
// // //     CA *pA = &c ;
// // //     pA->f1();
// // //     return 0;
// // // }

// // #include <stdio.h>
// // void g1(int *a, int n, int i){
// //     while (2 * i <= n){
// //         int j = 2 * i;
// //         int v = a[j - 1];
// //         if (j < n && v < a[j]){
// //             v = a[j];
// //             j += 1;
// //         }
// //         if (a[i - 1] < v){
// //             int tmp = a[i - 1];
// //             a[i - 1] = v;
// //             a[j - 1] = tmp;
// //             i = j;
// //         } else{
// //             break;
// //         }
// //     }
// // }
// // int g2(int *a, int n, int m){
// //     int i;
// //     for (i = n / 2; i > 0; --i)
// //         g1(a, n, i);
// //     for (i = 0; i < n && a[i] != m; ++i);
// //     int j = 0;
// //     for (++i; i > 0; i /= 2)
// //         ++j;
// //     return j;
// // }
// // int main(int argc, char* argv[]){
// //     int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
// //     int n = sizeof(a) / sizeof(a[0]);
// //     printf("%d", g2(a, n, 8));
// //     return 0;
// // }

// #include<iostream>
// using namespace std;
// void callbyval(int a,int b,int c){
// 	a=3; b=2; c=1;
// }
// void callbypointer(int* a,int* b,int* c){
// 	*a=3; *b=2; *c=1;
// }
// void callbyreference(int& a, int& b, int& c){
// 	a=1; b=2; c=3;
// }
// int main() {
// 	int a=1,b=2, c=3;
// 	int& a1=a;
// 	int& b1=a;
// 	int& c1=a;
// 	callbyval(a,b,c);
// 	cout<<a<<b<<c<<endl; // 1 2 3
// 	callbypointer(&a, &b, &c); 
// 	cout<<a<<b<<c<<endl; // 3 2 1
// 	callbyreference(a1, b1, c1); 
// 	cout<<a<<b<<c<<endl; // 3 2 1
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// char* month_name(int n) {
//     static char *name[]={
//         "ILLEGAL MONTH", "JANUARY",
//         "FEBRUARY","MARCH","APRIL",
//         "MAY","JUNE","JULY","AUGUST",
//         "SEPTEMBER","OCTOBER","NOVEMAER","DECEMBER"};
//         return((n<1 || n>12) ? name[0]:name[n]);
// }
// int main(){
//     char* month_name(int n);
//     cout<<"MONTH NO" << 3 <<" "<<month_name(3)<<"\n";
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
int a[3]={10,15,20};
int *p1=a, *p2=&a[1];
*p1=*(p2-1)+5;
*(p1+1)=*p1-5;
cout<<a[1]<<endl;
}