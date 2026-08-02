#include <vector>
using namespace std;

/**
 * leetcode
 * 566. 重塑矩阵
 * h w
 * 2 4
 *   0 1 2 3
 * 0 1 2 3 4
 * 1 5 6 7 8
 * 
 * r c
 * 4 2 
 *   0 1
 * 0 1 2
 * 1 3 4
 * 2 5 6
 * 3 7 8
 * 
 * h w
 * 2 2
 *   0 1
 * 0 1 2
 * 1 3 4
 * c r
 * 1 4
 *   0 1 2 3
 * 0 1 2 3 4
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int h = mat.size(), w = mat[0].size();
        if (h * w != r * c) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int hw = i * w + j;
                int cr = hw % c;
                int cc = hw / c;
                ans[cr][cc] = mat[i][j];
            }
        }
        return ans;
    }
};
