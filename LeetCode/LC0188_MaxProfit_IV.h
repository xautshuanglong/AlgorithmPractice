#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0188_MaxProfit_IV : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0188_MaxProfit_IV --> MainEntry" << std::endl;

        // 输入 : [2,4,1], k = 2
        // 输出 : 2
        int k1 = 2;
        std::vector<int> priceList1 = { 2, 4, 1 };
        this->MaxProfit(k1, priceList1);

        // 输入 : [3,2,6,5,0,3], k = 2
        // 输出 : 7
        int k2 = 2;
        std::vector<int> priceList2 = { 3, 2, 6, 5, 0, 3 };
        this->MaxProfit(k2, priceList2);

        return 0;
    }

public:
    int MaxProfit(int k, std::vector<int>& prices)
    {
        return 0;
    }
};
