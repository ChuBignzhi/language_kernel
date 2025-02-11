/**
 * @file sqrt_x.cpp
 * @author chu_bingzhi (chu_bingzhi@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/*
在不使用 sqrt(x)函数的情况下，得到 x的平方根的整数部分
重点考察:二分法、牛顿迭代
*/
#include <iostream>
int binarySearch(int x){
    int index =-1;
    int l=0, r=x;
    while (l<=r)
    {
        int mid = l+(r-l)/2;
        if(mid*mid<=x){
            index = mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    
    return index;
}

double sqrt(double i, int x){
    double res = (i+x/i)/2;
    if(res == i){
        return i;
    }else{
        return sqrt(res, x);
    }
}
int newton(int x){
    if (x==0){
        return 0;
    }
    
    return sqrt(x, x);
} 


int main()
{
    std::cout<<binarySearch(24)<<std::endl;
    std::cout<<newton(24)<<std::endl;
}