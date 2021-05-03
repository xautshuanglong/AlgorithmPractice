#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0213_HouseRobber_II : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0213_HouseRobber_II --> MainEntry" << std::endl;

        //示例 1：
        //输入：nums = [2, 3, 2]
        //输出：3
        //解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
        std::vector<int> nums1 = { 2, 3, 2 };
        int result1 = 3;
        std::cout << "Expected Result: " << result1 << "    Real Result: " << this->Rob(nums1) << std::endl;

        //示例 2：
        //输入：nums = [1, 2, 3, 1]
        //输出：4
        //解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
        //偷窃到的最高金额 = 1 + 3 = 4 。
        std::vector<int> nums2 = { 1, 2, 3, 1 };
        int result2 = 4;
        std::cout << "Expected Result: " << result2 << "    Real Result: " << this->Rob(nums2) << std::endl;

        //示例 3：
        //输入：nums = [0]
        //输出：0
        std::vector<int> nums3 = { 0 };
        int result3 = 0;
        std::cout << "Expected Result: " << result3 << "    Real Result: " << this->Rob(nums3) << std::endl;

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

        return max(this->HouseRobber_I(nums, 0, numLen-2), this->HouseRobber_I(nums, 1, numLen-1));
    }

private:
    int HouseRobber_I(std::vector<int> &nums, int start, int end)
    {
        int numLen = end - start + 1;
        if (numLen == 1)
        {
            return nums[start];
        }

        int temp = 0;
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i)
        {
            temp = first;
            first = second;
            second = max(nums[i] + temp, second);
        }

        return second;
    }
};
