// #include <iostream>
// using namespace std;

// int fun(int x){
//     int countx = 0;
//     while (x) {
//         countx++;
//         x = x & (x - 1);
//     }
//     return countx;
// }

// int func(int x) {
//     int count=0;
//     while( x != 0xFFFFFFFF) {
//         count++;
//         x = x|(x+1);
//     }
//     return count;
// }

// int main() {
//     // const int i = 0; 
//     // int *j = (int *) &i; 
//     // *j = 1; 
//     // printf("%d,%d", i, *j);
//     cout << fun(500) << endl;
//     cout << func(500) << endl;
//     return 0;
// }

#include<stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;
int main(){ 
    // int sum; 
    // for(int i=0; i<6; i+=2){ 
    //     sum=i; 
    //     for(int j = i; j<6; j++){
    //         if(i+j>5) continue;
    //         sum+=j;
    //     } 
    // }    
    // printf("%d",sum);
    // return 0; 
    unsigned int uiA;
    uiA = (0xAB & 0xCD) ^ (0xEF | 0xAB);
    cout << hex << uiA << endl;
} 