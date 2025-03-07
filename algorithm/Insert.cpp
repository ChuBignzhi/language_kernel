#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertSort(vector<int> nums) {
    for_each(nums.begin(), nums.end(), [](int n){
        cout << n << " ";
    });
    cout << endl;
    int i, j, len=nums.size(), temp;
    for(i=1; i<len; i++) {
        if(nums[i]<nums[i-1]) {
            temp = nums[i];
            for(j=i-1; nums[j]>temp && j>=0 ; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = temp;
        }
        for_each(nums.begin(), nums.end(), [](int n){
        	cout << n << " ";
    	});
    	cout << endl;
    }
}

int main() {
    vector<int> a{49, 38, 65, 97, 76, 13, 27, 49};
    InsertSort(a);
}