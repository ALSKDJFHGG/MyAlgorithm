#include <vector>
using namespace std;

/**
 * leetcode
 * 746. 使用最小花费爬楼梯
 */
class Solution {
public:
/**
 * 动态规划
 */
    int minCostClimbingStairs(vector<int>& cost) {
        size_t length = cost.size();
        vector<int> dp(length, 0);
        for (int i = 2; i < length; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return min(dp[length - 1] + cost[length - 1], dp[length - 2] + cost[length - 2]);
    }
};
