#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/**
leetcode
1297. 子串的最大出现次数
 */
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> map;
        vector<int> cap_char(26, 0);
        size_t kind_n{0}, length{s.size()};
        int max_a{}, max_c{};
        for (int i{0}; i < length; ++i) {
            
        }
    }
};