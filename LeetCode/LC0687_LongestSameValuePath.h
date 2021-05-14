#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"


/************************************************************************
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:
输入:
              5
             / \
            4   5
           / \   \
          1   1   5
输出:
2


示例 2:
输入:
              1
             / \
            4   5
           / \   \
          4   4   5
输出:
2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

************************************************************************/

class LC0687_LongestSameValuePath : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0687_LongestSameValuePath --> MainEntry" << std::endl;

        //输入 : [5,4,5,1,1,null,5]
        //输出 : 2
        std::vector<int> root1Vec = { 5, 4, 5, 1, 1, INT_MIN, 5 };
        TreeNode *root1 = LeetCodeTreeNodeCreate(root1Vec);
        std::cout << "LC0687_LongestSameValuePath --> Result 1 : " << this->LongestSameValuePath(root1) << std::endl;

        //输入 : [ 1, 4, 5, 4, 4, null, 5]
        //输出 : 2
        std::vector<int> root2Vec = { 1, 4, 5, 4, 4, INT_MIN, 5 };
        TreeNode *root2 = LeetCodeTreeNodeCreate(root2Vec);
        std::cout << "LC0687_LongestSameValuePath --> Result 2 : " << this->LongestSameValuePath(root2) << std::endl;

        // 输入 ： [5,4,5,4,4,5,3,4,4,null,null,null,4,null,null,4,null,null,4,null,4,4,null,null,4,4]
        // 输出 ： 6
        std::vector<int> root3Vec = { 5, 4, 5, 4, 4, 5, 3, 4, 4, INT_MIN, INT_MIN, INT_MIN, 4, INT_MIN, INT_MIN, 4, INT_MIN, INT_MIN, 4, INT_MIN, 4, 4, INT_MIN, INT_MIN, 4, 4 };
        TreeNode *root3 = LeetCodeTreeNodeCreate(root3Vec);
        std::cout << "LC0687_LongestSameValuePath --> Result 3 : " << this->LongestSameValuePath(root3) << std::endl;

        return 0;
    }

public:
    int LongestSameValuePath(TreeNode *root)
    {
        int retValue = 0;
        this->DFS(root, retValue);

        return retValue;
    }

private:
    int DFS(TreeNode *root, int &pathLenMax)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftMax = DFS(root->left, pathLenMax);
        int rightMax = DFS(root->right, pathLenMax);

        if (root->left != nullptr && root->left->val == root->val)
        {
            ++leftMax;
        }
        else
        {
            leftMax = 0;
        }
        if (root->right != nullptr && root->right->val == root->val)
        {
            ++rightMax;
        }
        else
        {
            rightMax = 0;
        }

        pathLenMax = max(pathLenMax, leftMax + rightMax);
        return max(leftMax, rightMax);
    }
};
