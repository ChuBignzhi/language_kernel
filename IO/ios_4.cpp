#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double x=1234567.89, y=12.34567;
    int n= 1234567;
    int m= 12;
    cout << setiosflags(ios::fixed) << 
        setprecision(6)<< x << endl
        << y << endl << n << endl << m;
}