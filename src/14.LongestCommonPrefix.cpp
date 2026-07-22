#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"

/**
 * leetcode
 * 14. 最长公共前缀
 */
class Solution {
public:
    // 暴力解法
    /*
    https://leetcode.cn/problems/longest-common-prefix/submissions/734504217
        1.先获取第一个单词
        2.对获取的单词遍历，获取字母
        3.对单词列表遍历, 比较第一个单词的下标对应获取列表的单词下标
        4.如果
        word
        word

        exampleword
        word

        word
        exampleword
    */
    string longestCommonPrefix1(vector<string>& strs) {
        string answer{};
        auto word = strs[0];
        auto length = strs.size();
        auto wordLength = word.size();
        for (int i{}; i < wordLength; i++) {
            auto cerrentSingleWord = word[i];
            bool is_simple = true;
            for (int j{}; j < length; j++) {
                auto compaseWord = strs[j];
                auto compaseWordLength = compaseWord.size();
                if (cerrentSingleWord != compaseWord[i]) {
                    is_simple = false;
                    return answer;
                }
            }
            if (is_simple) {
                answer.push_back(word[i]);
            }
        }
        return answer;
    }
    // 对字符串排序, 然后只比较头尾字符串
    string longestCommonPrefix2(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        auto firstWord = strs.front();
        auto endWord = strs.back();

        int i{}, j{};

        string answer{};

        while (i < firstWord.size() && j < endWord.size()) {
            if (firstWord[i] != endWord[j]) {
                break;
            }
            answer.push_back(firstWord[i]);
            i++;
            j++;
        }
        return answer;
    }
};



int main() {
    vector<string> strs1 = {"flower","flow","flight"};

    vector<string> strs2 = {"dog","racecar","car"};
    vector<string> strs3 = {"cir","car"};
    
    Solution s;
    auto ans1 = s.longestCommonPrefix1(strs1);
    auto ans2 = s.longestCommonPrefix1(strs2);
    auto ans3 = s.longestCommonPrefix1(strs3);

    print(ans1);
    print(ans2);
    print(ans3);
}