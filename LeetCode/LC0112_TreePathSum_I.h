#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC007LC0112_TreePathSum_I0_ClimbStairs : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0112_TreePathSum_I --> MainEntry" << std::endl;

        // ���룺root = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1], targetSum = 22
        // �����true
        int targetSum1 = 22;
        TreeNode *root1 = nullptr;

        // ���룺root = [1, 2, 3], targetSum = 5
        // �����false
        int targetSum2 = 5;
        TreeNode *root2 = nullptr;

        // ���룺root = [1, 2], targetSum = 0
        // �����false
        int targetSum3 = 0;
        TreeNode *root3 = nullptr;

        std::cout << "LC0112_TreePathSum_I --> Result 1 : " << this->hasPathSum(root1, targetSum1) << std::endl;
        std::cout << "LC0112_TreePathSum_I --> Result 2 : " << this->hasPathSum(root2, targetSum2) << std::endl;
        std::cout << "LC0112_TreePathSum_I --> Result 3 : " << this->hasPathSum(root3, targetSum3) << std::endl;

        return 0;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return false;
    }
};
