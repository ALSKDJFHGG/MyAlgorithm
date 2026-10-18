#include <cassert>
#include <cstddef>
#include <vector>
using namespace std;
/**
leetcode
2134. 最少交换次数来组合所有的 1 II
 */
class Solution {
public:
    int minSwaps(const vector<int>& nums) {
        size_t length = nums.size();
        size_t one_k = [&]() {
            size_t tempN{};
            for (int i{}; i < length; ++i) {
                if (nums[i]) {
                    ++tempN;
                }
            }
            return tempN;
        }();
        if (one_k <= 1 || one_k == length) {
            return 0;
        }
        vector<int> tnums = nums;
        tnums.insert(tnums.end(), nums.begin(), nums.end());
        int max_a{}, max_{};
        for (int i{}; i < length * 2; ++i) {
            if (tnums[i]) {
                ++max_;
            }
            int left = i - one_k + 1;
            if (left < 0) {
                continue;
            }
            max_a = max(max_, max_a);
            if (tnums[left]) {
                --max_;
            }
        }
        return one_k - max_a;
    }
};

int main() {
    Solution s;
    assert(s.minSwaps({0,1,0,1,1,0,0}));
    assert(s.minSwaps({0,1,1,1,0,0,1,1,0}) == 2);
    assert(s.minSwaps({1,1,0,0,1}) == 0);
}