#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0113_TreePathSum_II : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0113_TreePathSum_II --> MainEntry" << std::endl;
        // 输入：root = [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1], targetSum = 22
        // 输出： [[5, 4, 11, 2], [5, 8, 4, 5]]
        int targetSum1 = 22;
        TreeNode *root1 = nullptr;
        this->pathSum(root1, targetSum1);
        std::cout << "LC0113_TreePathSum_II --> Result 1 : "<< std::endl;
        // VectorPrint

        // 输入：root = [1, 2, 3], targetSum = 5
        // 输出：[]
        int targetSum2 = 5;
        TreeNode *root2 = nullptr;

        // 输入：root = [1, 2], targetSum = 0
        // 输出：[]
        int targetSum3 = 0;
        TreeNode *root3 = nullptr;
        return 0;
    }

public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        return std::vector<std::vector<int>>();
    }
};
