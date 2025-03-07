#include <iostream>
#include <cstring>
using namespace std;

int Index(string s, string t) {
    int i=0, j=0;
    while(i<s.length() && j<t.length()) {
		if(s[i] == t[j]) {
            ++i; ++j;
        }else{
            i=i-j+1; j=0;
        }
    }
    if(j == t.length()) return i-t.length();
    else return -1;
}

int main() {
    string s = "hello world";
    string t = "world";
    int pos = Index(s, t);
    if (pos != -1) {
        cout << "Found at position: " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}