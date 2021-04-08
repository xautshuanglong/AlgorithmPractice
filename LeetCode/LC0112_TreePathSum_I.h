#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0112_TreePathSum_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0112_TreePathSum_I --> MainEntry" << std::endl;

        // 输入：root = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1], targetSum = 22
        // 输出：true
        int targetSum1 = 22;
        std::vector<int> root1Vec = { 5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, INT_MIN, 1 };
        TreeNode *root1 = LeetCodeTreeNodeCreate(root1Vec);

        // 输入：root = [1, 2, 3], targetSum = 5
        // 输出：false
        int targetSum2 = 5;
        std::vector<int> root2Vec = { 1, 2, 3 };
        TreeNode *root2 = LeetCodeTreeNodeCreate(root2Vec);

        // 输入：root = [1, 2], targetSum = 0
        // 输出：false
        int targetSum3 = 0;
        std::vector<int> root3Vec = { 1, 2 };
        TreeNode *root3 = LeetCodeTreeNodeCreate(root3Vec);

        // 输入：root = [-2, null, -3], targetSum = -5
        // 输出：false
        int targetSum4 = -5;
        std::vector<int> root4Vec = { -2, INT_MIN, -3 };
        TreeNode *root4 = LeetCodeTreeNodeCreate(root4Vec);

        std::cout << "LC0112_TreePathSum_I --> Result 1 : " << this->hasPathSum(root1, targetSum1) << std::endl;
        std::cout << "LC0112_TreePathSum_I --> Result 2 : " << this->hasPathSum(root2, targetSum2) << std::endl;
        std::cout << "LC0112_TreePathSum_I --> Result 3 : " << this->hasPathSum(root3, targetSum3) << std::endl;
        std::cout << "LC0112_TreePathSum_I --> Result 4 : " << this->hasPathSum(root4, targetSum4) << std::endl;

        LeetCodeTreeNodeDestory(&root1);
        LeetCodeTreeNodeDestory(&root2);
        LeetCodeTreeNodeDestory(&root3);

        return 0;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return this->traversalDFS(root, targetSum, 0);
    }

    bool traversalDFS(TreeNode *root, int targetSum, int curSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        curSum += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            return curSum == targetSum;
        }

        return traversalDFS(root->left, targetSum, curSum) || traversalDFS(root->right, targetSum, curSum);
    }
};
