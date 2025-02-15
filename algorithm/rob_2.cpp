//首位相连
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//降低空间复杂度
//不用数组存储，只用的到i-2和i-1
int max_money_4(vector<int> num, int start, int end){
    if(num.empty()){
        return 0;
    }
    if(num.size()==1){
        return num[0];
    }

    int first=num[start], second=max(num[start],num[start+1]);
    for(int i=start+2; i<=end; i++){
        int temp = second;
        second = max(first+num[i], second);
        first = temp;
    }
    return second;
}

//循环数组，不要第一个或者不要最后一个，剩余的数组当做第一种来看
int main()
{
    vector<int> num={1,2,3,1};
    vector<int> nums={2,7,9,3,1};
    cout << max(max_money_4(num, 0, num.size()-2), 
                max_money_4(num, 1, num.size()-1)) << endl;
    // cout << max_money_4(nums, nums.size()-1) << endl;
    return 0;
}