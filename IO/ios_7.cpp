#include <iostream>
using namespace std;

ostream &tab(ostream &output){
    return output << "\t";
}

int main(){
    cout << "aa" << tab << "bb" << endl;
}