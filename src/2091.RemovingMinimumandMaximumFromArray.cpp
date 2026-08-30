#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/**
* leetcode
* 2091. 从数组中移除最大值和最小值
*/
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        int minIndex{}, maxIndex{};
        int length = nums.size();
        for (int i{}; i < length; ++i) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
            if (nums[i] < minNum) {
                minNum = nums[i];
                minIndex = i;
            }
        }
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);
        return min({right + 1, length - left, left + 1 + length - right});
    }
};