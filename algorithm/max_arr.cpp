//找最长连续递增数组

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLength(vector<int> &nums)
{
    int start=0;
    int maxx=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] <= nums[i-1]){
            start=i;
        }
        maxx = max(i-start+1, maxx);
    }
    return maxx;
}

int main()
{
    vector<int> nums={1,2,3,2,3,4,3,4,5,6,7};
    cout << findLength(nums);
    return 0;
}