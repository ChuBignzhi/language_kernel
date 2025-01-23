/**
 * @file geometry_example.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 几何形体处理程序:输入若干个几何形体的参数，要求按面积排序输出。输出时要指明形状。
 * input :
 * 第一行是几何形体数目n(不超过100).下面有n行，每行以一个字母c开头
 * 若c是'R’，则代表一个矩形，本行后面跟着两个整数，分别是矩形的宽和高;
 * 若c是'C’，则代表一个圆，本行后面跟着一个整数代表其半径
 * 若c是'T’，则代表一个三角形，本行后面跟着三个整数，代表三条边的长度
 * output:
 * 按面积从小到大依次输出每个几何形体的种类及面积。
 * 每行一个几何形体，输出格式为:
 * 形体名称:面积
 * @version 0.1
 * @date 2025-01-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class CShape{
    public:
    virtual double Area()=0; //纯虚函数
    virtual void PrintInfo()=0;
};
class CRectangle:public CShape{
    public:
    int w,h;
    virtual double Area();
    virtual void PrintInfo();
};
class CCircle:public CShape {
    public:
    int r;
    virtual double Area();
    virtual void PrintInfo();
};
class CTriangle:public CShape{
    public:
    int a,b,c;
    virtual double Area();
    virtual void PrintInfo();
};

double CRectangle::Area(){return w* h;}
void CRectangle::PrintInfo(){cout << "Rectangle:" << Area() << endl;}
double CCircle::Area(){return 3.14 * r*r ;}
void CCircle::PrintInfo(){cout << "Circle:" << Area() << endl;}
double CTriangle::Area(){double p=(a+b+c)/2.0;return sqrt(p*(p-a)*(p- b)*(p - c));}
void CTriangle::PrintInfo(){cout << "Triangle:" << Area() << endl;}

CShape *pShapes[100];
int MyCompare(const void * sl, const void * s2);
int main(){
    int i; int n;
    CRectangle * pr;
    CCircle * pc;
    CTriangle * pt;
    cin >> n;
    for( i=0;i<n;i ++){
        char c;cin >> c;
        switch(c){
            case 'R':
                pr = new CRectangle();
                cin >> pr->w >> pr->h;
                pShapes[i]= pr;
                break;
            case 'C':
                pc =new CCircle();
                cin >> pc->r;
                pShapes[i]= pc;
                break;
            case 'T':
                pt = new CTriangle();
                cin >> pt->a >> pt->b >> pt->c;
                pShapes[i]= pt;
                break;
        }
    }
    qsort(pShapes,n,sizeof( CShape*),MyCompare);
    for( i= 0;i <n;i ++){
        pShapes[i]->PrintInfo();
    }
    return 0;
}
int MyCompare(const void * s1, const void * s2){
    double a1,a2;
    CShape **p1;// sl,s2 是 void*，不可写“*s1”来取得s1指向的内容
    CShape **p2;
    p1=(CShape**)s1;//s1,s2指向pShapes数组中的元素，数组元素的类型是CShape
    p2=(CShape**)s2;// 故 p1,p2都是指向指针的指针，类型为 CShape **;
    a1=(*p1)->Area();//*p1的类型是 Cshape*,是基类指针，故此句为多态
    a2=(*p2)->Area();
    if( a1 <a2 )
        return -1;
    else if( a2< a1)
        return 1;
    else
        return 0;
}