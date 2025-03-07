#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        while(pivot <= nums[high] && low < high) high--;
        nums[low] = nums[high];
        while(pivot >= nums[low] && low < high) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

void QuickSort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int pivotpos = partition(nums, low, high);
        QuickSort(nums, low, pivotpos-1);
        QuickSort(nums, pivotpos+1, high);
    }
}

int main() {
    vector<int> a{49, 38, 65, 97, 76, 13, 27, 49};
    QuickSort(a, 0, a.size()-1);
    for_each(a.begin(), a.end(), [](int n){
        cout << n << " ";
    });
}