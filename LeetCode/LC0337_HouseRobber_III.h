#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0337_HouseRobber_III : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0337_HouseRobber_III --> MainEntry" << std::endl;

        //示例 1:
        //输入: [3, 2, 3, null, 3, null, 1]
        //      3
        //     / \
        //    2   3
        //     \   \
        //      3   1
        //输出: 7
        //解释 : 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
        std::vector<int> root1Vec = { 3, 2, 3, INT_MIN, 3, INT_MIN, 1 };
        TreeNode *root1 = LeetCodeTreeNodeCreate(root1Vec);
        int result1 = 7;
        std::cout << "Expected Result: " << result1 << "    Real Result: " << this->Rob(root1) << std::endl;

        //示例 2 :
        //输入 : [3, 4, 5, 1, 3, null, 1]
        //         3
        //        / \
        //       4   5
        //      / \   \
        //     1   3   1
        //输出: 9
        //解释 : 小偷一晚能够盗取的最高金额  = 4 + 5 = 9.
        std::vector<int> root2Vec = { 3, 4, 5, 1, 3, INT_MIN, 1 };
        TreeNode *root2 = LeetCodeTreeNodeCreate(root1Vec);
        int result2 = 9;
        std::cout << "Expected Result: " << result2 << "    Real Result: " << this->Rob(root2) << std::endl;

        return 0;
    }

public:
    int Rob(TreeNode *root)
    {
        return 0;
    }
};
