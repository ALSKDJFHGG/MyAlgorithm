#include "../include/print.h"

/**
 * leetcode
 * 463. 岛屿的周长 
 */
class Solution {
public:
    /**
     * 双循环遍历判断
     */
    int islandPerimeter(vector<vector<int>>& grid) {
        int length = grid.size(), wild = grid[0].size();
        int circumference = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < wild; j++) {
                if (grid[i][j] == 1) {
                    if (j - 1 < 0 || grid[i][j - 1] == 0) {
                        circumference++;
                    }
                    if (i - 1 < 0 || grid[i - 1][j] == 0) {
                        circumference++;
                    }
                    if (i + 1 >= length || grid[i + 1][j] == 0) {
                        circumference++;
                    }
                    if (j + 1 >= wild || grid[i][j + 1] == 0) {
                        circumference++;
                    }
                }
            }
        }
        return circumference;
    }
};