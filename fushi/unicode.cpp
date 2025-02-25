#include <iostream>

int main() {
    // 输出 Unicode 字符 '©'（版权符号）
    std::cout << "Copyright symbol: \u00A9" << std::endl;

    // 输出 Unicode 字符 '€'（欧元符号）
    std::cout << "Euro symbol: \u20AC" << std::endl;

    std::cout << "Smiling face: \U0001F60A" << std::endl;

    return 0;
}