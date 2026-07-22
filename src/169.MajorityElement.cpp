#include <vector>
#include <unordered_map>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 169. 多数元素
 */
class Solution {
public:
    /**
     * 桶
     * 时间复杂度: O(n) — 遍历数组一次，哈希表操作平均 O(1)
     * 空间复杂度: O(n) — 最坏情况下哈希表存储所有不重复元素
     */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int length = nums.size();
        int ans = 0, maxNum = 0;
        for (int i = 0; i < length; i++) {
            int currentNum = nums[i], &currentMaxNum = map[currentNum];
            if (map.find(currentNum) == map.end()) {
                currentMaxNum = 1;
            } else {
                currentMaxNum += 1;
            }
            if (currentMaxNum > maxNum) {
                ans = currentNum;
                maxNum = currentMaxNum;
            }
        }
        return ans;
    }
    /**
     * Boyer-Moore 投票算法
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int majorityElement1(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (auto num: nums) {
            if (count == 0) {
                candidate = num;
            }
            if (candidate == num) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {6, 5, 5};
    print(s.majorityElement(nums1));

    vector<int> nums2 = {2,2,1,1,1,2,2};
    print(s.majorityElement(nums2));

    print(s.majorityElement1(nums1));

    print(s.majorityElement(nums2));
}