#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SelectSort(vector<int> nums) {
	int len = nums.size();
    for_each(nums.begin(), nums.end(), [](int n){
        cout << n << " ";
    });
    cout << endl;
    for(int i=0; i<len-1; i++) {
        int min = i;
        for(int j=i+1; j<len; j++) {
			if(nums[j] < nums[min]) min=j;
        }
        if(min!=i) swap(nums[i], nums[min]);
        for_each(nums.begin(), nums.end(), [](int n){
            cout << n << " ";
        });
        cout << endl;
    }
}

int main() {
    vector<int> a{49, 38, 65, 97, 76, 13, 27, 49};
    SelectSort(a);
}