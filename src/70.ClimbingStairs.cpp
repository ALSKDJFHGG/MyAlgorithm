#include <vector>
using namespace std;

/**
 * leetcode
 * 70. 爬楼梯
 */
class Solution {
public:
/**
 * 递归加记忆化搜索
 * 时间: O(n)
 * 空间: O(n)
 */
    vector<int> cliM = vector<int>(46, 0);
    int climbStairs(int n)
    {
        if (n <= 2) {
            return n;
        }
        if (cliM[n] != 0) {
            return cliM[n];
        }
        cliM[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return cliM[n];
    }
};