//三角形的最大周长
//如果不能形成三角形返回0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestPerimeter(vector<int> &a){
    sort(a.begin(), a.end());
    for(int i=a.size()-1; i>1; i--){
        if((a[i-1]+a[i-2])>a[i]){
            return a[i-1] + a[i-2] + a[i];
        }
    }
    return 0;
}

int main()
{
    vector<int> edge = {3,6,2,3};
    cout << largestPerimeter(edge) <<endl;
    return 0;
}