#include <vector>
#include <iostream>
using namespace std;

/**
 * leetcode
 * 485. 最大连续 1 的个数
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int ans = 0, max = 0, length = nums.size();
       for (int i = 0; i < length; i++) {
           if (nums[i])
           {
                ans += 1;
           }
           else
           {
                
               ans = 0;
           }
           if (ans > max) {
                    max = ans;
                }
       } 
       return max;
    }
};