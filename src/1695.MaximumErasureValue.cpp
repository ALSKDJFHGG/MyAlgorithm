#include <cassert>
#include <cstddef>
#include <unordered_map>
#include <vector>
using namespace std;
/**
leetcode
1695. 删除子数组的最大得分 
*/
class Solution {
public:
    int maximumUniqueSubarray(const vector<int>& nums) {
        size_t left{}, ans{}, num{}, length{nums.size()};
        unordered_map<int, int> map;
        for (int i{}; i < length; ++i) {
            ++map[nums[i]];
            num += nums[i];
            while (map[nums[i]] > 1) {
                num -= nums[left];
                --map[nums[left]];
                ++left;
            }
            ans = max(ans, num);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maximumUniqueSubarray({4, 2, 4, 5, 6}) == 17);
    assert(s.maximumUniqueSubarray({5,2,1,2,5,2,1,2,5}) == 8);
}