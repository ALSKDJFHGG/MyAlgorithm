#include <iostream>
#include <string>
#include <vector>


/**
kmp
*/

std::vector<int> getNext(const std::string& s) {
    int length = s.size();
    std::vector<int> next(length, 0);
    int j = 0;
    for (int i = 1; i < length; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        next[i] = j;
    }
    return next;
}

int findStr(const std::string& s1, const std::string& s2) {
    int length1 = s1.size(), length2 = s2.size();
    int j{};
    auto next = getNext(s2);
    for (int i{}; i < length1; ++i) {
        while (j > 0 && s1[i] != s2[j]) {
            j = next[j - 1];
        }
        if (s1[i] == s2[j]) {
            ++j;
        }
        if (j == length2) {
            return i - j + 1;
        }
    }
    return -1;
}

int main() {
    auto vet = findStr("qweqqwert", "qwer");
    std::cout << vet << std::endl;
}
