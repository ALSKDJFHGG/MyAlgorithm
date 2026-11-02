#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;
/**
leetcode
2779. 数组的最大美丽值
 */
class Solution {
public:
    int maximumBeauty(vector<int> nums, int k) {
        ranges::sort(nums);
        int ans{}, left{}, length{static_cast<int>(nums.size())};
        for (int i{}; i < length; ++i) {
            if (nums[i] - nums[left] > 2 * k) {
                ++left;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maximumBeauty({4, 6, 1, 2}, 2) == 3);
}