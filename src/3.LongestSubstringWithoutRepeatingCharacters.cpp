#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/**
leetcode
3. 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans{1}, count{};
        unordered_map<char, int> cap;
        int left{}, right{}, length = s.size();
        while (right < length) {
            if (cap[s[right]] == 0) {
                ++cap[s[right]];
                ++count;
                ++right;
                continue;
            }
            ans = max(ans, count);
            --cap[s[left]];
            ++left;
            --count;
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
}
