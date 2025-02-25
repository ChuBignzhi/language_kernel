#include <iostream>
using namespace std;

int main()
{
    cout<<"what year your house built?"<<endl;
    int year;
    cin>>year;
    cin.get();
    cout<<"adress?"<<endl;
    char ad[80];
    cin.getline(ad, 80);
    cout << year << endl;
    cout << ad << endl;
}