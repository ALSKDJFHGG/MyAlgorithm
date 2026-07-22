#include "../include/print.h"

/**
 * leetcode
 * 349. 两个数组的交集
 */
class Solution {
public:
    /**
     * 哈希表实现思路
     * 时间: O()
     * 空间:
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp1(1005, 0), temp2(1005, 0);
        for (auto num: nums1) {
            if (temp1[num] == 0) {
                temp1[num]++;
            }
        }
        for (auto num: nums2) {
            if (temp2[num] == 0) {
                temp2[num]++;
            }
        }
        vector<int> ans;
        for (int k = 0; k < 1005; k++) {
            if (temp1[k] && temp2[k]) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

}