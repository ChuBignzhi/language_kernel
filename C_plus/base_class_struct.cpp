#include <iostream>
using namespace std;
class Bug {
    private :
    	int nLegs;
    	int nColor;
    public:
    	int nType;
    	Bug(int legs,int color);
    	void PrintBug(){};
};
Bug::Bug( int legs,int color)
{
    nLegs = legs;nColor =color;
}
class FlyBug: public Bug//FlyBug是Bug的派生类
{
    int nwings;
    public:
    	FlyBug( int legs,int color,int wings);
};
// //错误的FlyBug构造函数
// FlyBug::FlyBug(int legs,int color,int wings)
// {
//     nLegs = legs;//不能访问
//     nColor =color;// 不能访问
//     nType =1;//ok
//     nWings = wings;
// };
//正确的FlyBug构造函数:
FlyBug::FlyBug( int legs,int color,int wings):Bug(legs, color)
{
    nwings = wings;
}
int main(){
    FlyBug fb(2,3,4);
    fb.PrintBug();
    fb.nType =1;
    // fb.nLegs=2;//error.nLegs is private
    return 0;
}