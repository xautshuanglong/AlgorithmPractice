#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0198_HouseRobber_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0198_HouseRobber_I --> MainEntry" << std::endl;

        //ʾ�� 1��
        //���룺[1, 2, 3, 1]
        //�����4
        //���ͣ�͵�� 1 �ŷ���(��� = 1) ��Ȼ��͵�� 3 �ŷ���(��� = 3)��
        //͵�Ե�����߽�� = 1 + 3 = 4 ��
        std::vector<int> nums1 = { 1, 2, 3, 1 };
        int result1 = 4;
        std::cout << "Expected Result: " << result1 << "    Real Result: " << this->Rob(nums1) << std::endl;

        //ʾ�� 2��
        //���룺[2, 7, 9, 3, 1]
        //�����12
        //���ͣ�͵�� 1 �ŷ���(��� = 2), ͵�� 3 �ŷ���(��� = 9)������͵�� 5 �ŷ���(��� = 1)��
        //͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��
        std::vector<int> nums2 = { 2, 7, 9, 3, 1 };
        int result2 = 12;
        std::cout << "Expected Result: " << result2 << "    Real Result: " << this->Rob(nums2) << std::endl;

        return 0;
    }

public:
    int Rob(std::vector<int> &nums)
    {
        int numLen = (int)nums.size();
        if (numLen == 1)
        {
            return nums[0];
        }

        int temp = 0;
        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for (int i = 2; i < numLen; ++i)
        {
            temp = first;
            first = second;
            second = max(nums[i] + temp, second);
        }

        return second;
    }
};
