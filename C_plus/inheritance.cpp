//实例学籍管理
#include <iostream>
#include <string>
using namespace std;
class CStudent {
	private:
    	string name;
    	string id;//学号
    	char gender; //性别,F'代表女，"M'代表男
    	int age;
    public:
    	void PrintInfo(){
            cout<<name<<" "<<id<<" "<<gender<<" "<<age<<" ";
        }
    	void SetInfo( const string & name_,const string & id_,
                    int age_, char gender_){
                        name = name_;
                        id = id_;
                        age = age_;
                        gender = gender_;
                    }
    	string GetName(){ return name; }
};

class CUndergraduateStudent:public CStudent
{//本科生类，继承了CStudent类
    private:
    	string department; //学生所属的系的名称
    public:
    	void QualifiedForBaoyan(){ //给予保研资格
            cout <<"qualified for baoyan"<< endl;
        }
    	void PrintInfo(){
            CStudent::PrintInfo(); //调用基类的Printinfo
            cout <<"Department:"<< department <<endl;
        }
    	void SetInfo( const string & name_,const string & id_,
                     int age_,char gender_,const string & department_){
            CStudent::SetInfo(name_,id_,age_,gender_); //调用基类的Setlnfo
            department= department_;
        }
};

int main()
{
    CUndergraduateStudent s2;
    s2.SetInfo("Harry Potter ","118829212",19,'M',"Computer Science");
    cout << s2.GetName()<<" " ;
    s2.QualifiedForBaoyan();
    s2.PrintInfo ();
    return 0;
}