//两数之和
//用map计算

#include <iostream>
#include <map>
// #include <vector>
// #include <utility>
using namespace std;

template <typename T1, typename T2>
ostream & operator<<(ostream &os, const pair<T1,T2> &p)
{
    os << "{" << p.first <<", "<< p.second <<"}";
    return os;
}

pair<int, int> solution(int num[], int target, int length){
    map<int, int> mp;
    for (int i = 0; i < length; i++){
        auto it = mp.find(target-num[i]);
        if(it!=mp.end()){
            return pair<int, int>(it->second, i);
        }
        mp[num[i]]=i;
    }
    return {};
}
int main()
{
    int nums[] = {1,2,3,4,5,6};
    pair<int,int> p=solution(nums, 10, sizeof(nums)/sizeof(int));
    cout << p.first << " " << p.second << endl;
    cout << p <<endl;
    return 0;
}