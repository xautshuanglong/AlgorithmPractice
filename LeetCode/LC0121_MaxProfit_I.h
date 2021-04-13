#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0121_MaxProfit_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0121_MaxProfit_I --> MainEntry" << std::endl;

        // 输入: [7, 1, 5, 3, 6, 4]
        // 输出 : 5
        std::vector<int> priceList1 = { 7, 1, 5, 3, 6, 4 };
        int maxProfit1 = this->maxProfit(priceList1);

        // 输入: [7,6,4,3,1]
        // 输出: 0
        std::vector<int> priceList2 = { 7,6,4,3,1 };
        int maxProfit2 = this->maxProfit(priceList2);

        return 0;
    }

public:
    int maxProfit(std::vector<int> &prices)
    {
        int min = 0x7FFFFFFF;
        int retValue = 0;
        size_t dayCount = prices.size();
        if (dayCount > 0)
        {
            min = prices[0];
            for (size_t i = 1; i < dayCount; ++i)
            {
                if (prices[i] < min)
                {
                    min = prices[i];
                    ++i;
                }
                if (prices[i] - min > retValue)
                {
                    retValue = prices[i] - min;
                }
            }
        }
        return retValue;
    }
};
