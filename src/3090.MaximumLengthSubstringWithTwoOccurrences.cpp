#include <cassert>
#include <string>
#include <vector>
using namespace std;
/**
leetcode
3090. 每个字符最多出现两次的最长子字符串
 */
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int length = s.size();
        vector<int> cap(26, 0);
        int ans{}, count{};
        int left{}, right{};
        while (right < length) {
            if (cap[s[right] - 'a'] < 2) {
                ++cap[s[right] - 'a'];
                ++count;
                ++right;
                ans = max(ans, count);
                continue;
            }
            --cap[s[left] - 'a'];
            ++left;
            --count;
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maximumLengthSubstring("bcbbbcba") == 4);
    assert(s.maximumLengthSubstring("aaaa") == 2);
}