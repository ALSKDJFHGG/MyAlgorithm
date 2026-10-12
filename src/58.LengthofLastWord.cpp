#include <iostream>
#include <string>
using namespace std;

/**
leetcode
58. 最后一个单词的长度
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size() - 1;
        while (s[length] == ' ') {
            --length;
        }
        int count{};
        for (int i{length}; i >= 0; --i) {
            if (s[i] == ' ') {
                break;
            }
            count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("qwewqe w   w wee   weeee    ");
}
