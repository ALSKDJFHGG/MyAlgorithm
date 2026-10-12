#include <cstdio>
#include <vector>
using namespace std;

/**
1343. 大小为 K 且平均值大于等于阈值的子数组数目
 */
class Solution {
public:
    int numOfSubarrays(vector<int> arr, int k, int threshold) {
        int wind_sum{};
        for (int i{}; i < k - 1; ++i) {
            wind_sum += arr[i];
        }
        int ans{0};
        for (int i{k - 1}; i < arr.size(); ++i) {
            wind_sum += arr[i];
            if (wind_sum >= threshold * k) {
                ++ans;
            }
            wind_sum -= arr[i - k + 1];
        }
        return ans;
    }
};

int main() {
    Solution s;
    printf("ans: %d\n", s.numOfSubarrays({2,2,2,2,5,5,5,8}, 3, 4));
}