#include "../include/print.h"

/**
 * leetcode
 * 268. 丢失的数字
 */
class Solution
{
public:
    /**
     * 数学计算
     */
    int missingNumber1(vector<int> &nums)
    {
        int maxNum = nums.size();
        int sumNum = 0;
        for (auto num : nums)
        {
            sumNum += num;
        }
        int sum = (1 + maxNum) * maxNum / 2;
        return sum - sumNum;
    }
    /**
     * 位运算
     */
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto num: nums) {
            ans ^= num;
        }
        int i{ 0 };
        int length = nums.size();
        for (i; i <= length; i++) {
            ans ^= i;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    print(s.missingNumber(nums1));
}