#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0437_TreePathSum_III : public ILeetCodeEntry
{
#define MOD 1000000007

public:
    int MainEntry() override
    {
        std::cout << "LC0437_TreePathSum_III --> MainEntry" << std::endl;
        // root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], sum = 8
        int sum = 8;
        TreeNode *root = nullptr;
        std::cout << "LC0437_TreePathSum_III --> Result : " << this->pathSum(root, sum) << std::endl;
        return 0;
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        return 0;
    }
};
