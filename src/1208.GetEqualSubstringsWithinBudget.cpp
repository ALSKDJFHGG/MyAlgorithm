#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <string>
using namespace std;
/**
leetcode
1208. 尽可能使字符串相等
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans{}, cost{}, left{};
        size_t length{s.size()};
        for (int i{}; i < length; ++i) {
            cost += abs(s[i] - t[i]);
            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                ++left;
            } else {
                ans = max(i - left + 1, ans);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.equalSubstring("abcd", "bcdf", 3) == 3);
    assert(s.equalSubstring("abcd", "cdef", 3) == 1);
    assert(s.equalSubstring("abcd", "acde", 0) == 1);
}