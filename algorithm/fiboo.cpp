#include <iostream>
#include <cstring>
using namespace std;

//暴力递归
int Fib(int num){
    if (num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    return Fib(num-1)+Fib(num-2);
}

//去重递归
int Fib_non(int *arr, int n){
    if (n==0) return 0;
    if (n==1) return 1;
    if(arr[n]!=0) return arr[n];
    
    arr[n] = Fib_non(arr, n-1)+Fib_non(arr, n-2);
    return arr[n];
}

//双指针迭代
int Fib_double_pointer(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    int low=0, high=1;
    for (int i = 2; i <=n ; i++)
    {
        int sum = low+high;
        low =high;
        high = sum;
    }
    return high;    
}


int main()
{
    cout << Fib(10) << endl;
    int nums[11];
    memset(nums, 0, sizeof(nums));
    cout << Fib_non(nums, 10) << endl;
    cout << nums[10] << endl;
    for (int i = 0; i < 11; i++){
        cout << nums[i] << " ";
    }
    cout<< endl;
    cout << Fib_double_pointer(10)<< endl;
    return 0;
}