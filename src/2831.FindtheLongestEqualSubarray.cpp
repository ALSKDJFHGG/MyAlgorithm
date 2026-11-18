#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;
/**
leetcode
2831. 找出最长等值子数组
 */
class Solution {
public:
    int longestEqualSubarray(const vector<int>& nums, int k) {
        int length{(int)nums.size()}, ans{}, left{};
        vector<vector<int>> hashNum(length + 1);
        for (int i{}; i < length; ++i) {
            hashNum[nums[i]].push_back(i - hashNum[nums[i]].size());
        }
        for (auto& pos : hashNum) {
            left = 0;
            for (int right{}; right < pos.size(); ++right) {
                while (pos[right] - pos[left] > k) {
                    ++left;
                }
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.longestEqualSubarray({1, 3, 2, 3, 1, 3}, 3) == 3);
}