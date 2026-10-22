#include <cassert>
#include <cstdint>
#include <vector>
using namespace std;
/**
leetcode
3652. 按策略买卖股票的最佳时机
 */
class Solution {
public:
    long long maxProfit(vector<int> prices, vector<int> strategy, int k) {
        int64_t ans{},originS{}, temp{};
        int length = prices.size();
        for (int i{}; i < length; ++i) {
            originS += prices[i] * strategy[i];
        }
        ans = originS;
        int originL{}, originR{}, changeL{}, changeR{};
        for (int i{k / 2}; i < length; ++i) {
            int indexL = i - k / 2;
            originL += prices[indexL] * strategy[indexL];
            originR += prices[i] * strategy[i];
            changeR += prices[i];

            int left = i - k / 2 + 1;
            if (left < k / 2) {
                continue;
            }

            temp = originS;

            temp += changeR - originL - originR;
            ans = max(ans, temp);

            originL -= prices[left - k / 2] * strategy[left - k / 2];
            originR -= prices[left] * strategy[left];
            changeR -= prices[left];
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maxProfit({5, 4, 3}, {1, 1, 0}, 2) == 9);
    assert(s.maxProfit({4, 2, 8}, {-1, 0, 1}, 2) == 10);
    assert(s.maxProfit({5, 8}, {-1, -1}, 2) == 8);
    assert(s.maxProfit({4, 7, 13}, {-1, -1, -0}, 2) == 9);
}