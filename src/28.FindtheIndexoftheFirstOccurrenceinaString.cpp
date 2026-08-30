#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
kmp算法
28. 找出字符串中第一个匹配项的下标
 */
class Solution {
public:
    int strStr1(string haystack, string needle) {
        int length1 = haystack.size();
        int length2 = needle.size();
        if (length2 == 0) {
            return 0;
        }
        int i{}, j{};
        for (i = 0; i <= length1 - length2; i++) {
            int k = i, j = 0;
            while (haystack[k] == needle[j] && j < length2) {
                k++;
                j++;
            }
            if (j == length2) {
                return i;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        int length1 = haystack.size();
        int length2 = needle.size();
        if (length2 == 0) {
            return 0;
        }
        vector<int> next = getNext(needle);
        int j = 0;
        for (int i = 0; i < length1; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == length2) {
                return i - length2 + 1;
            }
        }
        return -1;
    }
    vector<int> getNext(string pattern) {
        int length = pattern.size();
        int j = 0;
        vector<int> next(length, 0);
        for (int i = 1; i < length; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
};

int main() {
    Solution s;
    string s1 = "abcabcabca";
    string s2 = "abc";
    cout << s.strStr(s1, s2);
}