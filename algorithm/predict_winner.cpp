//预测赢家

#include <iostream>
#include <vector>

using namespace std;

//递归
int maxScore(vector<int> &arr, int l, int r){
    if(l==r) return arr[l];
    int sLeft=0, rRight=0;
    if(r-l==1){
        sLeft = arr[l];
        rRight = arr[r];
    }
    if(r-l>1){
        int num = maxScore(arr, l+1, r-1);
        sLeft = arr[l]+max(maxScore(arr, l+2, r), num);
        rRight = arr[r]+max(num, maxScore(arr, l, r-2));
    }
    return max(sLeft, rRight);
}

//递归优化
int maxScore_2(vector<int> &arr, int l, int r){
    if(l==r){
        return arr[l];
    }
    int sLeft = arr[l] - maxScore_2(arr, l+1, r);
    int rRight = arr[r] - maxScore_2(arr, l, r-1);
    return max(sLeft, rRight);
}

//动态规划  将maxScore_2(arr, l+1, r)存储到二维数组中[i][j]
//左移[i+1][j] 右移[i][j-1] dp数组

bool dp(vector<int> arr){
    int length = arr.size();
    vector<vector<int>> dp(length, vector<int>(length, 0));
    for(int i=0; i<length; i++){
        dp[i][i] = arr[i];
    }
    for(int i=length-2; i>=0; i--){
        for(int j=i+1; j<length; j++){
            dp[i][j] = max(arr[i]-dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }
    return dp[0][length-1]>=0;
}

bool dp_2(vector<int> arr){
    int length = arr.size();
    vector<int> dp(arr);
    for(int i=length-2; i>=0; i--){
        vector<int> new_dp = dp;
        for(int j=i+1; j<length; j++){
            new_dp[j] = max(arr[i]-new_dp[j], arr[j] - new_dp[j-1]);
        }
        dp = new_dp;
    }
    return dp[length-1]>=0;
}

vector<vector<int>> dp_3(vector<int> arr){
    int length = arr.size();
    vector<vector<int>> dp(length, vector<int>(length, 0));
    for(int i=0; i<length; i++){
        dp[i][i] = arr[i];
    }
    for(int i=length-2; i>=0; i--){
        for(int j=i+1; j<length; j++){
            dp[i][j] = max(arr[i]-dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }
    return dp;
}


int main()
{
    vector<int> arr = {5,200,2,3};
    // int sum=0;
    // for (auto i : arr){
    //     sum+=i;
    // }
    // int p1 = maxScore(arr, 0, arr.size()-1);
    // cout << (p1>sum-p1?"p1 win":"p2 win") << endl;
    // p1 = maxScore_2(arr, 0, arr.size()-1);
    // cout << (p1>sum-p1?"p1 win":"p2 win") << endl;

    vector<vector<int>> dparr = dp_3(arr);
    for(auto row : dparr){
        for(auto col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    cout<<dp(arr)<<endl;
    return 0;
}