//找三个数乘积最大值
//线性扫描
#include <iostream>
#include <algorithm>
using namespace std;

int three_num_max(int *num, int length)
{
    sort(num, num+length);
    return max(num[0]*num[1]*num[length-1], 
        num[length-1]*num[length-2]*num[length-3]);
}

int getMaxMin(int *num, int length){
    int min1,min2;
    min1=min2=INT_MAX;
    int max1,max2,max3;
    max1=max2=max3=INT_MIN;
    for (int i = 0; i < length; i++){
        int x = num[i];
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
        if (x > max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max3 = max2;
            max2 = x;
        } else if (x > max3) {
            max3 = x;
        }
    }
    return max(min1*min2*max1, max1*max2*max3);
}

int main()
{
    int nums[] = {5,6,8,3,2};
    int length = sizeof(nums)/sizeof(int);
    cout << three_num_max(nums, length) <<endl;
    cout << getMaxMin(nums, length)<<endl;
    return 0;
}