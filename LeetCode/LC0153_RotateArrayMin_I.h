#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0153_RotateArrayMin_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0153_RotateArrayMin_I --> MainEntry" << std::endl;

        // ���룺nums = [3, 4, 5, 1, 2]
        // �����1
        // ���ͣ�ԭ����Ϊ[1, 2, 3, 4, 5] ����ת 3 �εõ��������顣
        std::vector<int> input1 = { 3, 4, 5, 1, 2 };
        std::cout << "LC0153_RotateArrayMin_I --> Result 1 : " << this->findMin(input1) << std::endl;

        // ���룺nums = [4, 5, 6, 7, 0, 1, 2]
        // �����0
        // ���ͣ�ԭ����Ϊ[0, 1, 2, 4, 5, 6, 7] ����ת 4 �εõ��������顣
        std::vector<int> input2 = { 4, 5, 6, 7, 0, 1, 2 };
        std::cout << "LC0153_RotateArrayMin_I --> Result 2 : " << this->findMin(input2) << std::endl;

        // ���룺nums = [11, 13, 15, 17]
        // �����11
        // ���ͣ�ԭ����Ϊ[11, 13, 15, 17] ����ת 4 �εõ��������顣
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
