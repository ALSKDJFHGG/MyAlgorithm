#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
/**
leetcode
1493. 删掉一个元素以后全为 1 的最长子数组
*/
class Solution {
public:
    int longestSubarray(vector<int> nums) {
        int length = nums.size();
        int zero{}, left{}, right{};
        int ans{}, count{};
        while (right < length) {
            if (nums[right] == 0) {
                ++zero;
            }
            while (zero == 2) {
                if (nums[left] == 0) {
                    --zero;
                }
                --count;
                ++left;
            }
            ++count;
            ans = max(ans, count);
            ++right;
        }
        return ans - 1;
    }
};

int main() {
    Solution s;
    assert(s.longestSubarray({1, 1, 0, 1}) == 3);
    assert(s.longestSubarray({0,1,1,1,0,1,1,0,1}) == 5);
    assert(s.longestSubarray({1, 1, 1}) == 2);
    // cout << s.longestSubarray({0,1,1,1,0,1,1,0,1}) << '\n';
}