#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 219. 存在重复元素 II
 */
class Solution {
public:
    /**
     * 哈希表
     * 时间: O(n)
     * 空间: O(n)
     */
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            int currentNum = nums[i];
            if (map.find(currentNum) != map.end()) {
                int oldIndex = map[currentNum];
                if ((i - oldIndex) <= k) {
                    return true;
                }
            }
            map[currentNum] = i;
        }
        return false;
    }
    /**
     * 滑动窗口
     * 时间: O(n)
     * 空间: O(k)
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }
            if (set.count(nums[i])) {
                return true;
            }
            set.emplace(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    int k = 3;
    print(s.containsNearbyDuplicate(nums1, k));
    vector<int> nums2 = {1, 0, 0, 1};
    k = 1;
    print(s.containsNearbyDuplicate(nums2, k));
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    k = 2;
    print(s.containsNearbyDuplicate(nums3, k));
}