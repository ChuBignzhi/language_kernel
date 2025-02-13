//倾倒了n杯香槟后，第i行第j个玻璃杯存放的香槟
//模拟的思想，模拟香槟下流的过程
#include <iostream>
#include <vector>
using namespace std;

double champangeTower(int cup, int row, int col){
    vector<vector<double>> ca(100, vector<double>(100, 0));
    ca[0][0] = cup;
    for(int r=0; r<=row ; r++){
        for(int l=0; l<=r; l++){
            double d = (ca[r][l]-1.0)/2;
            if(d>0){
                ca[r+1][l] += d;
                ca[r+1][l+1] += d;
            }
        }
    }
    return (ca[row][col]>1.0)? 1 : ca[row][col];
}

int main()
{
    cout << champangeTower(5, 2, 2);
    return 0;
}