#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>
using namespace std;
/**
leetcode
2106. 摘水果
 */
class Solution {
public:
    int maxTotalFruits(const vector<vector<int>>& fruits, int startPos, int k) {
        int left = ranges::lower_bound(fruits, startPos - k, ranges::less{}, 
            [](auto& a) {
                return a[0];
            }
        ) - fruits.begin();
        int sum{}, right{left}, length{static_cast<int>(fruits.size())};
        for (; right < length && fruits[right][0] <= startPos; ++right) {
            sum += fruits[right][1];
        }
        int ans{sum};
        for(; right < length && fruits[right][0] <= startPos + k; ++right) {
            sum += fruits[right][1];
            while (fruits[right][0] * 2 - fruits[left][0] - startPos > k 
                && fruits[right][0] - fruits[left][0] * 2 + startPos > k) {
                    sum -= fruits[left++][1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maxTotalFruits(
        {{2,8},{6,3},{8,6}}, 
        5, 
        4) == 9
    );
    assert(s.maxTotalFruits(
        {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}}, 
        5, 
        4) == 14
    );
}