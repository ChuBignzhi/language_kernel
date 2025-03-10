#include <iostream>
using namespace std;

// 判断一个数是否为素数
bool isPrime(int n) {
    if (n <= 1) return false; // 1 及以下的数不是素数
    if (n == 2) return true;  // 2 是素数
    if (n % 2 == 0) return false; // 排除偶数

    // 检查从 3 到 sqrt(n) 的奇数
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 验证哥德巴赫猜想
void verifyGoldbachConjecture(int limit) {
    for (int n = 4; n <= limit; n += 2) { // 遍历所有偶数
        bool found = false;
        for (int p1 = 2; p1 <= n / 2; p1++) { // 遍历可能的素数 p1
            if (isPrime(p1)) {
                int p2 = n - p1; // 计算 p2
                if (isPrime(p2)) { // 检查 p2 是否为素数
                    cout << n << " = " << p1 << " + " << p2 << endl;
                    found = true;
                    break; // 找到一对素数即可
                }
            }
        }
        if (!found) {
            cout << "验证失败: " << n << " 不能表示为两个素数之和" << endl;
        }
    }
}

int main() {
    int limit = 1000; // 验证范围
    cout << "在 1000 以内验证哥德巴赫猜想：" << endl;
    verifyGoldbachConjecture(limit);
    return 0;
}