#include <vector>
using namespace std;

/**
leetcode
1572. 矩阵对角线元素的和
 */
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans{};
        for (int i{}; i < n; ++i) {
            ans += mat[i][i] + mat[i][n - i - 1];
        }
        if (n % 2) {
            int del = n / 2;
            ans -= mat[del][del];
        }
        return ans;
    }
};
