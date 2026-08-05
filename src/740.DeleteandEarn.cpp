#include <vector>
using namespace std;

/**
 * leetcode
 * 740. 删除并获得点数
 */
class Solution {
    /**
     * 动态规划, 与leetcode 198一样
     */
private:
    int rob(vector<int> &nums) {
        int length = nums.size();
        vector<int> dp(length, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < length; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[length - 1];
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for (auto n : nums) {
            maxNum = max(maxNum, n);
        }
        vector<int> sum(maxNum + 1, 0);
        for (int n : nums) {
            sum[n] += n;
        }
        return rob(sum);
    }
};
