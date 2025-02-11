/**
 * @file prime_number.cpp
 * @author chu_bingzhi (chu_bingzhi@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
//素数个数统计,统计n以内的素数个数素数:只能被1和自身整除的自然数，0、1除外
//埃筛法

#include <iostream>
#include <cstring>
using namespace std;

int eratosthenes(int n){
    int* isPrime = new int[n];
    memset(isPrime, 0, n);
    int count = 0;
    for (int  i = 2; i < n; i++)
    {
        if(!isPrime[i]){
            cout << i << ' ';
            count++;
            for (int j = i*i; j < n; j+=i)
            {
                isPrime[j] = 1;
            }
        }
    }
    cout <<endl;
    delete[] isPrime;
    return count;
}

int main(){
    cout<<eratosthenes(100)<<endl;
    return 0;
}