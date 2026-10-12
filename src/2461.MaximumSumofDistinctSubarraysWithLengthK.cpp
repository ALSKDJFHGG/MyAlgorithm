#include <unordered_map>
#include <vector>
#include <cstdio>
using namespace std;

/**
2461. 长度为 K 子数组中的最大和
 */
class Solution {
public:
    long long maximumSubarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int max_a{}, max_{}, count{};
        for (int i{}; i < k - 1; ++i) {
            if (map[nums[i]] == 0) {
                ++count;
            }
            max_ += nums[i];
            ++map[nums[i]];
        }
        for (int i{k - 1}; i < nums.size(); ++i) {
            max_ += nums[i];
            if (map[nums[i]] == 0) {
                ++count;
            }
            ++map[nums[i]];
            if (count == k) {
                max_a = max(max_a, max_);
            }
            max_ -= nums[i - k + 1];
            --map[nums[i - k + 1]];
            if (map[nums[i - k + 1]] == 0) {
                --count;
            }
        }
        return max_a;
    }
};

int main() {
    Solution s;
    printf("ans: %lld\n", s.maximumSubarraySum({4, 4, 4}, 3));
}