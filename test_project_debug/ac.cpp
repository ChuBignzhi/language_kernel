#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    int id;
    int yuwen;
    int shuxue;
    int yingyu;
    int score;
};

int main() {
    int n;
    cin >> n;
    vector<stu> vec(n);

    for(int i=0; i<n; i++) {
        cin >> vec[i].yuwen >> vec[i].shuxue >> vec[i].yingyu;
        vec[i].score = vec[i].yuwen + vec[i].shuxue + vec[i].yingyu;
        vec[i].id = i+1;
    }

    sort(vec.begin(), vec.end(), [](const stu& a, const stu& b) {
        if(a.score != b.score)    return a.score>b.score;
        else {
            if(a.yuwen != b.yuwen) {
                return a.yuwen > b.yuwen;
            } else {
                return a.id < b.id;
            }
        }
    });

    for(int i=0; i<5; i++) {
        cout << vec[i].id << ' ' << vec[i].score << endl;
    }

    return 0;
}
