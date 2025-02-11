/**
 * @file delete_repeat_num.cpp
 * @author chu_bingzhi (chu_bingzhi@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
//一个有序数组原地删除重复出现的元素，
//使每nums个元素只出现一次，返回删除后数组的新长度
//不能使用额外的数组空间，必须在原地修改输入数组
//并在使用 O(1)额外空间的条件下完成。
#include <iostream>
using namespace std;

int removDuplicates(int *num, int length)
{
    if(length == 0){
        return 0;
    }
    int i=0;
    for (int j = 1; j < length; j++){
        if(num[j] != num[i]){
            i++;
            num[i]=num[j];
        }
    }
    return i+1;
}

int main()
{
    int nums[] = {1,2,2,4,4,5,6,7};
    cout << removDuplicates(nums, sizeof(nums)/sizeof(int));
    return 0;
}