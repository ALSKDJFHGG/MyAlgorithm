#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 26. 删除有序数组中的重复项
 */
class Solution {
public:
    /**
     * 该题需要使用双指针解法
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return 1;
        }
        int i{}, j{ i + 1 };
        while (j < length)
        {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 1, 2};

    auto ans1 = s.removeDuplicates(nums1);

    print(ans1);

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    auto ans2 = s.removeDuplicates(nums2);

    print(ans2);
}