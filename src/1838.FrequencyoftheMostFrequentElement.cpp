#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
using namespace std;
/**
leetcode
1838. 最高频元素的频数
 */
class Solution {
public:
    int maxFrequency(vector<int> nums, int k) {
        int length{(int)nums.size()}, ans{}, left{};
        std::size_t sum{}, com{};
        ranges::sort(nums);
        for (int i{}; i < length; ++i) {
            sum += nums[i];
            while (1LL * (i - left + 1) * nums[i] - sum > k) {
                sum -= nums[left++];
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maxFrequency({1, 2, 4}, 5) == 3);
    assert(s.maxFrequency({1, 4, 8, 13}, 5) == 2);
}
