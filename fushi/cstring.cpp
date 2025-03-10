#include <iostream>
#include <cstring>
using namespace std;


class MyString {
    private:
        char* m_pstr;
    public:
        MyString() : m_pstr(nullptr){} //默认构造函数
        ~MyString(){ //析构函数
            if(m_pstr) {
                delete []m_pstr;
                m_pstr = nullptr;
            }
        }
        
        MyString(const char* pstr) { //构造函数
            if(pstr) {
                m_pstr = new char[strlen(pstr)+1];
                strcpy(m_pstr, pstr);
            } else {
                m_pstr = nullptr;
            }
        }  
        MyString(const MyString& str) { //拷贝构造函数
            if(str.m_pstr) {
                m_pstr = new char[strlen(str.m_pstr)+1];
                strcpy(m_pstr, str.m_pstr);
            } else {
                m_pstr = nullptr;
            }
        }  
    
        //赋值函数
        MyString& operator=(const MyString& str){
            if(this == &str) return *this;
            if(m_pstr)  delete[] m_pstr;
            if(str.m_pstr) {
                m_pstr = new char[strlen(str.m_pstr)+1];
                strcpy(m_pstr, str.m_pstr);
            } else {
                m_pstr = nullptr;
            }
            return *this;
        }
    int size() const {  // 返回字符串长度
        return m_pstr ? strlen(m_pstr) : 0;
    }
    const char* c_str() const {
        return m_pstr ? m_pstr : "";
    }

    // 比较大小
    bool operator<(const MyString str) const {
        return strcmp(m_pstr, str.m_pstr) < 0;
    }
    bool operator==(const MyString str) const {
        return strcmp(m_pstr, str.m_pstr) == 0;
    }
    bool operator>(const MyString str) const {
        return strcmp(m_pstr, str.m_pstr) > 0;
    }
    bool operator<=(const MyString str) const {
        return strcmp(m_pstr, str.m_pstr) <= 0;
    }
    bool operator>=(const MyString str) const {
        return strcmp(m_pstr, str.m_pstr) >= 0;
    }
    bool operator!=(const MyString str) const {
        return strcmp(m_pstr, str.m_pstr) != 0;
    }

    //合并字符串
    MyString operator+(const MyString str) const {
        MyString newStr;
        if(m_pstr && str.m_pstr) {
            newStr =  new char[strlen(m_pstr)+strlen(str.m_pstr)+1];
            strcpy(newStr.m_pstr, m_pstr);
            strcat(newStr.m_pstr, str.m_pstr);
        } else if(m_pstr) {
            newStr.m_pstr = new char[strlen(m_pstr)+1];
            strcpy(newStr.m_pstr, m_pstr);
        } else if(str.m_pstr) {
            newStr.m_pstr = new char[strlen(str.m_pstr)+1];
            strcpy(newStr.m_pstr, str.m_pstr);
        }

        return newStr;
    }
    MyString& operator+=(const MyString str){
        if (str.m_pstr) {
            if (m_pstr) {
                char* temp = new char[strlen(m_pstr) + strlen(str.m_pstr) + 1];
                strcpy(temp, m_pstr);
                strcat(temp, str.m_pstr);
                delete[] m_pstr;
                m_pstr = temp;
            } else {
                m_pstr = new char[strlen(str.m_pstr) + 1];
                strcpy(m_pstr, str.m_pstr);
            }
        }
        return *this;
    }
    
    //返回某个字符，从0开始
    char operator[](int index) const {
        if (index >= 0 && index < size()) {
            return m_pstr[index];
        }
        throw out_of_range("Index out of range");
    }
    char& operator[](int index) { //这个返回是为了可以修改内容
        if (index >= 0 && index < size()) {
            return m_pstr[index];
        }
        throw out_of_range("Index out of range");
    }

    //输出字符串
    friend ostream& operator<<(ostream& os, const MyString& str) {
        os << (str.m_pstr ? str.m_pstr : "");
        return os;
    }
    //输入字符串
    friend istream& operator>>(istream& is, MyString& str) {
        char buffer[1024];
        if(is.getline(buffer, sizeof(buffer))) {
            if(str.m_pstr) {
                delete[] str.m_pstr;
            }
            str.m_pstr = new char[strlen(buffer)+1];
            strcpy(str.m_pstr, buffer);
        }
        return is;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2("World");

    // 测试拼接
    MyString str3 = str1 + " " + str2;
    cout << str3 << endl;  // 输出: Hello World

    // 测试比较
    if (str1 < str2) {
        cout << "str1 is less than str2" << endl;
    }

    // 测试下标访问
    cout << "First character of str1: " << str1[0] << endl;

    // 测试赋值
    MyString str4 = str1;
    cout << "str4: " << str4 << endl;

    cin >> str4;
    cout << str4 << endl;
    return 0;
}