#include <string>
#include <unordered_map>
using namespace std;

/**
leetcode
242. 有效的字母异位词
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        int length1 = s.size();
        for (int i{}; i < length1; i++) {
            map[s[i]]++;
        }
        int length2 = t.size();
        for (int i{}; i < length2; i++) {
            if (map[t[i]] == 0) {
                return false;
            }
            map[t[i]] -= 1;
        }
        for (auto& pair : map) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
    }
};
