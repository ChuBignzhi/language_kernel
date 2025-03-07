#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<int>& nums) {
    for_each(nums.begin(), nums.end(), [](int n){
        cout << n << " ";
    });
    cout<<endl;
	for(int i=0; i<nums.size()-1; i++) {
		bool flag = false;
        for(int j=nums.size()-1; j>i; j--) {
            if(nums[j-1]>nums[j]) {
                swap(nums[j-1], nums[j]);
                flag=true;
            }
        }
        for_each(nums.begin(), nums.end(), [](int n){
            cout << n << " ";
        });
        cout << endl;
        if(flag==false)	return;
    }
}

int main() {
    vector<int> a{49, 38, 65, 97, 76, 13, 27, 49};
    BubbleSort(a);
}