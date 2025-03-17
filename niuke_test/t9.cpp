#include <iostream>
#include <vector>
using namespace std;

// 归并排序一定要另外的数组去容纳之前的元素

long long merge(vector<int>& nums, vector<int>& tmp, int left, int mid, int right) {
    int i=left, j=mid+1, k=left;
    long long count = 0;
    while (i<=mid && j<=right) {
        if(nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
            count += mid-i+1;
        }
    }
    
    while(i<=mid) {
        tmp[k++] = nums[i++];
    }
    while (j<=right) {
        tmp[k++] = nums[j++];
    }
    
    for(int p=left; p<=right; p++) nums[p] = tmp[p];

    return count;
}

int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
    if(left>=right) return 0;

    int mid = left + (right-left)/2;
    long long count = 0;

    count += mergeSort(nums, tmp, left, mid);
    count += mergeSort(nums, tmp, mid+1, right);

    count += merge(nums, tmp, left, mid, right);

    return count;
}


long long InversePairs(vector<int>& nums) {
    int len = nums.size();
    if(len==0)  return 0;
    vector<int> tmp(len);
    return mergeSort(nums, tmp, 0, len-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << InversePairs(vec) << endl;
    return 0;
}