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
        std::vector<int> root1Vec = { 5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, 5, 1 };
        TreeNode *root1 = LeetCodeTreeNodeCreate(root1Vec);
        std::vector<std::vector<int>> result1 = this->pathSum(root1, targetSum1);
        std::cout << "LC0113_TreePathSum_II --> Result 1 : "<< std::endl;
        // VectorPrint

        // 输入：root = [1, 2, 3], targetSum = 5
        // 输出：[]
        int targetSum2 = 5;
        std::vector<int> root2Vec = { 1, 2, 3 };
        TreeNode *root2 = LeetCodeTreeNodeCreate(root2Vec);
        std::vector<std::vector<int>> result2 = this->pathSum(root2, targetSum2);

        // 输入：root = [1, 2], targetSum = 0
        // 输出：[]
        int targetSum3 = 0;
        std::vector<int> root3Vec = { 1,2 };
        TreeNode *root3 = LeetCodeTreeNodeCreate(root3Vec);
        std::vector<std::vector<int>> result3 = this->pathSum(root3, targetSum3);

        return 0;
    }

public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        std::vector<std::vector<int>> goodPaths;
        std::vector<int> path;
        this->traversalDFS(root, targetSum, 0, goodPaths, path);
        return goodPaths;
    }

    void traversalDFS(TreeNode *root, int targetSum, int curSum, std::vector<std::vector<int>>&goodPaths, std::vector<int> &path)
    {
        if (root == nullptr)
        {
            return;
        }
        curSum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && curSum == targetSum)
        {
            goodPaths.push_back(path);
        }

        traversalDFS(root->left, targetSum, curSum, goodPaths, path);
        traversalDFS(root->right, targetSum, curSum, goodPaths, path);
        path.pop_back();
    }
};
