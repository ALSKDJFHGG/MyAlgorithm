#include <algorithm>
#include <vector>
using namespace std;
/**
leetcode
453. 最小操作次数使数组元素相等
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans{}, minn{nums[0]};
        for (auto& num : nums) {
            minn = min(minn, num);
        }
        for (auto& num : nums) {
            ans += num - minn;
        }
        return ans;
    }
};