#include <vector>
#include <iostream>
using namespace std;

/**
 * leetcode
 * 118. 杨辉三角
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            ans.push_back(vector<int>(row, 1));
            int currentRow = row - 1;
            for (int line = 1; line < row - 1; line++) {
                ans[currentRow][line] = ans[currentRow - 1][line - 1] + ans[currentRow - 1][line];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int numRow = 10;
    s.generate(numRow);

    cout << "hi" << endl;

    return 0;
}