#include "../include/print.h"
#include <queue>
using namespace std;

/**
 * leetcode
 * 463. 岛屿的周长
 */
class Solution
{
public:
    /**
     * 双循环遍历判断
     */
    int islandPerimeter1(vector<vector<int>> &grid)
    {
        int length = grid.size(), wild = grid[0].size();
        int circumference = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < wild; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                    {
                        circumference++;
                    }
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                    {
                        circumference++;
                    }
                    if (i + 1 >= length || grid[i + 1][j] == 0)
                    {
                        circumference++;
                    }
                    if (j + 1 >= wild || grid[i][j + 1] == 0)
                    {
                        circumference++;
                    }
                }
            }
        }
        return circumference;
    }
    
    /**
     * dfs
     */
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
    int dfs(int x, int y, vector<vector<int>>& grid, int wild, int height) {
        if (x < 0 || x >= wild || y < 0 || y >= height || grid[x][y] == 0) {
            return 1;
        }
        if (grid[x][y] == 2) {
            return 0;
        }
        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, wild, height); 
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>> &grid) {
        int wild = grid.size(), height = grid[0].size();
        int ans = 0;
        for (int i = 0; i < wild; i++) {
            for (int j = 0; j < height; j++) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, wild, height);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    printf("%d\n", s.islandPerimeter(grid));
}