#include <cassert>
#include <cstdlib>
#include <vector>
using namespace std;
/**
leetcode
1652. 拆炸弹
 */
class Solution {
public:
    vector<int> decrypt(vector<int> code, int k) {
        size_t length = code.size();
        vector<int> ans(length, 0);
        if (k == 0) {
            return ans;
        }

        int currentN{}, windowsS{abs(k)};
        for (int i{}; i < length + windowsS - 1; ++i) {
            currentN += code[i % length];

            int left = i - windowsS + 1;
            if (left < 0) {
                continue;
            }

            int tragetI = (k > 0) ? ((left + length - 1) % length) : ((i + 1) % length);
            ans[tragetI] = currentN;

            currentN -= code[left % length];
        }
        return ans;
    }
};

int main() {
    Solution s;
    assert(s.decrypt({5, 7, 1, 4}, 3) == static_cast<vector<int>>{12, 10, 16, 13});
    return 0;
}