#include <vector>
#include <string>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 228. 汇总区间
 */
class Solution
{
public:
    /**
     * 顺序遍历
     */
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int length = nums.size();
        int i, k = 0;
        if (length == 0)
        {
            return ans;
        }
        
        for (i = 1; i < length; i++)
        {

            if ((long long)nums[i] - nums[k] != i - k)
            {
                if (nums[i - 1] == nums[k])
                {
                    ans.push_back(to_string(nums[k]));
                }
                else
                {
                    string temp = to_string(nums[k]) + "->" + to_string(nums[i - 1]);
                    ans.push_back(temp);
                }
                k = i;
            }
        }
        if (nums[i - 1] == nums[k])
        {
            ans.push_back(to_string(nums[k]));
        }
        else
        {
            string temp = to_string(nums[k]) + "->" + to_string(nums[i - 1]);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    print(s.summaryRanges(nums1));

    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    print(s.summaryRanges(nums2));

    vector<int> nums3 = {-1};
    print(s.summaryRanges(nums3));

    vector<int> nums4 = {0, 1};
    print(s.summaryRanges(nums4));

    vector<int> nums5 = {};
    print(s.summaryRanges(nums5));
}