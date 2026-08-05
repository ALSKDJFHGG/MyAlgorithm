#include <vector>
#include <unordered_map>
using namespace std;

/**
 * leetcode
 * 594. 最长和谐子序列
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }
        int ans = 0;
        for (auto& [k, v] : map) {
            if (map.count(k + 1)) {
                ans = max(ans, v + map[k + 1]);
            }
        }
        return ans;
    }
};
