#include "../include/print.h"

/**
 * leetcode
 * 119. 杨辉三角 II
 */
class Solution
{
public:
    /**
     *      n!         k     k - 1     n - k + 1 
     *   --------- = C   = C        * ----------
     *    k!(n-k)!     n     n              k
     * 
     */
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int k = 1; k <= rowIndex; k++) {
            ans[k] = 1LL * ans[k - 1] * (rowIndex - k + 1) / k;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    print(s.getRow(13));
}