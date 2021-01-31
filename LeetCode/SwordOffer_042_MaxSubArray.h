#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class SwordOffer_042_MaxSubArray : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "SwordOffer_042_MaxSubArray --> MainEntry" << std::endl;

        return 0;
    }

public:
    int MaxSubArray(std::vector<int> &nums)
    {
        int maxSum = 0;
        int numLen = int(nums.size());

        if (numLen > 0)
        {
            int newLen = 0;
            for (int i = 1; i < numLen; ++i)
            {
                if (nums[newLen] * nums[i - 1] < 0)
                {
                    ++newLen;
                    nums[newLen] = nums[i];
                }
                else
                {
                    nums[newLen] += nums[i];
                }
            }
            maxSum = nums[0];
            int index = 0;
            if (maxSum < 0 && newLen > 1)
            {
                maxSum = nums[1];
                ++index;
            }
            int tempNum = 0, tempMax = maxSum;
            for (int i = index + 1; i < newLen; i += 2)
            {
                tempNum = nums[i] * -1;
                if (i + 1 < newLen && tempNum < maxSum && tempNum < nums[i = 1])
                {
                    tempMax += nums[i];
                    tempMax += nums[i + 1];
                }
                else
                {
                    tempMax = nums[i + 1];
                }

            }
        }

        return maxSum;
    }
};
