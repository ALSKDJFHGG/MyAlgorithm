#include <vector>
using namespace std;

/**
 * leetcode
 * 198. 打家劫舍
 */
class Solution {
public:
/**
 * 动态规划
 * 1. 1家的情况
 * 2. 2家的情况
 * 3. >2的情况
 */
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        }
        if (length == 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(length, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < length; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[length - 1];
    }
};
