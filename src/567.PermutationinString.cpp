#include <cassert>
#include <string>
#include <vector>
using namespace std;
/**
leetcode
567. 字符串的排列
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        vector<int> charnum1(26, 0);
        vector<int> charnum2(26, 0);
        for (int i{}; i < k; ++i) {
            charnum1[s1[i] - 'a'] += 1;
        }
        int length = s2.size();
        for (int i{}; i < length; ++i) {
            charnum2[s2[i] - 'a'] += 1;

            int left = i - k + 1;
            if (left < 0) {
                continue;
            }

            if (charnum1 == charnum2) {
                return true;
            }

            charnum2[s2[left] - 'a'] -= 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    // assert(s.checkInclusion("ab", "eidbaooo"));
    assert(s.checkInclusion("ab", "eidboaoo") == false);
}