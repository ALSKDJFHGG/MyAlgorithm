#include <vector>
#include <unordered_map>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 217. 存在重复元素
 */
class Solution {
public:
    /**
     * 哈希表
     * 时间: O(n)
     * 空间: O(n)
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto num: nums) {
            if (map.find(num) != map.end()) {
                return true;
            }
            map[num] = 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};

    print(s.containsDuplicate(nums1));
    print(s.containsDuplicate(nums2));
    print(s.containsDuplicate(nums3));
}