//参议院
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

string predictPatryVicitory(string senate)
{
    //队列
    queue<int> r;
    queue<int> d;
    int length = senate.size();
    for (int i = 0; i < length; i++){
        if(senate[i] == 'R')  r.push(i);
        else d.push(i);
    }
    while(!r.empty()&&!d.empty()){
        int rPoll=r.front(), dPoll=d.front();
        d.pop();r.pop();
        if(rPoll < dPoll){
            r.push(rPoll+length);
        }else{
            d.push(dPoll+length);
        }
    }
    return d.empty()?"R":"D";
}

int main()
{
    string senate = "RDD";
    cout<<predictPatryVicitory(senate);
    return 0;
}

