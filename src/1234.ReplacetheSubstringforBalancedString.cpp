#include <cassert>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;
/**
leetcode
1234. 替换子串得到平衡字符串
 */
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> map;
        int length{(int)s.size()}, k{length / 4}, ans{INT_MAX}, sum{}, left{};
        for (int i{}; i < length; ++i) {
            ++map[s[i]];
        }
        if (map['Q'] == k && map['W'] == k && map['E'] == k && map['R'] == k) {
            return 0; 
        }
        for (int i{}; i < length; ++i) {
            --map[s[i]];
            while (map['Q'] <= k && map['W'] <= k&& map['E'] <= k&& map['R'] <= k) {
                ans = min(ans, i - left + 1);
                ++map[s[left]];
                ++left;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.balancedString("QWER") == 0);
    assert(s.balancedString("QQWE") == 1);
    assert(s.balancedString("QQQW") == 2);
    assert(s.balancedString("QQQQ") == 3);
    assert(s.balancedString("WWQQRRRRQRQQ") == 4);
}