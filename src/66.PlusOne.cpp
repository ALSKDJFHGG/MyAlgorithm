#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 66. 加一
 */
class Solution {
public:
    /**
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int i = length - 1;
        while (i >= 0)
        {
            if (digits[i] != 9) {
                digits[i] += 1;
                break;
            }
            digits[i] = 0;
            i--;
        }
        if (i < 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 3, 2, 1};
    vector<int> nums3 = {9};
    
    s.plusOne(nums1);
    s.plusOne(nums2);
    s.plusOne(nums3);

    print(nums1);
    print(nums2);
    print(nums3);

}