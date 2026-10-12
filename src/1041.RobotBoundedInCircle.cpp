#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
leetcode
1041. 困于环中的机器人
 */
class Solution {
public:
    bool isRobotBounded(string instructions) {
        const vector<vector<int>> forth = {
            {0, 1}, {-1, 0},
            {0, -1}, {1, 0}
        };
        int strigth = 0;
        int x{}, y{};
        for (int i{}; i < 4; ++i) {
            for (auto& s : instructions) {
                if (s == 'G') {
                    x += forth[strigth][0];
                    y += forth[strigth][1];
                }
                if (s == 'L') {
                    strigth = (strigth + 1) % 4;
                }
                if (s == 'R') {
                    strigth = (strigth + 3) % 4;
                }
            }
        }
        if (x == 0 && y == 0) {
            return true;
        }
        return false;
    }
};
