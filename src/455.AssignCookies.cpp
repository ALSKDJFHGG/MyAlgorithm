#include <algorithm>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 455. 分发饼干
 */
class Solution {
public:
    /**
     * 贪心
     * 先排序，然后从小到大开始比较
     * 时间复杂度: O(mlog m + nlog n)
     * 空间复杂度: O(1)
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int length_g = g.size(),length_s = s.size();
        int result = 0, index = 0;
        for (int i = 0; i < length_s; i++) {
            if (index < length_g && s[i] >= g[index]) {
                result++;
                index++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1_g = {1, 2, 3};
    vector<int> nums1_s = {1, 1};
    print(s.findContentChildren(nums1_g, nums1_s));
    vector<int> nums2_g = {1, 2};
    vector<int> nums2_s = {1, 2, 3};
    print(s.findContentChildren(nums2_g, nums2_s));
    vector<int> nums3_g = {10, 9, 8, 7};
    vector<int> nums3_s = {5, 6, 7, 8};
    print(s.findContentChildren(nums3_g, nums3_s));
    
}