#include <iostream>
#include <vector>
using namespace std;

/**
leetcode
54. 螺旋矩阵
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
    } 
};

int main() {
    Solution s;
    vector<vector<int>> vet = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto ans = s.spiralOrder(vet);
    cout << "hello";
}
