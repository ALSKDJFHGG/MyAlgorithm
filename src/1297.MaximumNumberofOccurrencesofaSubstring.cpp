#include <cassert>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/**
leetcode
1297. 子串的最大出现次数
 */
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> map;
        vector<int> cap_char(26, 0);
        size_t kind_n{0}, length{s.size()};
        int max_a{}, max_c{};
        for (int i{0}; i < length; ++i) {
            int in = s[i] - 'a';
            if (cap_char[in] == 0) {
                ++kind_n;
            }
            ++cap_char[in];
            int left = i - minSize + 1;
            if (left < 0) {
                continue;
            }
            if (kind_n <= maxLetters) {
                max_c = ++map[s.substr(left, minSize)];
                max_a = max(max_a, max_c);
            }
            int out = s[left] - 'a';
            --cap_char[out];
            if (cap_char[out] == 0) {
                --kind_n;
            }
        }
        return max_a;
    }
};

int main() {
    Solution s;
    assert(s.maxFreq("aababcaab", 2, 3, 4) == 2);
}
