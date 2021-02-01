#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/************************************************************************/
/* https://www.runoob.com/w3cnote/ten-sorting-algorithm.html            */
/************************************************************************/

class NC0140_MySort : public INowCoderEntry
{
public:
    int MainEntry() override
    {
        std::cout << "NC0140_MySort --> MainEntry" << std::endl;

        std::vector<int> intVector;
        //intVector.push_back(5);
        //intVector.push_back(2);
        //intVector.push_back(3);
        //intVector.push_back(1);
        //intVector.push_back(4);

        //for (int i = 100000; i>0; --i)
        //{
        //    intVector.push_back(i);
        //}

        for (int i = 0; i < 100000; ++i)
        {
            intVector.push_back(i);
        }

        //NowCoderVectorPrint(intVector);
        ULONGLONG startTick = GetTickCount64();
        std::cout << "----------------- BEGIN (" << startTick << ") -----------------" << std::endl;
        std::vector<int> resultVector = this->MySort_Bubble(intVector);
        //std::vector<int> resultVector = this->MySort_Selection(intVector);
        //std::vector<int> resultVector = this->MySort_Insertion(intVector);
        //std::vector<int> resultVector = this->MySort_Quick(intVector);
        //std::vector<int> resultVector = this->MySort_STL_Sort(intVector);
        ULONGLONG endTick = GetTickCount64();
        std::cout << "----------------- END (" << endTick << ") -----------------" << std::endl;
        std::cout << "Elapsed Time: " << endTick - startTick << " ms" << std::endl;
        NowCoderVectorPrint(resultVector);

        return 0;
    }

public:
    /************************************************************************/
    /* 冒泡排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Bubble(std::vector<int> &arr)
    {
        int temp = 0;
        bool switchFlag = false;
        size_t arrLen = arr.size();

        for (size_t i = 0; i < arrLen - 1; ++i)
        {
            switchFlag = false;
            for (size_t j = 0; j < arrLen - 1 - i; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    switchFlag = true;
                }
            }
            if (!switchFlag)
            {
                break;
            }
        }

        return arr;
    }

    /************************************************************************/
    /* 选择排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Selection(std::vector<int> &arr)
    {
        int temp = 0;
        bool switchFlag = false;
        size_t targetIdx = 0;
        size_t arrLen = arr.size();

        for (size_t i = 0; i < arrLen - 1; ++i)
        {
            switchFlag = false;
            temp = arr[i];
            for (size_t j = i + 1; j < arrLen; ++j)
            {
                if (temp > arr[j])
                {
                    temp = arr[j];
                    targetIdx = j;
                    switchFlag = true;
                }
            }
            if (switchFlag)
            {
                temp = arr[i];
                arr[i] = arr[targetIdx];
                arr[targetIdx] = temp;
            }
        }

        return arr;
    }

    /************************************************************************/
    /* 插入排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Insertion(std::vector<int> &arr)
    {
        std::sort(arr.begin(), arr.end());
        return arr;
    }

    /************************************************************************/
    /* 希尔排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Shell(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************/
    /* 归并排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Merge(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************/
    /* 快速排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Quick(std::vector<int> &arr)
    {
        this->QuickSortRecursive(arr, 0, arr.size() - 1);
        return arr;
    }

    /************************************************************************/
    /* 堆排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Heap(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************/
    /* 计数排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Counting(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************/
    /* 桶排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Bucket(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************/
    /* 基数排序                                                              */
    /************************************************************************/
    std::vector<int> MySort_Radix(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************/
    /* 根据具体情况分别调用适合的排序算法                                     */
    /*     如何判断哪种算法更合适                                            */
    /************************************************************************/
    std::vector<int> MySort_STL_Sort(std::vector<int> &arr)
    {
        //std::sort(arr.begin(), arr.end(), std::greater<int>());
        //std::sort(arr.begin(), arr.end(), std::greater_equal<int>());
        std::sort(arr.begin(), arr.end(), std::less<int>());
        //std::sort(arr.begin(), arr.end(), std::less_equal<int>());
        return arr;
    }

private:
    void QuickSortRecursive(std::vector<int> &arr, size_t left, size_t right)
    {
    }
};
