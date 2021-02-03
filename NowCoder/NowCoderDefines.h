#pragma once

#include <windows.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL)
    {
    }
};

void NowCoderListNodeRelease(ListNode **ppHead)
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

void NowCoderListNodePrint(ListNode *pHead)
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
void NowCoderVectorPrint(std::vector<T> dataVec)
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
