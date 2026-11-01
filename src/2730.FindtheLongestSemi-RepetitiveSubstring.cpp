#include <cassert>
#include <string>
using namespace std;
/**
leetcode
2730. 找到最长的半重复子字符串
 */
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int length{static_cast<int>(s.size())}, ans{1}, left{}, count{};
        for (int i{1}; i < length; ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            }
            while (count > 1 && left < i) {
                if (s[left] == s[left + 1]) {
                    --count;
                }
                ++left;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.longestSemiRepetitiveSubstring("52233") == 4);
    assert(s.longestSemiRepetitiveSubstring("5494") == 4);
    assert(s.longestSemiRepetitiveSubstring("1111111") == 2);
    assert(s.longestSemiRepetitiveSubstring("0001") == 3);
    assert(s.longestSemiRepetitiveSubstring("4411974") == 6);
}