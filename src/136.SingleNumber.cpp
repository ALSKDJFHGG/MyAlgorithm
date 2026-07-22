#include "../include/print.h"

/**
 * leetcode
 * 136. 只出现一次的数字
 */
class Solution {
public:
    /**
     * 异或
     * 0 ^ 0 = 0
     * 0 ^ 1 = 1
     * 1 ^ 1 = 0
     */
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        int length = nums.size();
        for (int i = 1; i < length; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {2, 2, 1};
    print(s.singleNumber(nums1));

    vector<int> nums2 = {4, 1, 2, 1, 2};
    print(s.singleNumber(nums2));

    vector<int> nums3 = {1};
    print(s.singleNumber(nums3));
}