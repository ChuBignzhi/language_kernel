/**
 * @file find_center_index.cpp
 * @author chu_bingzhi(chu_bingzhi@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 /*
寻找数组的中心下标
给定一个整数数组 nums，请编写一个能够返回数组“中心下标”的方法。
中心下标是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
1. 如果数组不存在中心下标，返回-1。
2. 如果数组有多个中心下标，应该返回最靠近左边的那一个。
注意:中心下标可能出现在数组的两端。
 */
#include <iostream>
#include <numeric>
using namespace std;
int pivotIndex(int *num,int length){
    int sum = accumulate(num, num+length, 0);
    int total=0;
    for(int i=0; i<length; i++){
        total += num[i];
        if (total == sum){
            return i;
        }
        sum = sum - num[i];
    }
    return -1;
}

int main()
{
    int nums[]={1,7,3,6,5,6};
    cout << pivotIndex(nums, sizeof(nums)/sizeof(int));
    return 0;
}