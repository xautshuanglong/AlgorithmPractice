#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0198_HouseRobber_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0198_HouseRobber_I --> MainEntry" << std::endl;

        //示例 1：
        //输入：[1, 2, 3, 1]
        //输出：4
        //解释：偷窃 1 号房屋(金额 = 1) ，然后偷窃 3 号房屋(金额 = 3)。
        //偷窃到的最高金额 = 1 + 3 = 4 。
        std::vector<int> nums1 = { 1, 2, 3, 1 };
        int result1 = 4;
        std::cout << "Expected Result: " << result1 << "    Real Result: " << this->Rob(nums1) << std::endl;

        //示例 2：
        //输入：[2, 7, 9, 3, 1]
        //输出：12
        //解释：偷窃 1 号房屋(金额 = 2), 偷窃 3 号房屋(金额 = 9)，接着偷窃 5 号房屋(金额 = 1)。
        //偷窃到的最高金额 = 2 + 9 + 1 = 12 。
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
