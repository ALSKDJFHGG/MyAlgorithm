#include <vector>
using namespace std;

/**
 * leetcode
 * 598. 区间加法 II
 */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int length = ops.size();
        if (length == 0) {
            return m * n;
        }
        int minX = m, minY = n;
        for (int i = 0; i < length; i++) {
            minX = min(minX, ops[i][0]);
            minY = min(minY, ops[i][1]);
        }
        return minX * minY;
    }
};
