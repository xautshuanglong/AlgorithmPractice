#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0154_RotateArrayMin_II : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        //输入：nums = [1, 3, 5]
        //输出：1
        std::vector<int> input1 = { 1, 3, 5 };
        std::cout << "LC0154_RotateArrayMin_II --> Result 1 : " << this->findMin(input1) << std::endl;

        //输入：nums = [2, 2, 2, 0, 1]
        //输出：0
        std::vector<int> input2 = { 2, 2, 2, 0, 1 };
        std::cout << "LC0154_RotateArrayMin_II --> Result 2 : " << this->findMin(input2) << std::endl;

        return 0;
    }

public:
    int findMin(std::vector<int> &nums)
    {
        return 0;
    }
};
