#include <vector>
#include <map>
#include <string>
using namespace std;

/**
 * leetcode
 * 506. 相对名次
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int, greater<int>> m;
        for (int i = 0; i < score.size(); i++) {
            m[score[i]] = i;
        }
        vector<string> ans(score.size());
        auto it = m.begin();
        for (int i = 0; i < score.size(); i++) {
            switch (i)
            {
            case 0:
                ans[(*it).second] = "Gold Medal";
                break;
            case 1:
                ans[(*it).second] = "Silver Medal";
                break;
            case 2:
                ans[(*it).second] = "Bronze Medal";
                break;
            default:
                ans[(*it).second] = to_string(i + 1);
                break;
            }
            it++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 3, 8, 9, 4};
    s.findRelativeRanks(nums);
}