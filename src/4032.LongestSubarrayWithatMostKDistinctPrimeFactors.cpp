#include <array>
#include <unordered_map>
#include <vector>
using namespace std;
/**
leetcode
4032. 至多 K 个不同质因数集合的最长子数组
 */
constexpr int NX = 10'0001;
array<vector<int>, NX> prime_factor;
int init = []() {
    for (int i{2}; i < NX; ++i) {
        if (prime_factor[i].empty()) {
            for (int j{i}; j < NX; j += i) {
                prime_factor[j].push_back(i);
            }
        }
    }
    return 0;
}();
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans{}, left{}, length{static_cast<int>(nums.size())};
        for (int i{0}; i < length; ++i) {
            for (auto& p : prime_factor[nums[i]]) {
                ++cnt[p];
            }
            while (cnt.size() > k) {
                for (auto& p : prime_factor[nums[left]]) {
                    auto it = cnt.find(p);
                    if (--it->second == 0) {
                        cnt.erase(it);
                    }
                }
                ++left;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
