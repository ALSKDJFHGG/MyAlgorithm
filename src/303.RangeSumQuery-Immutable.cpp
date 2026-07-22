#include "../include/print.h"

/**
 * leetcode
 * 303. 区域和检索 - 数组不可变
 * 前缀和
 */
class NumArray
{
private:
    vector<int> array;

public:
    NumArray(vector<int> &&nums)
    {
        int sum = 0, i = 0;
        int length = nums.size();
        array.resize(length + 1);
        for (i = 0; i < length; i++)
        {
            sum += nums[i];
            array[i + 1] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        return array[right + 1] - array[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    NumArray numArray = NumArray({ -2, 0, 3, -5, 2, -1 });
    print(numArray.sumRange(0, 2)); // return 1 ((-2) + 0 + 3)
    print(numArray.sumRange(2, 5)); // return -1 (3 + (-5) + 2 + (-1))
    print(numArray.sumRange(0, 5)); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
}