#include <vector>
using namespace std;

/**
 * leetcode
 * 643. 子数组最大平均数 I
 */
class Solution {
public:
/**
 * time: O(n)
 * space: O(1)
 */
    double findMaxAverage(vector<int>& nums, int k) {
        int length = nums.size();
        double sum{};
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double agv = sum / k;
        double ans = agv;
        for (int i = k; i < length; i++) {
            sum = sum - nums[i - k] + nums[i];
            agv = sum / k;
            if (agv > ans) {
                ans = agv;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> test1 = {0,1,1,3,3};
    s.findMaxAverage(test1, 4);
}