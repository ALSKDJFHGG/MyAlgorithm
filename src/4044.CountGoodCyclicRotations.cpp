#include <cassert>
#include <cstddef>
#include <vector>
using namespace std;
/**
leetcode
4044. 统计好循环移位的数量
 */
class Solution {
public:
    int countGoodRotations(const vector<int>& nums) {
        vector<int> tnums = nums;
        tnums.insert(tnums.end(), nums.begin(), nums.end());
        int length = nums.size();
        int k = length / 2;
        size_t frontN{}, endN{}, ans{};
        for (int i{k}; i < length * 2 - 1; ++i) {
            frontN += tnums[i - k];
            endN += tnums[i];

            int left = i - k + 1;
            if (left < k) {
                continue;
            }

            if (frontN > endN) {
                ++ans;
            }

            frontN -= tnums[left - k];
            endN -= tnums[left];
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.countGoodRotations({1, 2, 3, 4, 5, 6}) == 3);
    assert(s.countGoodRotations({1, 2, 1, 2}) == 0);
}