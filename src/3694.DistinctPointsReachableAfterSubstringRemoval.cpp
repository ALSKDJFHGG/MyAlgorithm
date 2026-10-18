#include <cassert>
#include <cstddef>
#include <string>
#include <unordered_set>
using namespace std;
/**
leetcode
3694. 删除子字符串后不同的终点
 */
class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_set<size_t> set;
        size_t length = s.size();
        int x{0}, y{0};
        for (int i{0}; i < length; ++i) {
            switch (s[i]) {
                case 'U': ++y; break;
                case 'D': --y; break;
                case 'L': --x; break;
                case 'R': ++x; break;
            }

            if (i < k - 1) {
                continue;
            }
            int left = i - k + 1;
            set.insert(1LL * (x + length) << 32 | (y + length));


            switch (s[left]) {
                case 'L': x++; break;
                case 'R': x--; break;
                case 'D': y++; break;
                case 'U': y--; break;
            }
        }
        return set.size();
    }
};

int main() {
    Solution s;
    assert(s.distinctPoints("LUL", 1) == 1);
}
