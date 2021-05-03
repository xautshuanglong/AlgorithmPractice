#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0337_HouseRobber_III : public ILeetCodeEntry
{
    struct SubtreeStatus
    {
        int selected;
        int notSelected;
    };

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
        TreeNode *root2 = LeetCodeTreeNodeCreate(root2Vec);
        int result2 = 9;
        std::cout << "Expected Result: " << result2 << "    Real Result: " << this->Rob(root2) << std::endl;

        // 输入： [2,3,null,1]
        // 输出： 3
        std::vector<int> root3Vec = { 2, 3, INT_MIN, 1 };
        TreeNode *root3 = LeetCodeTreeNodeCreate(root3Vec);
        int result3 = 3;
        std::cout << "Expected Result: " << result3 << "    Real Result: " << this->Rob(root3) << std::endl;

        return 0;
    }

public:
    int Rob(TreeNode *root)
    {
        //DFS(root);
        //int retValue = max(rootMapSelected[root], rootMapUnselected[root]);
        //return retValue;

        auto rootStatus = DFS_NoMap(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }

private:
    void DFS(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        DFS(root->left);
        DFS(root->right);
        rootMapSelected[root] = root->val + rootMapUnselected[root->left] + rootMapUnselected[root->right];
        rootMapUnselected[root] = max(rootMapSelected[root->left], rootMapUnselected[root->left]) + max(rootMapSelected[root->right], rootMapUnselected[root->right]);
    }

    SubtreeStatus DFS_NoMap(TreeNode *node)
    {
        if (node == nullptr)
        {
            return { 0, 0 };
        }
        auto l = DFS_NoMap(node->left);
        auto r = DFS_NoMap(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return { selected, notSelected };
    }

private:
    std::unordered_map<TreeNode *, int> rootMapSelected;
    std::unordered_map<TreeNode *, int> rootMapUnselected;
};
