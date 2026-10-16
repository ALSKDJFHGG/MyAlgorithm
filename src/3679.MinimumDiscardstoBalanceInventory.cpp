#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
/**
3679. 使库存平衡的最少丢弃次数
*/
class Solution {
public:
    int minArrivalsToDiscard(vector<int> arrivals, int w, int m) {
        unordered_map<int, int> map;
        int length = arrivals.size();
        int ans{};
        for (int i{}; i < length; ++i) {
            ++map[arrivals[i]];
            if (map[arrivals[i]] > m) {
                --map[arrivals[i]];
                ++ans;
                arrivals[i] = 0;
            }

            if (i >= w - 1 && map[arrivals[i - w + 1]] != 0) {
                --map[arrivals[i - w + 1]];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    printf("ans: %d\n", s.minArrivalsToDiscard({7,3,9,9,7,3,5,9,7,2,6,10,9,7,9,1,3,6,2,4,6,2,6,8,4,8,2,7,5,6}, 10, 1));
}