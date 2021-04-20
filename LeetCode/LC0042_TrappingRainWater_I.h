#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0042_TrappingRainWater_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0042_TrappingRainWater_I --> MainEntry" << std::endl;

        //输入：height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
        //输出：6
        //解释：上面是由数组[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
        std::vector<int> inputHeight1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        std::cout << "LC0042_TrappingRainWater_I --> Result 2 : " << this->trap(inputHeight1) << std::endl;

        //输入：height = [4, 2, 0, 3, 2, 5]
        //输出：9
        std::vector<int> inputHeight2 = { 4, 2, 0, 3, 2, 5 };
        std::cout << "LC0042_TrappingRainWater_I --> Result 2 : " << this->trap(inputHeight2) << std::endl;

        return 0;
    }

public:
    int trap(std::vector<int>& height)
    {
        int retValue = 0;

        return retValue;
    }
};
