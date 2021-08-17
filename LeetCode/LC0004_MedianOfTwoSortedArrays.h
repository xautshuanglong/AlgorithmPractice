#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0004_MedianOfTwoSortedArrays : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0004_MedianOfTwoSortedArrays --> MainEntry" << std::endl;

        //输入：nums1 = [1, 3], nums2 = [2]
        //输出：2.00000
        //解释：合并数组 = [1, 2, 3] ，中位数 2
        std::vector<int> inputVec1_1 = { 1, 3 };
        std::vector<int> inputVec1_2 = { 2 };
        std::cout << "result-1 : " << this->findMedianSortedArrays(inputVec1_1, inputVec1_2) << std::endl;

        //输入：nums1 = [1, 2], nums2 = [3, 4]
        //输出：2.50000
        //解释：合并数组 = [1, 2, 3, 4] ，中位数(2 + 3) / 2 = 2.5
        std::vector<int> inputVec2_1 = { 1, 2 };
        std::vector<int> inputVec2_2 = { 3, 4 };
        std::cout << "result-2 : " << this->findMedianSortedArrays(inputVec2_1, inputVec2_2) << std::endl;

        //输入：nums1 = [0, 0], nums2 = [0, 0]
        //输出：0.00000
        std::vector<int> inputVec3_1 = { 0, 0 };
        std::vector<int> inputVec3_2 = { 0, 0 };
        std::cout << "result-3 : " << this->findMedianSortedArrays(inputVec3_1, inputVec3_2) << std::endl;

        //输入：nums1 = [], nums2 = [1]
        //输出：1.00000
        std::vector<int> inputVec4_1 = { };
        std::vector<int> inputVec4_2 = { 1 };
        std::cout << "result-4 : " << this->findMedianSortedArrays(inputVec4_1, inputVec4_2) << std::endl;

        //输入：nums1 = [2], nums2 = []
        //输出：2.00000
        std::vector<int> inputVec5_1 = { 2 };
        std::vector<int> inputVec5_2 = { };
        std::cout << "result-5 : " << this->findMedianSortedArrays(inputVec5_1, inputVec5_2) << std::endl;

        return 0;
    }

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        return this->findMedianSortedArrays_1(nums1, nums2);
    }

    double findMedianSortedArrays_1(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        double retValue = 0.0;

        std::vector<int> merge(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merge.begin());
        std::sort(merge.begin(), merge.end());

        size_t mergeSize = merge.size();
        if (mergeSize == 0) return 0.0;

        if (mergeSize % 2 == 0)
        {
            size_t index = mergeSize / 2;
            retValue = merge[index - 1] - (merge[index - 1] - merge[index]) / 2.0;
        }
        else
        {
            size_t index = mergeSize / 2;
            retValue = merge[index];
        }

        return retValue;
    }

    double findMedianSortedArrays_2(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        double retValue = 0.0;
        return retValue;
    }
};
