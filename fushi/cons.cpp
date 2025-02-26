#include <iostream>
using namespace std;
// class A
// {
//     public:
//     	int v;
//     	A(int n){v=n; };
//     	A( const A&a){
//             v = a.v;
//             cout<< "Copy constructor called";
//         }
// };
// A Func(){
//     A b(4);
// 	return b;
// }
// int main(){
//     cout<<Func().v<<endl;
//     return 0;
// }
// class Complex
// {
//     public:
// 		double real,imag;
//     	Complex(int i)//类型转换构造函数
//         {
//             cout << "IntConstructor called" <<endl;
//             real=i; imag=0;
//         }
//     	Complex(double r,double i) { real=r; imag=i; }
// };
// int main()
// {
//     Complex c1(7,8);
// 	Complex c2 =12;
// 	c1=9;//9被自动转换成一个临时complex对象
// 	cout<< c1.real<< "," <<c1.imag<< endl;
// 	return 0;
// }

class CMyclass{
	public:
    ~CMyclass(){cout<<"destructor"<< endl;}
};
CMyclass obj;
CMyclass fun(CMyclass sobj){//参数对象消亡也会导致析
    //构函数被调用
    return sobj; //函数调用返回时生成临时对象返回
}

int main(){
	obj= fun(obj); //函数调用的返回值(临时对象)被
    return 0;  //用过后，该临时对象析构函数被调用
}// 输出三个destructor