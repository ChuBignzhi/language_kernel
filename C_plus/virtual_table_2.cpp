#include <iostream>
using namespace std;
class A{
	public:
    virtual void Func(){ cout<< "A::Func"<< endl;}
};
class B:public A{
    public:
    virtual void Func(){ cout<< "B::Func" << endl; }
};
int main(){
    A a;
    A *pa = new B();
    pa->Func();
    //64位程序指针为8字节
    long long *p1=(long long *) & a;
    long long *p2=(long long *) pa;
    * p2 = * p1;
    pa->Func();
    return 0;
}