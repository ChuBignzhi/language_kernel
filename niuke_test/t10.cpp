#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=10;
    int& b=a;
    double c=10;
    double& d=c;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    return 0;    
}

