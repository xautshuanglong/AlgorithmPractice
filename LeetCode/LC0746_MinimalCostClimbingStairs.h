#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0746_MinimalCostClimbingStairs : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0746_MinimalCostClimbingStairs --> MainEntry" << std::endl;

        std::vector<int> cost1 = { 10, 15, 20 };
        std::vector<int> cost2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };

        std::cout << "LC0746_MinimalCostClimbingStairs --> Result : " << this->MinCostClimbingStairs(cost1) << std::endl;
        std::cout << "LC0746_MinimalCostClimbingStairs --> Result : " << this->MinCostClimbingStairs(cost2) << std::endl;
        return 0;
    }

public:
    int MinCostClimbingStairs(std::vector<int> &cost)
    {
        return this->climbingStairs(cost);
    }

private:
    int climbingStairs(std::vector<int> &cost)
    {
        size_t vectorSize = cost.size();
        for (int i = 2; i < vectorSize; ++i)
        {
            cost[i] = min(cost[i - 1] + cost[i], cost[i - 2] + cost[i]);
        }

        return min(cost[vectorSize - 2], cost[vectorSize - 1]);

        //size_t vectorSize = cost.size();
        //std::vector<int> minCost(vectorSize);
        //minCost[0] = cost[0];
        //minCost[1] = cost[1];
        //for (int i = 2; i < vectorSize; ++i)
        //{
        //    minCost[i] = min(minCost[i - 1] + cost[i], minCost[i - 2] + cost[i]);
        //}
        //return min(minCost[vectorSize - 2], minCost[vectorSize - 1]);
    }
};
