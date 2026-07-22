#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 27. 移除元素
 */
class Solution {
public:
    // 双指针解法,快慢指针解决
    int removeElement(vector<int>& nums, int val) {
        int i{}, j{};
        int length = nums.size();
        while (j < length)
        {
            if (nums[j] != val) {
                nums[i++] = nums[j++];
            } else {
                j++;
            }
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {3, 2, 2, 3};
    int val = 3;
    auto ans1 = s.removeElement(nums1, val);
    print(ans1);

    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    val = 2;
    auto ans2 = s.removeElement(nums2, val);
    print(ans2);
}