#pragma once

#include <windows.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *LeetCodeTreeNodeCreate(std::vector<int> &treeValues)
{
    TreeNode *root = nullptr;
    TreeNode *pTempNode = nullptr;
    int treeValueCount = int(treeValues.size());
    if (treeValueCount == 0 || treeValues[0] == INT_MIN)
    {
        return root;
    }

    int tempNodeIndex = 0, valueIndex = 0;
    root = new TreeNode(treeValues[0]);
    std::queue <TreeNode*> broadTreeNode;
    broadTreeNode.push(root);

    do 
    {
        pTempNode = broadTreeNode.front();
        broadTreeNode.pop();
        if (pTempNode != nullptr)
        {
            valueIndex = 2 * tempNodeIndex + 1;
            if (valueIndex < treeValueCount && treeValues[valueIndex] != INT_MIN)
            {
                pTempNode->left = new TreeNode(treeValues[valueIndex]);
            }
            ++valueIndex;
            if (valueIndex < treeValueCount && treeValues[valueIndex] != INT_MIN)
            {
                pTempNode->right = new TreeNode(treeValues[valueIndex]);
            }
            broadTreeNode.push(pTempNode->left);
            broadTreeNode.push(pTempNode->right);
            ++tempNodeIndex;
        }
    } while (!broadTreeNode.empty() && 2 * tempNodeIndex + 1 < treeValueCount);

    return root;
}

void LeetCodeTreeNodeDestory(TreeNode **root)
{
    if (root == nullptr) return;
    TreeNode *tempNode = *root;
    if (tempNode == nullptr) return;

    std::stack<TreeNode *> broadTreeNode;
    broadTreeNode.push(tempNode);

    while (!broadTreeNode.empty())
    {
        tempNode = broadTreeNode.top();
        if (tempNode->left == nullptr && tempNode->right == nullptr)
        {
            broadTreeNode.pop();
        }
        if (tempNode->left != nullptr)
        {
            if (tempNode->left->left == nullptr && tempNode->left->right == nullptr)
            {
                delete tempNode->left;
                tempNode->left = nullptr;
            }
            else
            {
                broadTreeNode.push(tempNode->left);
            }
        }
        if (tempNode->right != nullptr)
        {
            if (tempNode->right->left == nullptr && tempNode->right->right == nullptr)
            {
                delete tempNode->right;
                tempNode->right = nullptr;
            }
            else
            {
                broadTreeNode.push(tempNode->right);
            }
        }
    }

    delete *root;
    *root = nullptr;
}
 
void LeetCodeListNodeRelease(ListNode **ppHead)
{
    if (ppHead == NULL) return;

    ListNode *pNodeCurrent = *ppHead;
    ListNode *pNodeNext = NULL;
    while (pNodeCurrent != NULL)
    {
        pNodeNext = pNodeCurrent->next;
        delete pNodeCurrent;
        pNodeCurrent = pNodeNext;
    }

    *ppHead = NULL;
}

void LeetCodeListNodePrint(ListNode *pHead)
{
    ListNode *pTemp = pHead;
    std::cout << "{ ";

    while (pTemp != NULL)
    {
        if (pTemp != pHead)
        {
            std::cout << ", ";
        }
        std::cout << pTemp->val;
        pTemp = pTemp->next;
    }

    std::cout << " }";
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& outStream, std::vector<int> intVector)
{
    std::stringstream outString;
    outString << "[ ";
    auto begin = intVector.begin();
    auto end = intVector.end();

    auto iter = begin;
    while (iter != end)
    {
        if (iter != begin)
        {
            outString << ", ";
        }
        outString << *iter;
        ++iter;
    }
    outString << " ]";

    outStream << outString.str();
    return outStream;
}

template <class T>
void LeetCodeVectorPrint(std::vector<T> dataVec)
{
    std::cout << "[ ";

    auto begin = dataVec.begin();
    auto end = dataVec.end();

    auto iter = begin;
    while (iter != end)
    {
        if (iter != begin)
        {
            std::cout << ", ";
        }
        std::cout << *iter;
        ++iter;
    }

    std::cout << " ]";
    std::cout << std::endl;
}

template <class T>
void LeetCodeVectorPrint(std::vector<std::vector<T>> dataVec)
{
    typename std::vector<std::vector<T>>::iterator begin = dataVec.begin();
    typename std::vector<std::vector<T>>::iterator end = dataVec.end();
    typename std::vector<std::vector<T>>::iterator iter = begin;

    typename std::vector<T>::iterator childBegin;
    typename std::vector<T>::iterator childEnd;
    typename std::vector<T>::iterator childIter;

    std::cout << "[ ";

    while (iter != end)
    {
        if (iter != begin)
        {
            std::cout << ", ";
        }

        childBegin = iter->begin();
        childEnd = iter->end();
        childIter = childBegin;
        std::cout << "[ ";
        while (childIter != childEnd)
        {
            if (childIter != childBegin)
            {
                std::cout << ", ";
            }
            std::cout << *childIter;
            ++childIter;
        }
        std::cout << " ]";
        ++iter;
    }

    std::cout << " ]";
    std::cout << std::endl;
}
