#include <vector>
using namespace std;
/**
1052. 爱生气的书店老板
 */
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int length = customers.size();
        int max_a{}, max_{}, s0{};
        for (int i{}; i < minutes - 1; ++i) {
            max_ += customers[i] * grumpy[i];
            s0 += customers[i] * (1 - grumpy[i]);
        }
        for (int i{minutes - 1}; i < length; ++i) {
            max_ += customers[i] * grumpy[i];
            max_a = max(max_, max_a);
            max_ -= customers[i - minutes + 1] * grumpy[i - minutes + 1];
            s0 += customers[i] * (1 - grumpy[i]);
        }
        return s0 + max_a;
    }
};

