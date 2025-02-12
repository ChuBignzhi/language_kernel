//排列硬币，输出完整的列数

#include <iostream>
#include <cmath>
using namespace std;

int arrange_coin(int n) //迭代
{
    for (int i = 1; i <= n; i++)
    {
        n-=i;
        if (n<=i)
        {
            return i;
        }
    }
    return 0;
}

int arrange_coin_2(int n)
{
    int low=0, high=n;
    while (low<=high)
    {
        long mid = (high-low)/2+low;
        long cost = ((mid + 1) * mid) /2;
        if (cost == n) return mid;
        else if (cost > n) high = mid-1;
        else low = mid+1;
    }
    return high;
}

double sqrt(double x, int n){ // x = (2n - x)/x
    double res = (x+(2*n-x)/x)/2;
    // if(fabs(res-x)< 1e-6){
    if(res == x){
        return res;
    }else{
        return sqrt(res, n);
    }
}
int arrange_coin_3(int n) //牛顿迭代法
{
    if( n == 0 ){
        return 0;
    }
    return (int)sqrt(n, n);
} 


int main()
{
    cout << arrange_coin(10) <<endl;
    cout << arrange_coin_2(10) <<endl;
    cout << arrange_coin_3(10) << endl;
    return 0;
}