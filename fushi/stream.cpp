//从键盘输入几个学生的姓名的成绩，并以二进制文件形式保存
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct student{
    char name[20];
    int score;
};

//写入数据
// int main(){
//     student s;
//     ofstream OutFile( "./students.dat",ios::out | ios::binary);
//     while(cin >> s.name >> s.score)
//         OutFile.write((const char *)&s, sizeof(s));
//     OutFile.close();
//     return 0;
// }

//读出数据
// int main(){
//     student s;
//     ifstream inFile("./students.dat", ios::in | ios::binary );
// 	if(!inFile){
// 		cout<< "error" <<endl;
//         return 0;
//     }
//     while(inFile.read((char*)&s, sizeof(s))){
//         int readedBytes = inFile.gcount();//看刚才读了多少字节
//         cout << s.name << " " << s.score << endl;
//     }
//     inFile.close();
//     return 0;
// }

//修改数据
int main(){
    student s;
    fstream iofile("students.dat", ios::in | ios::out | ios::binary);
    if(!iofile) {
        cout << "error";
        return 0;
    }
    iofile.seekp(2*sizeof(s), ios::beg);
    iofile.write("Mike", strlen("Mike"+1));
    iofile.seekg(0, ios::beg);
    while (iofile.read((char* )&s, sizeof(s))){
        cout << s.name << " " << s.score << endl;
    }
    iofile.close();
    return 0;
}
