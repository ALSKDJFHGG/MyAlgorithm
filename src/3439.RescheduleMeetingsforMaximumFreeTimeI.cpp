#include <cstdio>
#include <vector>
using namespace std;
/**
leetcode
3439. 重新安排会议得到最多空余时间 I
 */
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int> startTime, vector<int> endTime) {
        size_t free_length = startTime.size();
        vector<int> free_time(free_length + 1, 0);
        free_time[0] = startTime[0];
        for (int i{1}; i < free_length; ++i) {
            free_time[i] = startTime[i] - endTime[i - 1];
        }
        free_time[free_length] = eventTime - endTime[free_length - 1];
        int max_a{}, max_{};
        for (int i{}; i < k; ++i) {
            max_ += free_time[i];
        }
        for (int i{k}; i < free_length + 1; ++i) {
            max_ += free_time[i];
            max_a = max(max_a, max_);
            max_ -= free_time[i - k];
        }
        return max_a;
    }
};

int main() {
    Solution s;
    printf("ans: %d\n", s.maxFreeTime(10, 1, {0, 2, 9}, {1, 4, 10}));
}