#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/**
1423. 可获得的最大点数
 */
class Solution {
public:
    int maxScore(const vector<int>& cardPoints, int k) {
        int length = cardPoints.size();
        if (k == length) {
            return [&]() {
                int n{};
                for (int i{}; i < length; ++i) {
                n += cardPoints[i];
                }
                return n;
            }();
        }
        vector<int> temp(2 * k);
        for (int i{length - k}; i < length; ++i) {
            temp[k + i - length] = cardPoints[i];
        }
        for (int i{}; i < k; ++i) {
            temp[i + k] = cardPoints[i];
        }
        int count_{}, max_a{};
        for (int i{}; i < k - 1; ++i) {
            count_ += temp[i];
        }
        for (int i{k - 1}; i < 2 * k; ++i) {
            count_ += temp[i];
            max_a = max(max_a, count_);
            count_ -= temp[i - k + 1];
        }
        return max_a;
    }
};

int main() {
    Solution s;
    printf("ans: %d\n", s.maxScore({1,79,80,1,1,1,200,1}, 3));
}