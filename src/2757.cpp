#include <iostream>
#include <ostream>

// 2757: Counting Coins
/**
    tzoj
*/
int main() {
    int n{};
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "DeadMan\n";
        }
        else if (i % 3 == 0) {
            std::cout << "Dead\n";
        }
        else if (i % 5 == 0) {
            std::cout << "Man\n";
        }
        else {
            std::cout << i << " ";
        }
    }
} 