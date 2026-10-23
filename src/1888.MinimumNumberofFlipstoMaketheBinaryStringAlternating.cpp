#include <cassert>
#include <climits>
#include <string>
using namespace std;
/**
leetcode
1888. 使二进制字符串字符交替的最少反转次数
 */
class Solution {
public:
    int minFlips(string s) {
        string ss = s + s;
        int k = s.size(), length = 2 * k;
        int first0{}, first1{}, ans{INT_MAX};
        for (int i{}; i < length; ++i) {
            if (ss[i] - '0' != i % 2) {
                ++first0;
            } else {
                ++first1;
            }

            int left = i - k + 1;
            if (left < 0) {
                continue;
            }

            ans = min(min(first0, first1), ans);

            if (ss[left] - '0' != left % 2) {
                --first0;
            } else {
                --first1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.minFlips("111000") == 2);
}