#include <iostream>
#include <format>

/**
 * u Calculate e
 *       n
 * e = E    1/(i!)
 *       i=0
 */
long double jie(int n) {
    if (n == 0) {
        return 1;
    }
    int res = 1;
    while (n > 0) {
        res*=n;
        n--;
    }
    return res;
}


long double cal(int n) {
    long double s{};
    for (int i = 0; i <= n; i++) {
        s += 1.0 / jie(i);
    }
    return s;
}

int main() {
    std::cout << "n e" << std::endl;
    std::cout << "- -----------" << std::endl;
    for (int i = 0; i <= 9; i++) {
        // 格式精度映射：n=0→0位, n=1→0位, n=2→1位, n≥3→9位
        int prec = i < 3 ? (i < 2 ? 0 : 1) : 9;
        std::cout << i << " " << std::format("{:.{}f}", cal(i), prec) << std::endl;
    }
    return 0;
}
