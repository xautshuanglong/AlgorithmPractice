#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0407_TrappingRainWater_II : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0407_TrappingRainWater_II --> MainEntry" << std::endl;
        
        //给出如下 3x6 的高度图 :
        //[
        //    [1, 4, 3, 1, 3, 2],
        //    [3, 2, 1, 3, 2, 4],
        //    [2, 3, 3, 2, 3, 1]
        //]
        //返回 4 。
        std::vector<std::vector<int>> inputHeight1 =
        {
            {1, 4, 3, 1, 3, 2},
            {3, 2, 1, 3, 2, 4},
            {2, 3, 3, 2, 3, 1}
        };
        std::cout << "LC0407_TrappingRainWater_II --> Result 2 : " << this->trapRainWater(inputHeight1) << std::endl;

        std::vector<std::vector<int>> inputHeight2 = {};
        std::cout << "LC0407_TrappingRainWater_II --> Result 2 : " << this->trapRainWater(inputHeight2) << std::endl;

        return 0;
    }

public:
    int trapRainWater(std::vector<std::vector<int>>& height)
    {
        int retValue = 0;

        size_t rowSize = height.size();
        if (rowSize < 3) return 0;
        size_t colSize = height[0].size();
        if (colSize < 3) return 0;

        int layer = 0;
        bool hasMoreLayer = true;
        do
        {
            for (size_t row = 0; row < rowSize; ++row)
            {
                for (size_t col = 0; col < colSize; ++col)
                {
                    ;
                }
            }
        } while (hasMoreLayer);

        return retValue;
    }
};
