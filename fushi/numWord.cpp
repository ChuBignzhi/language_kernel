#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int theNumLetter(string input) {
    if(input.size() == 0)   return 0;

    istringstream iss(input);
    int cnt = 0;
    string word;
    while(iss >> word)
        cnt++;
    return cnt;
}

int main() {
    string input("hello there are some good people here");
    cout << theNumLetter(input) << endl;
    return 0;
}