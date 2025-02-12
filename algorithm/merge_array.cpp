//合并两个有序数组

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void merge(int a[], int m, int b[], int n)
{
    int* num = new int[m+n];
    copy(a, a+m, num);
    int k=0, l=0;
    int cnt=0;
    while (k<m&&l<n){
        a[cnt++] = (num[k]<b[l]) ? num[k++] : b[l++];
    }
    while (k<m){
        a[cnt++] = num[k++];
    }
    while (l<n){
        a[cnt++] = b[l++];
    }
    delete[] num;
    // return a;
}

void merge2(int a[], int m, int b[], int n){
    int p1=m-1, p2=n-1;
    int p=m+n-1;
    while(p1>=0&&p2>=0){
        a[p--] = a[p1]>b[p2] ? a[p1--]:b[p2--];
    }
    while (p1>=0){
        a[p--] = a[p1--];
    }
    while (p2>=0){
        a[p--] = a[p2--];
    }
}

int main()
{
    int* num1 = new int[9]{1,3,5,7,9,0,0,0,0};
    int* num2 = new int[4]{2,4,6,8};

    // copy(num2, num2+4, num1+5);
    // sort(num1, num1+9);
    // for (int i = 0; i < 9; ++i) {
    //     cout << num1[i] << " ";
    // }
    // cout << endl;

    merge2(num1, 5, num2, 4);
    for (int i = 0; i < 9; ++i) {
        cout << num1[i] << " ";
    }
    cout << endl;
    delete[] num1;
    delete[] num2;
    return 0;
}