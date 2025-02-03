#include <iostream>
using namespace std;
class Test
{
public:
    Test() { cout << "i like zk"; }
    Test(int) { cout << "i like wangyi"; }
    void exe() { cout << "this is my choice"; }
};
int foo(int x, int y){
    if (x <= 0 || y <= 0)
        return 1;
    return 3 * foo( x-6, y/2 );
}
int main()
{
    cout << foo(20, 13) <<endl;
}