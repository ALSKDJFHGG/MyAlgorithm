#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * leetcode
 * 575. 分糖果
 */
class Solution {
public:
    int distributeCandies1(vector<int>& candyType) {
        int kindNum = 0;
        sort(candyType.begin(), candyType.end());
        for (int i = 1; i < candyType.size(); i++) {
            if (candyType[i] != candyType[i - 1]) {
                kindNum++;
            }
        }
        if (kindNum < candyType.size() / 2) {
            return kindNum + 1;
        }
        return candyType.size() / 2;
    }
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set(candyType.begin(), candyType.end());
        return min(set.size(), candyType.size() / 2);
    }
};
