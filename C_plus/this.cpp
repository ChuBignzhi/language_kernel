#include <iostream>
using namespace std;
//this作用
class A{
    int i; 
	public:
		void Hello() { cout << "hello" << endl; }//这样子不出错
		//void Hello() { cout << i << endl; }//这样子出错
};//->void Hello(A* this) { cout << "hello" << endl; }

int main()
{
    A * p= NULL;
    p->Hello();//结果会怎样?
    /*->Hello(p)*/
}//输出hello