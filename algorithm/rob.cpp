//打家劫舍

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//递归思想
int max_money(vector<int> num, int index){
    if(num.empty() || index<0){
        return 0;
    }
    if(index==0){
        return num[0];
    }
    return max(max_money(num, index-1), 
            max_money(num, index-2)+num[index]);
} //只有index影响，之前预测赢家是l与r


//最优子结构 n->n-1 递推公式    重叠子问题
int max_money_2(vector<int> num){
    if(num.empty()){
        return 0;
    }
    if(num.size()==1){
        return num[0];
    }
    int n=num.size();
    vector<int> dp(n, 0);
    dp[0] = num[0];
    dp[1] = max(num[0], num[1]);
    for(int i=2; i<num.size(); i++){
        dp[i] = max(dp[i-1], dp[i-2]+num[i]);
    }
    return dp[num.size()-1];
}

//降低空间复杂度
//不用数组存储，只用的到i-2和i-1
int max_money_3(vector<int> num){
    if(num.empty()){
        return 0;
    }
    if(num.size()==1){
        return num[0];
    }

    int first=num[0], second=num[1];
    for(int i=2; i<num.size(); i++){
        int temp = second;
        second = max(first+num[i], second);
        first = temp;
    }
    return second;
}

int main()
{
    vector<int> num={1,2,3,1};
    vector<int> nums={2,7,9,3,1};
    cout << max_money(num, num.size()-1) << endl;
    cout << max_money(nums, nums.size()-1) << endl;

    cout << max_money_2(num) << endl;
    cout << max_money_2(nums) << endl;
}