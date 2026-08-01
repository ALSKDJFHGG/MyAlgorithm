#include <vector>
#include <iostream>
using namespace std;

/**
 * leetcode
 * 495. 提莫攻击
 */
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int ans = 0, expire = 0;
        int length = timeSeries.size();
        for (int i = 0; i < length; i++)
        {
            if (timeSeries[i] >= expire)
            {
                ans += duration;
            }
            else
            {
                ans += timeSeries[i] + duration - expire;
            }
            expire = timeSeries[i] + duration;
        }
        return ans;
    };
} int main()
{
    Solution s;
    vector<int> time = {1, 4};
    s.findPoisonedDuration(time, 2);
}