#include <vector>
#include <string>
#include <iostream>

using namespace std;
vector<int> getNext(const string& s) {
    int m = s.length();
    vector<int> next(m, -1); // 初始化next数组，默认-1

    if (m <= 1) return next; // 处理空字符串

    int j = -1; // 前缀指针，初始化为-1

    // 从第二个字符开始遍历(i=1)
    for (int i = 1; i < m; i++) {
        // 当前字符不匹配时，回退j到next[j]的位置
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        // 匹配成功时，j向前移动
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j; // 更新next[i]
    }

    for(int i=0; i<m; i++) next[i] += 1; 

    return next;
}

// int main() {
//     // 测试用例1："ABABC"
//     string pattern1 = "ABABC";
//     vector<int> next1 = getNext(pattern1);
//     // 预期输出: [-1, 0, 0, 1, 2]
//     for (int val : next1) cout << val << " ";
//     cout << endl;

//     // 测试用例2："AAAAA"
//     string pattern2 = "AAAAA";
//     vector<int> next2 = getNext(pattern2);
//     // 预期输出: [-1, 0, 1, 2, 3]
//     for (int val : next2) cout << val << " ";
//     cout << endl;

//     // 测试用例3："ABCDABD"
//     string pattern3 = "abaabcaba";
//     vector<int> next3 = getNext(pattern3);
//     // 预期输出: [-1, 0, 0, 0, 0, 1, 2]
//     for (int val : next3) cout << val << " ";
//     cout << endl;

//     return 0;
// }
// 使用next数组进行查找 ‌:ml-citation{ref="1,5" data="citationList"}
int kmpSearch(const string& text, const string& pattern) {
    vector<int> next = getNext(pattern);
    int j = -1; // 模式串指针
    
    for(int i = 0; i < text.length(); i++) {
        while(j >= 0 && text[i] != pattern[j+1]) {
            j = next[j]; // 利用next数组回退‌:ml-citation{ref="4" data="citationList"}
        }
        if(text[i] == pattern[j+1]) j++;
        if(j == pattern.length() - 1) {
            return i - j; // 返回匹配起始位置‌:ml-citation{ref="3" data="citationList"}
        }
    }
    return -1;
}

int main() {
    string text = "ABABABABC";   // 主串
    string pattern = "ABABC";     // 模式串
    
    int pos = kmpSearch(text, pattern);
    cout << "匹配位置：" << pos << endl; // 输出: 0
    return 0;
}