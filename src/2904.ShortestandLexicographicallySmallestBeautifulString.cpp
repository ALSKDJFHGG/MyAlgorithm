#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
/**
leetcode
2904. 最短且字典序最小的美丽子字符串
 */
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1') < k) {
            return "";
        }
        int length{(int)s.size()}, ans{length}, sum{}, left{};
        string sans{s};
        for (int i{}; i < length; ++i) {
            sum += s[i] - '0';
            while (sum > k || s[left] == '0') {
                sum -= s[left++] - '0';
            }
            if (sum == k) {
                string temp = s.substr(left, i - left + 1);
                if (temp.size() < sans.length() || temp.length() == sans.size() && temp < sans) {
                    sans = std::move(temp);
                }
            }
        }
        return sans;
    }
};

int main() {
    Solution s;
    // cout << s.shortestBeautifulSubstring("100011001", 3) << '\n';
    assert(s.shortestBeautifulSubstring("100011001", 3) == "11001");
}