#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "File name missing!" <<endl;
        return 0;
    }
    ifstream inFile(argv[1], ios::binary | ios::in);
    if (!inFile)
    {
        cout << "Source file open error" <<endl;
        return 0;
    }
    ofstream outFile(argv[2], ios::binary | ios::out);
    if (!outFile)
    {
        cout << "New file open error" << endl;
        inFile.close();
        return 0;
    }
    char c;
    while( inFile.get(c))//每次读取一个字符
        outFile.put(c);//每次写入一个字符
    outFile.close();
    inFile.close();
    return 0;
}
