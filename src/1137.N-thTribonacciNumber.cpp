#include <vector>
using namespace std;

/**
 * leetcode
 * 1137. 第 N 个泰波那契数
 */
class Solution {
public:
    vector<int> memory = vector<int>(38, 0);
    int tribonacci(int n) {
        if (n <= 1) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        if (memory[n] != 0) {
            return memory[n];
        }
        memory[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return memory[n];
    }
};