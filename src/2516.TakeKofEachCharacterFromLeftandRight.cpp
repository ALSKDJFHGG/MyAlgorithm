#include <cassert>
#include <string>
#include <vector>
using namespace std;

#define ASSERT(FLAG) do {    \
    if (!(FLAG)) {\
        printf("line: %s\n", __LINE__);\
    }\
}while(0)

/**
leetcode
2516. 每种字符至少取 K 个
 */
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cap(3, -k);
        for (char& c : s) {
            ++cap['c' - c];
        }
        if (cap[0] < 0 || cap[1] < 0 || cap[2] < 0) {
            return -1;
        }
        int length{(int)s.size()}, left{}, ans{};
        vector<int> count(3, 0);
        for (int i{}; i < length; ++i) {
            ++count['c' - s[i]];
            while (count[0] > cap[0] || count[1] > cap[1] || count[2] > cap[2]) {
                --count['c' - s[left++]];
            }
            ans = max(ans, i - left + 1);
        }
        return length - ans;
    }
};

int main() {
    Solution s;
    ASSERT(s.takeCharacters("aabaaaacaabc", 2) == 8);
    ASSERT(s.takeCharacters("a", 1) == -1);
}