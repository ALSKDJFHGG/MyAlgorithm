#include <string>
#include <unordered_map>
using namespace std;

/**
leetcode
13. 罗马数字转整数
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int length = s.size();
        int ans{map[s[length - 1]]};
        for (int i{length - 2}; i >= 0; --i) {
            if (map[s[i]] < map[s[i + 1]]) {
                ans -= map[s[i]];
            } else {
                ans += map[s[i]];
            }
        }
        return ans;
    }
};