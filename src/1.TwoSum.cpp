#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * leetcode
 * 1. 两数之和
 */
class Solution {
public:
    // 暴力枚举
    vector<int> twoSum1(vector<int>& nums, int target) {
        int length = nums.size();

        int i{}, j{};
        for (i; i < length; i++) {
            for (j = i + 1; j < length; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {i, j};
    }

    // 哈希表
    vector<int> twoSum2(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashMap;
        auto length = nums.size();
        for (int i{}; i < length; i++) {
            int complement = target - nums[i];
            if (hashMap.find(complement) != hashMap.end()) {
                return {hashMap[complement], i};
            }
            hashMap[nums[i]] = i;
        }
        return {};
    }
};

void print(vector<int> vec) {
    for (auto v: vec) {
        std::cout<< v << ", ";
    }
    std::cout << std::endl;
}

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    auto a1 = s.twoSum1(nums, 9);

    print(a1);

    auto a2 = s.twoSum2(nums, 9);
    print(a2);

    cout << "Hello World!你好，世界！" << endl;
}