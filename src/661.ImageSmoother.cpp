#include <vector>
using namespace std;

/**
 * leetcode
 * 661. 图片平滑器
 */
class Solution {
public:
/**
 * 前缀和
 * time: O(m * n)
 * space: O(m * n)
 */
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> sum(m + 10, vector<int>(n + 10, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int a = max(0, i - 1), b = max(0, j - 1);
                int c = min(m - 1, i + 1), d = min(n - 1, j + 1);
                int cnt = (c - a + 1) * (d - b + 1);
                int tot = sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] + sum[a][b];
                ans[i][j] = tot / cnt;
            }
        }
        return ans;
    }
};
