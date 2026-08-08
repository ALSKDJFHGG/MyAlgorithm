#include <vector>
#include <algorithm>
using namespace std;

/**
 * leetcode
 * 628. 三个数的最大乘积
 */
class Solution {
public:
/**
 * time: O(n)
 * space: O(1)
 */
    int maximumProduct(vector<int>& nums) {
       // sort(nums.begin(), nums.end());
        int length = nums.size();
        //return max(nums[0] * nums[1] * nums[length - 1], nums[length - 1] * nums[length - 2] * nums[length - 3]);
        int maxNum1 = -1001, maxNum2 = -1001, maxNum3 = -1001;
        int minNum1 = 1001, minNum2 = 1001;
        for (int i = 0; i < length; i++) {
            int currentNum = nums[i];
            if (currentNum > maxNum1) {
                maxNum3 = maxNum2;
                maxNum2 = maxNum1;
                maxNum1 = currentNum;
            } else if (currentNum > maxNum2) {
                maxNum3 = maxNum2;
                maxNum2 = currentNum;
            } else if (currentNum > maxNum3) {
                maxNum3 = currentNum;
            }
            if (currentNum < minNum1) {
                minNum2 = minNum1;
                minNum1 = currentNum;
            } else if (currentNum < minNum2) {
                minNum2 = currentNum;
            }
        }
        return max(maxNum1 * maxNum2 * maxNum3, minNum1 * minNum2 * maxNum1);
    }
};

int main() {
    Solution s;
    vector<int> test1 = {-100,-98,-1,2,3,4};
    s.maximumProduct(test1);
}