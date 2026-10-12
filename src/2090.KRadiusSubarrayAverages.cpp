#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
/**
2090. 半径为 k 的子数组平均值
 */
class Solution {
public:
    vector<int> getAverages(vector<int> nums, int k) {
        int length = nums.size();
        vector<int> ans(length, -1);
        if (2 * k >= length) {
            return ans;
        }
        int win_k{2 * k + 1};
        size_t win_s{};
        for (int i{}; i < win_k - 1; ++i) {
            win_s += nums[i];
        }
        for (int i{win_k - 1}; i < length; ++i) {
            win_s += nums[i];
            ans[i - k] = win_s / win_k;
            win_s -= nums[i - win_k + 1];
        }
        return ans;
    }
};

template<typename T>
void print(const vector<T>& arr) {
    for (auto& a_ : arr) {
        cout << a_ << ", ";
    }
    cout << "\n";
}

int main() {
    Solution s;
    print(s.getAverages({7,4,3,9,1,8,5,2,6}, 3));
}