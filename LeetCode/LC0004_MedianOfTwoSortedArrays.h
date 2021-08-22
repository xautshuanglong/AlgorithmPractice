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
        //return this->findMedianSortedArrays_1(nums1, nums2);
        return this->findMedianSortedArrays_2(nums1, nums2);
    }

    /*
    * 合并两个数组后重新排序，计算出中位数。
    */
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

    /*
    * 模拟合并操作（只需合并一半）
    * 按大小顺序访问到两数组和的一半
    */
    double findMedianSortedArrays_2(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        double retValue = 0.0;

        size_t nums1Len = nums1.size();
        size_t nums2Len = nums2.size();
        size_t totalLen = nums1Len + nums2Len;

        size_t halfLen = totalLen / 2; // 长度的一半，下标需减 1
        size_t visitedCount = 0;

        int nums1Index = 0;
        int nums2Index = 0;
        int curNum = 0;
        int tempNum1 = INT_MAX;
        int tempNum2 = INT_MAX;

        while (visitedCount < halfLen)
        {
            if (nums1Index < nums1Len)
            {
                tempNum1 = nums1[nums1Index];
            }
            else
            {
                tempNum1 = INT_MAX;
            }
            if (nums2Index < nums2Len)
            {
                tempNum2 = nums2[nums2Index];
            }
            else
            {
                tempNum2 = INT_MAX;
            }
            if (tempNum1 <= tempNum2)
            {
                ++nums1Index;
                curNum = tempNum1;
            }
            else
            {
                ++nums2Index;
                curNum = tempNum2;
            }
            ++visitedCount;
        }

        if (nums1Index < nums1Len)
        {
            tempNum1 = nums1[nums1Index];
        }
        else
        {
            tempNum1 = INT_MAX;
        }
        if (nums2Index < nums2Len)
        {
            tempNum2 = nums2[nums2Index];
        }
        else
        {
            tempNum2 = INT_MAX;
        }
        int nextNum = min(tempNum1, tempNum2);
        if (totalLen % 2 == 0)
        {
            retValue = (curNum + nextNum) / 2.0;
        }
        else
        {
            retValue = nextNum;
        }

        return retValue;
    }

    double findMedianSortedArrays_3(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays_3(nums2, nums1);
        }

        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right)
        {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j)
            {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
