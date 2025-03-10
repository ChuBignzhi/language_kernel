#include<iostream>
using namespace std;
void callbyval(int a,int b,int c){
	a=3; b=2; c=1;
}
void callbypointer(int* a,int* b,int* c){
	*a=3; *b=2; *c=1;
}
void callbyreference(int& a, int& b, int& c){
	a=1; b=2; c=3;
}
int main() {
	int a=1,b=2, c=3;
	int& a1=a;
	int& b1=a;
	int& c1=a;
	callbyval(a,b,c);
	cout<<a<<b<<c<<endl; // 1 2 3
	callbypointer(&a, &b, &c); 
	cout<<a<<b<<c<<endl; // 3 2 1
	callbyreference(a1, b1, c1); 
	cout<<a<<b<<c<<endl; // 3 2 1
	return 0;
}
