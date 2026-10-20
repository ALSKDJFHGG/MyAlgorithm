#include <cassert>
#include <string>
using namespace std;
/**
leetcode
4043. 恰好有 K 对相等相邻字符的循环移位数量
 */
class Solution {
public:
    int countRotations(string s, int k) {
        string ss = s + s;
        int length = ss.length();
        int windows_size = s.size();
        int ans = 0, count = 0;
        for (int i = 1; i < length - 1; ++i) {
            if (ss[i] == ss[i - 1]) {
                ++count;
            }

            int left = i - windows_size + 1;
            if (left < 0) {
                continue;
            }

            if (count == k) {
                ++ans;
            }

            if (ss[left] == ss[left + 1]) {
                --count;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.countRotations("aab", 1) == 2);
    assert(s.countRotations("abca", 0) == 1);
}