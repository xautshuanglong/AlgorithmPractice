#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0637_TreeLevelAverage : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0637_TreeLevelAverage --> MainEntry" << std::endl;
        // root = [3, 9, 20, null, null, 15, 7]
        // result = [3, 14.5, 11];
        std::vector<int> root1Vec = { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 };
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

        int count = 0;
        double layerAverage = 0;
        std::queue<TreeNode *> treeLayer;
        treeLayer.push(root);
        treeLayer.push(nullptr);

        while (!treeLayer.empty())
        {
            TreeNode *tempNode = treeLayer.front();
            treeLayer.pop();

            if (tempNode == nullptr) // 出现分层（本层结束）
            {
                retValue.push_back(layerAverage);
                count = 0;
                layerAverage = 0;
                if (!treeLayer.empty()) // 还有下层节点，增加分层标记
                {
                    treeLayer.push(nullptr);
                }
            }
            else
            {
                ++count;
                layerAverage += (tempNode->val - layerAverage) * 1.0 / count;
                if (tempNode->left)
                {
                    treeLayer.push(tempNode->left);
                }
                if (tempNode->right)
                {
                    treeLayer.push(tempNode->right);
                }
            }
        }

        return retValue;
    }
};
