//柠檬水找零

#include <iostream>
#include <vector>
using namespace std;

bool change(vector<int> &bills){
    int five=0, ten=0;
    for(auto bill: bills){
        if(bill==5) five++;
        else if(bill==10){
            if(five==0) return false;
            five--;ten++;
        }else{
            if(five>0&&ten>0){
                five--;ten--;
            }else if(five>=3){
                five-=3;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> bills = {5,5,20};
    cout << (change(bills)?"ture" : "false") <<endl;
    return 0;
}