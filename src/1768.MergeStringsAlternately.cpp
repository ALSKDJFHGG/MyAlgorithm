#include <iostream>
#include <string>
using namespace std;

/**
* leetcode
* 1768. 交替合并字符串
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length1 = word1.size();
        int length2 = word2.size();
        string reslut{};
        int i{}, j{};
        while (i < length1 || j < length2) {
            if (i < length1) {
                reslut += word1[i++];
            }
            if (j < length2) {
                reslut += word2[j++];
            }
        }
        return reslut;
    }
};

int main() {
    Solution s;
    string w1 = "abc";
    string w2 = "pqr";
    string r = s.mergeAlternately(w1, w2);
    cout << r << endl;
}
