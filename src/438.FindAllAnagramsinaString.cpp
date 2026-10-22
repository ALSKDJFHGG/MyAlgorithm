#include <cassert>
#include <vector>
#include <string>
using namespace std;
/**
leetcode
438. 找到字符串中所有字母异位词
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        vector<int> charS(26, 0), charP(26, 0), ans;
        for (int i{}; i < k; ++i) {
            ++charP[p[i] - 'a'];
        }
        int length = s.size();
        for (int i{}; i < length; ++i) {
            ++charS[s[i] - 'a'];

            int left = i - k + 1;
            if (left < 0) {
                continue;
            }

            if (charP == charS) {
                ans.emplace_back(left);
            }

            --charS[s[left] - 'a'];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> res{0, 6};
    assert((s.findAnagrams("cbaebabacd", "abc") == res));
}