#include <cassert>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/**
leetcode
904. 水果成篮
*/
class Solution {
public:
    int totalFruit(vector<int> fruits) {
        unordered_map<int, int> map;
        std::size_t ans{}, length{fruits.size()};
        int count{}, left{};
        for (int i{}; i < length; ++i) {
            if (map[fruits[i]] == 0) {
                ++count;
                while (count > 2) {
                    --map[fruits[left]];
                    if (map[fruits[left]] == 0) {
                        --count;
                    }
                    ++left;
                }
            }
            ++map[fruits[i]];
            ans = max(ans, static_cast<std::size_t>(i - left + 1));
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.totalFruit({1, 2, 1}) << '\n';
    assert(s.totalFruit({1, 2, 1}) == 3);
    assert(s.totalFruit({0, 1, 2, 2}) == 3);
    assert(s.totalFruit({1, 2, 3, 2, 2}) == 4);
    cout << s.totalFruit({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}) << '\n';
    assert(s.totalFruit({3,3,3,1,2,1,1,2,3,3,4}) == 5);
}