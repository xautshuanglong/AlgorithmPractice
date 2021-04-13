#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0123_MaxProfit_III : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0123_MaxProfit_III --> MainEntry" << std::endl;

        // ����: [3,3,5,0,0,3,1,4]
        // ���: 6
        //std::vector<int> priceList1 = { 3,3,5,0,0,3,1,4 };
        std::vector<int> priceList1 = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 };
        int maxProfit1 = this->MaxProfit(priceList1);

        // ����: [1,2,3,4,5]
        // ���: 4
        std::vector<int> priceList2 = { 1,2,3,4,5 };
        int maxProfit2 = this->MaxProfit(priceList2);

        // ����: [7, 6, 4, 3, 1]
        // ��� : 0
        std::vector<int> priceList3 = { 7, 6, 4, 3, 1 };
        int maxProfit3 = this->MaxProfit(priceList3);

        return 0;
    }

private:
    int MaxProfit(std::vector<int>& prices)
    {
        int firstBig = 0, secondBig = 0, tempBig = 0;
        size_t inputCount = prices.size();

        // ���
        std::vector<int> diffVector;
        for (int i = 0; i < inputCount - 1; ++i)
        {
            diffVector.push_back(prices[i + 1] - prices[i]);
        }
        // ͬ�źϲ�
        int multiple = 0;
        std::vector<int> unionVector;
        unionVector.push_back(diffVector[0]);
        size_t unionCount = 1;
        size_t diffCount = diffVector.size();
        for (size_t i = 1; i < diffCount; ++i)
        {
            multiple = unionVector[unionCount - 1] * diffVector[i];
            if (multiple < 0)
            {
                // �������
                unionVector.push_back(diffVector[i]);
                ++unionCount;
            }
            else
            {
                unionVector[unionCount - 1] = unionVector[unionCount - 1] + diffVector[i];
            }
        }
        // �ϲ��������
        int tempUnionThree = 0;
        for (size_t i = 0, j = 1; j < unionCount; ++j)
        {
            tempUnionThree = unionVector[j - 1] + unionVector[j] + unionVector[j + 1];
            if (unionVector[j] < 0 && tempUnionThree > unionVector[j - 1] && tempUnionThree > unionVector[j + 1])
            {
            }
        }

        return firstBig + secondBig;
    }
};
