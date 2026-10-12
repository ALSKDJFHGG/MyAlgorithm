#include <iostream>

int main() {
    int ans{};
    int num = 3;
    while (num) {
        ans += num % 2;
        num = num >> 1;
    }
    std::cout << ans << "\n";
}