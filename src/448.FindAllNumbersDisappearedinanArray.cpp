#include "../include/print.h"

/**
 * leetcode
 * 448. 找到所有数组中消失的数字
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       vector<int> ans;
       int mod = 1e7 + 7;
       int length = nums.size();
       for(int i = 0; i < length; i++) {
            int index = (nums[i] - 1) % mod;
            if (nums[index] <= length) {
                nums[index] += length; 
            }
       } 
       for (int i = 0; i < length; i++) {
            if (nums[i] < length) {
                ans.push_back(nums[i]);
            }
       }
       return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    print(s.findDisappearedNumbers(nums1));
}