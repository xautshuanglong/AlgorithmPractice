#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0033_SearchRotateArray_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0033_SearchRotateArray_I --> MainEntry" << std::endl;

        // 输入：nums = [4, 5, 6, 7, 0, 1, 2], target = 0
        // 输出：4
        std::vector<int> nums1 = { 4, 5, 6, 7, 0, 1, 2 };
        int target1 = 0;

        // 输入：nums = [4, 5, 6, 7, 0, 1, 2], target = 3
        // 输出： - 1
        std::vector<int> nums2 = { 4, 5, 6, 7, 0, 1, 2 };
        int target2 = 3;

        // 输入：nums = [1], target = 0
        // 输出： - 1
        std::vector<int> nums3 = { 1 };
        int target3 = 0;

        std::cout << "LC0033_SearchRotateArray_I --> Result 1 : " << this->search(nums1, target1) << std::endl;
        std::cout << "LC0033_SearchRotateArray_I --> Result 2 : " << this->search(nums2, target2) << std::endl;
        std::cout << "LC0033_SearchRotateArray_I --> Result 3 : " << this->search(nums3, target3) << std::endl;
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
