//Map func
#include <iostream>
using namespace std;
template<class T,class Pred>
void Map(T s,T e,T x,Pred op){
	for(;s!=e;++s,++x){
        *x = op(*s);
    }
}
int Cube(int x){return x*x*x;}
double Square(double x){return x*x;}
int a[5]={1,2,3,4,5},b[5];
double d[5]={ 1.1,2.1,3.1,4.1,5.1},c[5];
int main(){
    Map(a,a+5,b,Square);
    for(int i=0; i<5; ++i)
        cout << b[i] <<",";
    cout << endl;
    Map(a,a+5,b,Cube);
    for(int i=0;i<5;++i)
        cout<< b[i] <<",";
    cout << endl;
    Map(d,d+5,c,Square);
    for(int i=0;i<5;++i)
        cout << c[i] <<",";
    cout<< endl;
	return 0;
}