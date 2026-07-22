#include "../include/print.h"

/**
 * leetcode
 * 414. 第三大的数
 */
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long firstMaxNum = LONG_LONG_MIN, secondMaxNum = LONG_LONG_MIN, thirdMaxNum = LONG_LONG_MIN;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            int currentNum = nums[i];
            if (currentNum > firstMaxNum) {
                thirdMaxNum = secondMaxNum;
                secondMaxNum = firstMaxNum;
                firstMaxNum = currentNum;
            }
            if (currentNum < firstMaxNum && currentNum > secondMaxNum) {
                thirdMaxNum = secondMaxNum;
                secondMaxNum = currentNum;
            }
            if (currentNum > thirdMaxNum && currentNum < secondMaxNum) {
                thirdMaxNum = currentNum;
            }
        }
        if (thirdMaxNum == LONG_LONG_MIN) {
            return firstMaxNum;
        }
        return thirdMaxNum;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 2, 1};
    print(s.thirdMax(nums1));

    vector<int> nums2 = {1, 2};
    print(s.thirdMax(nums2));

    vector<int> nums3 = {2, 2, 3, 1};
    print(s.thirdMax(nums3));

    vector<int> nums4 = {1, 2, INT_MIN};
    print(s.thirdMax(nums4));
}