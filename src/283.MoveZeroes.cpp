#include "../include/print.h"

/**
 * leetcode
 * 283. 移动零
 */
class Solution {
public:
    /**
     * 双指针
     */
    void moveZeroes(vector<int>& nums) {
        int i, j;
        int length = nums.size();
        for (i = 0, j = 0; j < length; j++) {
            if (nums[j]) {
                nums[i++] = nums[j];
            }
        }
        for (i; i < length; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {0,1,0,3,12};
    s.moveZeroes(nums1);
    print(nums1);
}