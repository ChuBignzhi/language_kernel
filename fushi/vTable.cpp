#include <iostream>
using namespace std;


class A{
    int i=5;
	public:
    virtual void Func(){ 
        cout<< "A::Func"<< endl;
        cout<<i<<endl;
    }
    virtual void Func2(){ 
        cout<< "A::Func"<< i << endl; 
    }
};
class B:public A{
    int i=10;
    public:
    virtual void Func(){ 
        cout<< "B::Func" << endl; 
        cout << i <<endl;
    }
    virtual void Func2(){ 
        cout<< "B::Func"<< i << endl; 
    }
};
int main(){
    A a;
    A *pa = new B();
    pa->Func2();
    //64位程序指针为8字节
    long long *p1=(long long *) &a; //这个是A类的虚函数表
    long long *p2=(long long *) pa; //这个是B类的虚函数表
    //因为虚拟函数表就丢在开头，这样子就是将虚函数表提取出来
    * p2 = * p1;
    pa->Func2();
    return 0;
}