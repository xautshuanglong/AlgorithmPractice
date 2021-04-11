#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0081_SearchRotateArray_II : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0081_SearchRotateArray_II --> MainEntry" << std::endl;

        // 输入：nums = [2, 5, 6, 0, 0, 1, 2], target = 0
        // 输出：true
        std::vector<int> nums1 = { 2, 5, 6, 0, 0, 1, 2 };
        int target1 = 0;

        // 输入：nums = [2, 5, 6, 0, 0, 1, 2], target = 3
        // 输出：false
        std::vector<int> nums2 = { 2, 5, 6, 0, 0, 1, 2 };
        int target2 = 3;

        std::cout << "LC0081_SearchRotateArray_II --> Result 1 : " << this->search(nums1, target1) << std::endl;
        std::cout << "LC0081_SearchRotateArray_II --> Result 2 : " << this->search(nums2, target2) << std::endl;
        return 0;
    }

public:
    bool search(std::vector<int> &nums, int target)
    {
        //return this->search1(nums, target);
        return this->search2(nums, target);
    }
    bool search1(std::vector<int> &nums, int target) {
        int numsLen = int(nums.size());
        for (int i = 0; i < numsLen; ++i)
        {
            if (nums[i] == target)
            {
                return true;
            }
        }

        return false;
    }

    bool search2(std::vector<int> &nums, int target) {
        int numsLen = int(nums.size());
        int index = 0;
        for (int i = 0; i < numsLen; ++i)
        {
            if (nums[index] == target)
            {
                return true;
            }
            else if (nums[index] < target)
            {
                if (index == numsLen - 1) return false;
                if (nums[index] > nums[index + 1]) return false;
                index = i + 1;
            }
            else if (nums[index] > target)
            {
                if (index > 0 && nums[index - 1] < target) return false;
                index = numsLen - 1 - i;
            }
        }

        return false;
    }
};
