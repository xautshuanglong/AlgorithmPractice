#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0004_MedianOfTwoSortedArrays : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0004_MedianOfTwoSortedArrays --> MainEntry" << std::endl;

        //���룺nums1 = [1, 3], nums2 = [2]
        //�����2.00000
        //���ͣ��ϲ����� = [1, 2, 3] ����λ�� 2
        std::vector<int> inputVec1_1 = { 1, 3 };
        std::vector<int> inputVec1_2 = { 2 };
        std::cout << "result-1 : " << this->findMedianSortedArrays(inputVec1_1, inputVec1_2) << std::endl;

        //���룺nums1 = [1, 2], nums2 = [3, 4]
        //�����2.50000
        //���ͣ��ϲ����� = [1, 2, 3, 4] ����λ��(2 + 3) / 2 = 2.5
        std::vector<int> inputVec2_1 = { 1, 2 };
        std::vector<int> inputVec2_2 = { 3, 4 };
        std::cout << "result-2 : " << this->findMedianSortedArrays(inputVec2_1, inputVec2_2) << std::endl;

        //���룺nums1 = [0, 0], nums2 = [0, 0]
        //�����0.00000
        std::vector<int> inputVec3_1 = { 0, 0 };
        std::vector<int> inputVec3_2 = { 0, 0 };
        std::cout << "result-3 : " << this->findMedianSortedArrays(inputVec3_1, inputVec3_2) << std::endl;

        //���룺nums1 = [], nums2 = [1]
        //�����1.00000
        std::vector<int> inputVec4_1 = { };
        std::vector<int> inputVec4_2 = { 1 };
        std::cout << "result-4 : " << this->findMedianSortedArrays(inputVec4_1, inputVec4_2) << std::endl;

        //���룺nums1 = [2], nums2 = []
        //�����2.00000
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
    * �ϲ�����������������򣬼������λ����
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
    * ģ��ϲ�������ֻ��ϲ�һ�룩
    * ����С˳����ʵ�������͵�һ��
    */
    double findMedianSortedArrays_2(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        double retValue = 0.0;

        size_t nums1Len = nums1.size();
        size_t nums2Len = nums2.size();
        size_t totalLen = nums1Len + nums2Len;

        size_t halfLen = totalLen / 2; // ���ȵ�һ�룬�±���� 1
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
        // median1��ǰһ���ֵ����ֵ
        // median2����һ���ֵ���Сֵ
        int median1 = 0, median2 = 0;

        while (left <= right)
        {
            // ǰһ���ְ��� nums1[0 .. i-1] �� nums2[0 .. j-1]
            // ��һ���ְ��� nums1[i .. m-1] �� nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j �ֱ��ʾ nums1[i-1], nums1[i], nums2[j-1], nums2[j]
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
