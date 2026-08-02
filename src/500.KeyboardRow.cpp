#include <vector>
#include <string>
using namespace std;

/**
 * leetcode
 * 500. 键盘行
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string wordToId = "12210111011122000010020202";
        for (auto &word : words)
        {
            int currentLine = wordToId[tolower(word[0]) - 'a'];
            bool isValid = true;
            for (auto &w : word) {
                if (wordToId[tolower(w) - 'a'] != currentLine) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};