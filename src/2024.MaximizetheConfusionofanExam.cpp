#include <cassert>
#include <string>
using namespace std;
/**
leetcode
2024. 考试的最大困扰度
 */
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int tCount{}, fCount{}, count{}, length{static_cast<int>(answerKey.size())}, ans{}, left{};
        for (int i{}; i < length; ++i) {
            char currentChar = answerKey[i];
            if (currentChar == 'T') {
                ++tCount;
            } else {
                ++fCount;
            }
            count = min(tCount, fCount);
            while (count > k) {
                char leftChar = answerKey[left];
                if (leftChar == 'T') {
                    --tCount;
                } else {
                    --fCount;
                }
                count = min(tCount, fCount);
                ++left;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.maxConsecutiveAnswers("TTFF", 2) == 4);
    assert(s.maxConsecutiveAnswers("TFFT", 1) == 3);
    assert(s.maxConsecutiveAnswers("TTFTTFTT", 1) == 5);
}