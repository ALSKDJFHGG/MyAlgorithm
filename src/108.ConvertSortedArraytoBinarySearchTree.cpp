#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeNode(int i, int j, TreeNode* node, vector<int>& nums) {
    if (i > j) {
        return nullptr;
    }
    int m = (i + j) / 2;
    node->val = nums[m];
    TreeNode* nodeLeft = new TreeNode();
    node->left = buildTreeNode(i, m - 1, nodeLeft, nums);
    TreeNode* nodeRight = new TreeNode();
    node->right = buildTreeNode(m + 1, j, nodeRight, nums);
    return node;
}

/**
 * leetcode
 * 108. 将有序数组转换为二叉搜索树
 */
class Solution
{
public:
    /**
     * 将有序数组转换为平衡二叉搜索树
     * 时间复杂度: O(n) — 每个元素访问一次
     * 空间复杂度: O(log n) — 递归栈深度为平衡树高度
     */
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode* node = new TreeNode();
        TreeNode* Node = buildTreeNode(0, nums.size() - 1, node, nums);
        return Node;
    }
};

void printTreeNode(TreeNode* node) {
    if (node == nullptr) {
        std::cout << "nullptr, ";
        return;
    }
    std::cout << node->val << ", ";
    printTreeNode(node->left);
    printTreeNode(node->right);
}

int main() {
    Solution s;
    // vector<int> nums{-10, -3, 0, 5, 9};
    vector<int> nums{1, 3};
    TreeNode* ans = s.sortedArrayToBST(nums);
    printTreeNode(ans);
}