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
int i = 0;
int fun(int n) {
    static int a = 2;
    a++;
    return (a * n);
}
 
int main() {
    int k = 5;
    {
        int i = 2;
        k += fun(i);
    }
    k += fun(i);
    cout << k;
    return (0);
}