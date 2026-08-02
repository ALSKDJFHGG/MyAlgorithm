#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/**
 * leetcode
 * 496. 下一个更大元素 I
 */
class Solution
{
public:
    /**
     * 暴力解法
     */
    vector<int> nextGreaterElement1(vector<int> &nums1, vector<int> &nums2)
    {
        int length1 = nums1.size(), length2 = nums2.size();
        vector<int> ans(length1, -1);
        bool flag = false;
        for (int i = 0; i < length1; i++)
        {
            flag = false;
            for (int j = 0; j < length2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    flag = true;
                }
                if (flag && nums1[i] < nums2[j])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
    /**
     * 单调栈解法接
     */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> map;
        int length = nums2.size();
        for (int i = length - 1; i >= 0; i--) {
            int currentNum = nums2[i];
            while (!st.empty() && currentNum > st.top()) {
                st.pop();
            }
            map[currentNum] = st.empty() ? -1 : st.top();
            st.push(currentNum);
        }
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = map[nums1[i]];
        }
        return nums1;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3, 5, 2, 4};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    /**
     * 4 1 2
     * 1 3 4 2
     * -1 3 -1
     */
    s.nextGreaterElement1(nums1, nums2);
}