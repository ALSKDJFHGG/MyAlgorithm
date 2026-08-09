#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
/**
 * time: O(n)
 * space: O(n)
 */
    int calPoints(vector<string>& operations) {
        stack<int> numSave;
        int ans{};
        int length = operations.size();
        for (int i = 0; i < length; i++) {
            if (operations[i] == "D") {
                numSave.push(numSave.top() * 2);
            } else if (operations[i] == "C") {
                numSave.pop();
            } else if (operations[i] == "+") {
                int tempTopNum = numSave.top();
                numSave.pop();
                int sum2Num = tempTopNum + numSave.top();
                numSave.push(tempTopNum);
                numSave.push(sum2Num);
            } else {
                int tempNum = string2num(operations[i]);
                numSave.push(tempNum);
            }
        }
        while (!numSave.empty())
        {
            ans += numSave.top();
            numSave.pop();
        }
        return ans;
    }
private:
    int string2num(string& str) {
        int sum = 0;
        int isPostive = true;
        for (auto s : str) {
            if (s == '-') {
                isPostive = false;
            }
            else {
                sum = sum * 10 + (s - '0');
            }
        }
        return isPostive ? sum : -sum;
    }
};

int main() {
    Solution s;
    vector<string> test1 = {"5","-2","4","C","D","9","+","+"};
    s.calPoints(test1);
}