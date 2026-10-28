#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
/**
leetcode
3634. 使数组平衡的最少移除数目
 */
class Solution {
public:
    int minRemoval(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int left = 0;
        int ans{}, max_{};
        for (int i{}; i < length; ++i) {
            if (1LL * nums[left] * k < nums[i]) {
                ++left;
            }
            max_ = max(ans, i - left + 1);
        }
        return length - max_;
    }
};

// 1, 2, 6, 9
int main() {
    Solution s;
    assert(s.minRemoval({2, 1, 5}, 2) == 1);
    assert(s.minRemoval({1, 6, 2, 9}, 3) == 2);
    assert(s.minRemoval({4, 6}, 2) == 0);
    // cout << s.minRemoval({1, 6, 2, 9}, 3) << '\n';
}