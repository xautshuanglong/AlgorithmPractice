#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0042_TrappingRainWater_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0042_TrappingRainWater_I --> MainEntry" << std::endl;

        //���룺height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
        //�����6
        //���ͣ�������������[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����
        std::vector<int> inputHeight1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        std::cout << "LC0042_TrappingRainWater_I --> Result 2 : " << this->trap(inputHeight1) << std::endl;

        //���룺height = [4, 2, 0, 3, 2, 5]
        //�����9
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
