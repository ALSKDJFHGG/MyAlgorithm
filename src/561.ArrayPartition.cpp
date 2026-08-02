#include <vector>
#include <algorithm>
using namespace std;

/**
 * leetcode
 * 561. 数组拆分
 * 1 2 2 5 6 6 
 * 1 2 6
 * 2 5 6
 * 1 2 3 4
 * 1 3
 * 2 4
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans{};
        for (int i = 0; i < nums.size(); i+=2) {
            ans += nums[i];
        }
        return ans;
    }
};