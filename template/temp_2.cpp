//不通过参数实例化函数模板
#include <iostream>
using namespace std;
template <class T>
T Inc(T n){
    return 1 + n;
}
int main(){
    cout<< Inc<double>(4)/2;//输出2.5
    return 0;
}