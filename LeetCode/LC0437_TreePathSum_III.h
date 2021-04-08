#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0437_TreePathSum_III : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0437_TreePathSum_III --> MainEntry" << std::endl;
        // root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], sum = 8
        int sum1 = 8;
        std::vector<int> root1Vec = { 10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1 };
        TreeNode *root1 = LeetCodeTreeNodeCreate(root1Vec);
        std::cout << "LC0437_TreePathSum_III --> Result : " << this->pathSum(root1, sum1) << std::endl;
        return 0;
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        int result = 0;
        std::queue<int> path;
        this->traversalDFS(root, sum, result, path);
        return result;
    }

    void traversalDFS(TreeNode *root, int sum, int &result, std::queue<int> &path)
    {
    }
};
