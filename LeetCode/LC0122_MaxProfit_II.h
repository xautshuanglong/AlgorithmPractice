#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0122_MaxProfit_II : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0122_MaxProfit_II --> MainEntry" << std::endl;

        // 输入: [7, 1, 5, 3, 6, 4]
        // 输出 : 7
        std::vector<int> priceList1 = { 7, 1, 5, 3, 6, 4 };
        int maxProfit1 = this->MaxProfit(priceList1);

        // 输入: [1, 2, 3, 4, 5]
        // 输出 : 4
        std::vector<int> priceList2 = { 1, 2, 3, 4, 5 };
        int maxProfit2 = this->MaxProfit(priceList2);

        // 输入: [7, 6, 4, 3, 1]
        // 输出 : 0
        std::vector<int> priceList3 = { 7, 6, 4, 3, 1 };
        int maxProfit3 = this->MaxProfit(priceList3);

        return 0;
    }

private:
    int MaxProfit(std::vector<int>& prices)
    {
        int retValue = 0;
        size_t inputCount = prices.size();
        for (size_t i = 0; i < inputCount - 1; ++i)
        {
            prices[i] = prices[i + 1] - prices[i];
            if (prices[i] > 0)
            {
                retValue += prices[i];
            }
        }
        return retValue;
    }
};
