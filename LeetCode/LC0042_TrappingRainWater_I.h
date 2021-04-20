#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0042_TrappingRainWater_I : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0042_TrappingRainWater_I --> MainEntry" << std::endl;

        //输入：height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
        //输出：6
        //解释：上面是由数组[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
        std::vector<int> inputHeight1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        std::cout << "LC0042_TrappingRainWater_I --> Result 2 : " << this->trap(inputHeight1) << std::endl;

        //输入：height = [4, 2, 0, 3, 2, 5]
        //输出：9
        std::vector<int> inputHeight2 = { 4, 2, 0, 3, 2, 5 };
        std::cout << "LC0042_TrappingRainWater_I --> Result 2 : " << this->trap(inputHeight2) << std::endl;

        return 0;
    }

public:
    int trap(std::vector<int>& height)
    {
        //return this->ScanOneByeOne(height);
        //return this->ScanLeftMaxRightMax(height);
        return this->ScanIntoStack(height);
    }

    int ScanOneByeOne(std::vector<int>& height)
    {
        int retValue = 0;
        size_t heightLen = height.size();
        std::vector<int> heightMax(heightLen);

        if (heightLen < 3) return retValue;

        for (size_t i = 1; i < heightLen - 1; ++i)
        {
            int maxL = height[i];
            for (size_t l = 0; l < i; ++l)
            {
                if (height[l] > maxL)
                {
                    maxL = height[l];
                }
            }
            int maxR = height[i];
            for (size_t r = i+1; r < heightLen; ++r)
            {
                if (height[r] > maxR)
                {
                    maxR = height[r];
                }
            }
            heightMax[i] = min(maxL, maxR);
        }

        for (int i = 1; i < heightLen - 1; ++i)
        {
            retValue += heightMax[i] - height[i];
        }

        return retValue;
    }

    int ScanLeftMaxRightMax(std::vector<int>& height)
    {
        int retValue = 0;
        size_t heightSize = height.size();
        if (heightSize < 3) return retValue;

        std::vector<int> leftMax(heightSize);
        std::vector<int> rightMax(heightSize);
        leftMax[0] = height[0];
        rightMax[heightSize - 1] = height[heightSize - 1];

        // 每个桶的左侧最大值
        for (size_t i = 1; i < heightSize; ++i)
        {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        for (size_t i = heightSize - 2; i != ULLONG_MAX; --i)
        {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        for (size_t i = 1; i < heightSize - 1; ++i)
        {
            retValue += min(rightMax[i], leftMax[i]) - height[i];
        }

        return retValue;
    }

    int ScanIntoStack(std::vector<int>& height)
    {
        int retValue = 0;
        int heightSize = (int)height.size();

        int leftMaxTemp = 0;
        int oldTop = 0;
        int curHeight = 0;
        int curWidth = 0;
        std::stack<int> indexStack;

        for (int i = 0; i < heightSize; ++i)
        {
            while (!indexStack.empty() && height[i] > height[indexStack.top()])
            {
                oldTop = indexStack.top();
                indexStack.pop();
                if (indexStack.empty())
                {
                    break;
                }
                leftMaxTemp = indexStack.top();
                curHeight = min(height[i], height[leftMaxTemp]) - height[oldTop];
                curWidth = i - leftMaxTemp - 1;
                retValue += curHeight * curWidth;
            }
            indexStack.push(i);
        }

        return retValue;
    }

    int ScanDoublePointer(std::vector<int>& height)
    {
        int retValue = 0;

        int heightSize = (int)height.size();
        int left = 0;
        int leftMax = 0;
        int right = heightSize - 1;
        int rightMax = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > leftMax)
                {
                    leftMax = height[left];
                } 
                else
                {
                    retValue += leftMax - height[left];
                }
                left++;
            } 
            else
            {
                if (height[right] > rightMax)
                {
                    rightMax = height[right];
                } 
                else
                {
                    retValue += rightMax - height[right];
                }
                right--;
            }
        }

        return retValue;
    }
};
