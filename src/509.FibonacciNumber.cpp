#include <vector>
using namespace std;

/**
 * leetcode
 * 509. 斐波那契数
 */
class Solution {
public:
    vector<int> memory = vector<int>(31, 0);
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        if (memory[n] != 0) {
            return memory[n];
        }
        memory[n] = fib(n - 1) + fib(n - 2);
        return memory[n];
    }
};


