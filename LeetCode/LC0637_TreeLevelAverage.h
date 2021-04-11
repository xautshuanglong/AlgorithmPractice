#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0637_TreeLevelAverage : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0637_TreeLevelAverage --> MainEntry" << std::endl;
        // root = [10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1], sum = 8
        int sum1 = 8;
        std::vector<int> root1Vec = { 10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1 };
        TreeNode *root1 = LeetCodeTreeNodeCreate(root1Vec);
        std::vector<double> result1 = this->averageOfLevels(root1);
        std::cout << "LC0637_TreeLevelAverage --> Result 1 : " << std::endl;
        LeetCodeVectorPrint(result1);

        return 0;
    }

public:
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::vector<double> retValue;

        return retValue;
    }
};
