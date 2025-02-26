#include <iostream>
#include <cstring>
using namespace std;

class String{
    private:
		char *str;
	public:
        String(const String& s) {
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
		String():str(new char[1]) {str[0]=0;}
    	const char* c_str() const {return str;}
    	String &operator = (const char* s);
    	~String(){delete[]str;}
        String & operator =(const String & s){
            if (this == &s) { // 检查自赋值
                return *this;
            }
            delete []str;
            str =new char [strlen(s.str)+1];
            strcpy(str, s.str);
            return *this;
        }
};
String & String::operator = (const char * s){
    //重载"="以使得 obj= "hello"能够成立
    delete []str;
    str =new char[strlen(s)+1];
    strcpy(str, s);
	return *this;
}
int main(){
    String s;
    s="Good Luck,";//等价于 s.operator=("Good Luck,");
    cout<< s.c_str()<< endl;
    //这条语句要是不注释掉就会出错
    //string s2 ="hello!";
    s="shenzhou 8!";//等价于 s.operator=("shenzhou 8!");

    String s1;
    s1=s;

    cout<< s.c_str()<< endl;
    cout<< s1.c_str()<< endl;
    return 0;
}