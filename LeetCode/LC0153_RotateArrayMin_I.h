#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0153_RotateArrayMin_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0153_RotateArrayMin_I --> MainEntry" << std::endl;

        // 输入：nums = [3, 4, 5, 1, 2]
        // 输出：1
        // 解释：原数组为[1, 2, 3, 4, 5] ，旋转 3 次得到输入数组。
        std::vector<int> input1 = { 3, 4, 5, 1, 2 };
        std::cout << "LC0153_RotateArrayMin_I --> Result 1 : " << this->findMin(input1) << std::endl;

        // 输入：nums = [4, 5, 6, 7, 0, 1, 2]
        // 输出：0
        // 解释：原数组为[0, 1, 2, 4, 5, 6, 7] ，旋转 4 次得到输入数组。
        std::vector<int> input2 = { 4, 5, 6, 7, 0, 1, 2 };
        std::cout << "LC0153_RotateArrayMin_I --> Result 2 : " << this->findMin(input2) << std::endl;

        // 输入：nums = [11, 13, 15, 17]
        // 输出：11
        // 解释：原数组为[11, 13, 15, 17] ，旋转 4 次得到输入数组。
        std::vector<int> input3 = { 11, 13, 15, 17 };
        std::cout << "LC0153_RotateArrayMin_I --> Result 3 : " << this->findMin(input3) << std::endl;

        return 0;
    }

public:
    int findMin(std::vector<int> &nums)
    {
        return 0;
    }
};
