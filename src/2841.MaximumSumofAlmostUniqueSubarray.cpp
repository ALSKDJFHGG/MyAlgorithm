#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
/** 
2841. 几乎唯一子数组的最大和
 */
class Solution {
public:
    long long maxSum(const vector<int>& nums, int m, int k) {
        unordered_map<int, int> map;
        size_t ans{}, max_a{}, count{};
        for (int i{}; i < k - 1; ++i) {
            if (!map.contains(nums[i])) {
                ++count;
            }
            ++map[nums[i]];
            ans += nums[i];
        }
        for (int i{k - 1}; i < nums.size(); ++i) {
            ans += nums[i];
            if (!map.contains(nums[i])) {
                ++count;
            }
            ++map[nums[i]];
            if (count >= m) {
                max_a = max(max_a, ans);
            }
            if (map[nums[i - k + 1]] == 1) {
                map.erase(nums[i - k + 1]);
                --count;
            } else {
                --map[nums[i - k + 1]];
            }
            ans -= nums[i - k + 1];
        }
        return max_a;
    }
};

int main() {
    Solution s;
    printf("ans: %lld\n", s.maxSum({2,6,7,3,1,7}, 3, 4));
}