#include <cassert>
#include <vector>
using namespace std;
/**
leetcode
1004. 最大连续1的个数 III
 */
class Solution {
public:
    int longestOnes(const vector<int>& nums, int k) {
        int length{static_cast<int>(nums.size())}, count{}, left{}, ans{};
        for (int i{}; i < length; ++i) {
            if (nums[i] == 0) {
                ++count;
            }
            while (count > k) {
                if (nums[left++] == 0) {
                    --count;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.longestOnes({1,1,1,0,0,0,1,1,1,1,0}, 2) == 6);
    assert(s.longestOnes({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3) == 10);
}