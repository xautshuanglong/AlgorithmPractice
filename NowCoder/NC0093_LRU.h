#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/************************************************************************/
/* Least Recently Used  最近最少使用算法                                 */
/************************************************************************/
class NC0093_LRU : public INowCoderEntry
{
public:
    struct DListNode
    {
        int key, val;
        DListNode *pre;
        DListNode *next;
        DListNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {};
    };

    int MainEntry() override
    {
        std::cout << "NC93_LRU --> MainEntry" << std::endl;

        // [[1,1,1],[1,2,2],[1,3,2],[2,1],[1,4,4],[2,2]],3
        int k = 3;
        std::vector<std::vector<int>> intVVector;
        intVVector.push_back({ 1, 1, 1 });
        intVVector.push_back({ 1, 2, 2 });
        intVVector.push_back({ 1, 3, 2 });
        intVVector.push_back({ 2, 1 });
        intVVector.push_back({ 1, 4, 4 });
        intVVector.push_back({ 2, 2 });

        NowCoderVectorPrint(intVVector);
        std::vector<int> retValue = this->LRU(intVVector, k);
        NowCoderVectorPrint(retValue);

        return 0;
    }

    std::vector<int> LRU(std::vector<std::vector<int> > &operators, int k)
    {
        std::unordered_map<int, int> cacheMap;
        std::list<int> recentList; // 索引越小越不常用
        std::vector<int> retValue;

        std::vector<std::vector<int>>::iterator iter = operators.begin();
        std::vector<std::vector<int>>::iterator end = operators.end();
        int operate = 1;
        int key = 0, value = 0;
        while (iter != end)
        {
            operate = iter->at(0);
            key = iter->at(1);

            if (operate == 1) // set
            {
                value = iter->at(2);
                cacheMap[key] = value;

                recentList.remove(key);
                recentList.push_back(key);

                if (cacheMap.size() > size_t(k))
                {
                    std::list<int>::const_iterator itBegin = recentList.begin();
                    cacheMap.erase(*itBegin);
                    recentList.erase(itBegin);
                }
            } 
            else if (operate == 2) // get
            {
                if (cacheMap.find(key) == cacheMap.end())
                {
                    retValue.push_back(-1);
                } 
                else
                {
                    recentList.remove(key);
                    recentList.push_back(key);
                    retValue.push_back(cacheMap[key]);
                }
            }

            ++iter;
        }

        return retValue;
    }
};
