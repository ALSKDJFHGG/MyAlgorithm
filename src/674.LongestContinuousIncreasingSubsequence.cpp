#include <vector>
using namespace std;

/**
 * leetcode
 * 674. 最长连续递增序列
 */
class Solution {
public:
/**
 * time: O(n)
 * space: O(1)
 */
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int left = 0, right = 1;
        int length = nums.size();
        for (int i = 1; i < length; i++) {
            if (nums[right] > nums[right - 1]) {
                ans = max(ans, right - left + 1);
            } else {
                left = right;
            }
            right++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> test1 = {1,3,5,4,2,3,4,5};
    s.findLengthOfLCIS(test1);
}