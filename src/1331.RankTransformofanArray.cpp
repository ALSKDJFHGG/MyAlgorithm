#include "../include/print.h"
#include <unordered_map>
#include <algorithm>

/**
 * leetcode
 * 1331. 数组序号转换
 */
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> map;
        for (auto a: arr) {
            map[a] = 0;
        }
        vector<int> temp = arr, ans(arr.size());
        sort(temp.begin(), temp.end());
        int i = 1, length = arr.size();
        map[temp[0]] = i;
        while (i < length) {
            map[temp[i]] = i;
            if (temp[i - 1] != temp[i]) {
                i++;
            }
        }
        for (i = 0; i < length; i++) {
            ans[i] = map[arr[i]];
        }
        return ans;
    }
};

int main() {
    
}