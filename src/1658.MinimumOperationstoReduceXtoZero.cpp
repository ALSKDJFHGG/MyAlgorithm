#include <numeric>
#include <vector>
using namespace std;
/**
leetcode
1658. 将 x 减到 0 的最小操作数
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int length{(int)nums.size()}, left{}, ans{-1}, sum{};
        // C++17 引入归约算法，将范围内数合并成一个值
        int target = reduce(nums.begin(), nums.end()) - x;
        if (target < 0) {
            return -1;
        }
        for (int i{}; i < length; ++i) {
            sum += nums[i];
            while (sum > target) {
                sum -= nums[left];
                ++left;
            }
            if (sum == target) {
                ans = max(ans, i - left + 1);
            }
        }
        return ans < 0 ? -1 : length - ans;
    }
};
