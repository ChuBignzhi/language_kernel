//优势洗牌

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> advantageCount(vector<int> A, vector<int> B){
    const int n = A.size();
    vector<int> ans(n);
    vector<pair<int, int>> sorted_B;

    sort(A.begin(), A.end());
    
    for(int i=0; i<n; i++){
        sorted_B.emplace_back(B[i], i);
    }
    sort(sorted_B.begin(), sorted_B.end(), 
        [](const auto& a, const auto& b){
            return a.first>b.first;
        }
    );

    int left=0, right=n-1;
    for(const auto& [b_val, b_idx] : sorted_B){
        if(A[right]>b_val){
            ans[b_idx] = A[right];
            right--;
        }else{
            ans[b_idx] = A[left];
            ++left;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {10, 24, 8, 32};
    vector<int> B = {13, 25, 25, 11};
    vector<int> result = advantageCount(A, B);
    for (int num : result) {
        cout << num << " ";
    }
    // 输出：24 32 8 10 或类似组合
    return 0;
}