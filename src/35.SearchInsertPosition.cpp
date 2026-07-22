#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 35. 搜索插入位置
 */
class Solution {
public:
    /**
     * 顺序遍历查找
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int searchInsert1(vector<int>& nums, int target) {
        int i{};
        int length = nums.size();
        while (i < length)
        {
            if (nums[i] >= target) {
                break;
            }
            i++;
        }
        return (i < length) ? i : (i - 1);
    }
    /**
     * 二分查找
     * 时间复杂度: O(log n)
     * 空间复杂度: O(1)
     */
    int searchInsert2(vector<int>& nums, int target) {
        int length = nums.size();
        int i{}, j{ length - 1 };
        while (i <= j) {
            int m{ (i + j) / 2 };
            if (nums[m] < target) {
                i = m + 1;
            } else if (nums[m] > target)
            {
                j = m - 1;
            } else {
                return m;
            }
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};

    int target = 5;
    int ans1 = s.searchInsert1(nums, target);
    print(ans1);

    target = 2;
    int ans2 = s.searchInsert1(nums, target);
    print(ans2);

    target = 7;
    int ans3 = s.searchInsert1(nums, target);
    print(ans3);

    target = 5;
    int ans4 = s.searchInsert2(nums, target);
    print(ans4);

    target = 2;
    int ans5 = s.searchInsert2(nums, target);
    print(ans5);

    target = 7;
    int ans6 = s.searchInsert2(nums, target);
    print(ans6);

}