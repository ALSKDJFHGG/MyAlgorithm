#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

/**
2379. 得到 K 个黑块的最少涂色次数
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min_w{k}, count_w{};
        for (int i{}; i < k - 1; ++i) {
            if (blocks[i] == 'W') {
                ++count_w;
            }
        }
        for (int i{k - 1}; i < blocks.size(); ++i) {
            if (blocks[i] == 'W') {
                ++count_w;
            }
            min_w = min(min_w, count_w);
            if (min_w == 0) {
                return min_w;
            }
            if (blocks[i - k + 1] == 'W') {
                --count_w;
            }
        }
        return min_w;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.minimumRecolors("WBWBBBW", 2));
}