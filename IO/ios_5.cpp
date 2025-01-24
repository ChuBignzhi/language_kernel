#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int w= 4;
    char string[10];
    cin.width(5);
    while(cin >> string){
        cout.width(w++);
        cout<< string << endl;
        cin.width(5);
    }
}