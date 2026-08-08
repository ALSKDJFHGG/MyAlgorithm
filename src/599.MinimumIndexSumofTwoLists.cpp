#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * leetcode
 * 599. 两个列表的最小索引总和
 */
class Solution
{
public:
/**
 * 哈希表
 * time: O(n)
 * space: O(n)
 */
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int length1 = list1.size(), length2 = list2.size();
        unordered_map<string, int> indexMap;
        for (int i = 0; i < length1; i++)
        {
            indexMap[list1[i]] = i;
        }
        vector<string> ret;
        int minIndex = length1 + length2;
        for (int i = 0; i < length2; i++)
        {
            if (indexMap.count(list2[i])) {
                int sum = i + indexMap[list2[i]];
                if (sum < minIndex) {
                    minIndex = sum;
                    ret.clear();
                    ret.push_back(list2[i]);
                } else if (sum == minIndex) {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};
