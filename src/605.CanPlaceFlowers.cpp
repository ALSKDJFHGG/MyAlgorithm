#include <vector>
using namespace std;

/**
 * leetcode
 * 605. 种花问题
 */
class Solution {
public:
/**
 * time: O(n)
 * space: O(n)
 */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        int length = flowerbed.size() - 2;
        for (int i = 1; i <= length; i++) {
            if (flowerbed[i - 1] + flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return false ? n == 0 : n;
    }
};

int main() {
    Solution s;
    vector<int> test1 = {1, 0, 0, 0, 1, 0, 0};
    int n = 2;
    s.canPlaceFlowers(test1, n);
}