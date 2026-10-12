#include <string>
#include <vector>
using namespace std;

/**
leetcode
1275. 找出井字棋的获胜者
*/
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> playA(3, vector<int>(3));
        vector<vector<int>> playB(3, vector<int>(3));
        int row = moves.size();
        int x{}, y{};
        for (int i{}; i < row; ++i) {
            x = moves[i][0];
            y = moves[i][1];
            if (i % 2 == 0) {
                playA[x][y] = 1;
                if (checkWin(playA)) {
                    return "A";
                }
            } else {
                playB[x][y] = 1;    
                if (checkWin(playB)) {
                    return "B";
                }
            }
        }
        vector<vector<int>> sum(3, vector<int>(3, 0));
        for (int i{}; i < 3; ++i) {
            for (int j{}; j < 3; ++j) {
                sum[i][j] = playA[i][j] + playB[i][j];
            }
        }
        for (int i{}; i < 3; ++i) {
            for (int j{}; j < 3; ++j) {
                if (sum[i][j] == 0) {
                    return "Pending";
                }
            }
        }
        return "Draw";
    }

    bool checkWin(const vector<vector<int>>& nums) {
        int sum{};
        for (int x{}; x < 3; ++x) {
            sum = 0;
            sum += nums[x][0] + nums[x][1] + nums[x][2];
            if (sum == 3) {
                return true;
            }
        }
        for (int y{}; y < 3; ++y) {
            sum = 0;
            sum += nums[0][y] + nums[1][y] + nums[2][y];
            if (sum == 3) {
                return true;
            }
        }
        if (nums[0][0] + nums[1][1] + nums[2][2] == 3 || nums[0][2] + nums[1][1] + nums[2][0] == 3) {
            return true;
        }
        return false;
    }
};
