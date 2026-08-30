#include <string>
#include <vector>
using namespace std;

/**
leetcode
459. 重复的子字符串
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        auto res = getNext(s);
        if (res[s.size() - 1] > 0 && s.size() % (s.size() - res[s.size() - 1]) == 0) {
            return true;
        }
        return false;
    }
    vector<int> getNext(const string& s) {
        int length = s.size();
        vector<int> next(length, 0);
        int j = 0;
        for (int i = 1; i < length; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
};

int main() {
    Solution s;
    s.repeatedSubstringPattern("abac");
}