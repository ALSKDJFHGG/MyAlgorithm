#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 88. 合并两个有序数组
 */
class Solution {
public:
    /**
     * 合并后排序
     * 时间复杂度: O((m+n)log(m+n))
     * 空间复杂度: O(1)
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i{}; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    /**
     * 双指针（从后往前）
     * 时间复杂度: O(m + n)
     * 空间复杂度: O(1)
     */
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i{ m - 1 }, j{ n - 1 }, tail{ m + n - 1 };
        int value{};
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[tail--] = nums1[i--];
            } else
            {
                nums1[tail--] = nums2[j--];
            }
            
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s;
    s.merge1(nums1, 3, nums2, 3);
    print(nums1);
    
}