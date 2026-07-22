#include "../include/print.h"

/**
 * leetcode
 * 350. 两个数组的交集 II
 */
class Solution
{
public:
    /**
     * 哈希表
     */
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> temp1(1005, 0), temp2(1005, 0);
        for (auto num : nums1)
        {
                temp1[num]++;
        }
        for (auto num : nums2)
        {
                temp2[num]++;
        }
        vector<int> ans;
        for (int k = 0; k < 1005; k++)
        {
            if (temp1[k] && temp2[k])
            {
                int minNum = temp1[k] < temp2[k] ? temp1[k] : temp2[k];
                for (int i = 0; i < minNum; i++) {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    print(s.intersect(nums1, nums2));

    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};

    print(s.intersect(nums3, nums4));
}