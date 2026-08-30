#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int length1 = s.size();
        int length2 = t.size();
        int sum1{}, sum2{};
        for (int i = 0; i < length1; i++) {
            sum1 += s[i];
        }
        for (int i = 0; i < length2; i++) {
            sum2 += t[i];
        }
        return sum2 - sum1;
    }
};


int main() {
    Solution s;
    string s1 = "abcd";
    string s2 = "abcde";
    char res = s.findTheDifference(s1, s2);
    cout << res << endl;
}