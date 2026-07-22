#include "../include/print.h"

/**
 * leetcode
 * 121. 买卖股票的最佳时机
 */
class Solution {
public:
    /**
     * 一次遍历
     */
    int maxProfit(vector<int>& prices) {
        int ans = 0, minPrice = 10e4;
        int length = prices.size();
        for (int i = 0; i < length; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            if (prices[i] - minPrice > ans) {
                ans = prices[i] - minPrice;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {7,1,5,3,6,4};
    print(s.maxProfit(nums1));

    vector<int> nums2 = {7,6,4,3,1};
    print(s.maxProfit(nums2));
}