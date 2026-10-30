#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

/**
leetcode
2958. 最多 K 个重复元素的最长子数组
 */
class Solution {
public:
    int maxSubarrayLength(const vector<int>& nums, int k) {
        int length{static_cast<int>(nums.size())}, ans{}, left{}, count{};
        unordered_map<int, int> map;
        for (int i{}; i < length; ++i) {
            ++map[nums[i]];
            ++count;
            while (map[nums[i]] > k) {
                --map[nums[left]];
                --count;
                ++left;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maxSubarrayLength({1,2,3,1,2,3,1,2}, 2) == 6);
    assert(s.maxSubarrayLength({1,2,1,2,1,2,1,2}, 1) == 2);
    assert(s.maxSubarrayLength({5,5,5,5,5,5,5}, 4) == 4);
}