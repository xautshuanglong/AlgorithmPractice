#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/************************************************************************
 * 参考网址：https://www.runoob.com/w3cnote/ten-sorting-algorithm.html            
 * 参考网址：https://www.cnblogs.com/onepixel/p/7674659.html
 ************************************************************************/

class NC0140_MySort : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
    {
        std::cout << "NC0140_MySort --> MainEntry" << std::endl;

        std::vector<int> intVector;
        intVector.push_back(5);
        intVector.push_back(2);
        intVector.push_back(3);
        intVector.push_back(1);
        intVector.push_back(4);

        //std::vector<int> intVector;
        //intVector.push_back(5);
        //intVector.push_back(4);
        //intVector.push_back(3);
        //intVector.push_back(2);
        //intVector.push_back(1);

        //const int size = 100000;
        //std::vector<int> intVector(size);
        //for (int i = 0; i<size; ++i)
        //{
        //    intVector[i] = size - i;
        //}

        //for (int i = 0; i < 100000; ++i)
        //{
        //    intVector.push_back(i);
        //}

        //NowCoderVectorPrint(intVector);
        ULONGLONG startTick = GetTickCount64();
        std::cout << "----------------- BEGIN (" << startTick << ") -----------------" << std::endl;
        //std::vector<int> resultVector = this->MySort_Bubble(intVector);
        //std::vector<int> resultVector = this->MySort_Selection(intVector);
        //std::vector<int> resultVector = this->MySort_Insertion(intVector);
        //std::vector<int> resultVector = this->MySort_Shell(intVector);
        //std::vector<int> resultVector = this->MySort_Merge(intVector);
        std::vector<int> resultVector = this->MySort_Quick(intVector);
        //std::vector<int> resultVector = this->MySort_Heap(intVector);
        //std::vector<int> resultVector = this->MySort_Counting(intVector);
        //std::vector<int> resultVector = this->MySort_Bucket(intVector);
        //std::vector<int> resultVector = this->MySort_Radix(intVector);
        //std::vector<int> resultVector = this->MySort_STL_Sort(intVector);
        ULONGLONG endTick = GetTickCount64();
        std::cout << "----------------- END (" << endTick << ") -----------------" << std::endl;
        std::cout << "Elapsed Time: " << endTick - startTick << " ms" << std::endl;
        NowCoderVectorPrint(resultVector);

        return 0;
    }

public:
    /************************************************************************/
    /* 冒泡排序                                                             */
    /*  1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个；               */
    /*  2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，         */
    /*     这样在最后的元素应该会是最大的数；                                 */
    /*  3. 针对所有的元素重复以上的步骤，除了最后一个；                        */
    /*  4. 重复步骤1~3，直到排序完成。                                        */
    /************************************************************************/
    /* 冒泡排序
     * 冒泡排序是一种简单的排序算法。
     * 它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。
     * 走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
     * 这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。 
     * 
     *  1. 比较相邻的两个数据，如果第二个数小，就交换位置。
     *  2. 从后向前两两比较，一直到比较最前两个数据。
     *     最终最小数被交换到起始的位置，这样第一个最小数的位置就排好了。
     *  3. 继续重复上述过程，依次将第2.3...n-1个最小数排好位置。
     ************************************************************************/
    std::vector<int> MySort_Bubble(std::vector<int> &arr)
    {
        size_t arrLen = arr.size();
        if (arrLen < 2)
        {
            return arr;
        }

        int temp = 0;
        bool switchFlag = false;

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

    /************************************************************************************
     * 选择排序
     * 选择排序(Selection-sort)是一种简单直观的排序算法。
     * 它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
     * 然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
     * 
     *  n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。
     *  具体算法描述如下：
     *  1. 初始状态：无序区为R[1..n]，有序区为空；
     *  2. 第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。
     *     该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，
     *     使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
     *  3. n-1趟结束，数组有序化了。
     ***********************************************************************************/
    std::vector<int> MySort_Selection(std::vector<int> &arr)
    {
        size_t arrLen = arr.size();
        if (arrLen < 2)
        {
            return arr;
        }

        int temp = 0;
        bool switchFlag = false;
        size_t targetIdx = 0;

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

    /************************************************************************
     *  插入排序
     *  插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。
     *  它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
     * 
     *  一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
     *  1. 从第一个元素开始，该元素可以认为已经被排序；
     *  2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
     *  3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
     *  4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
     *  5. 将新元素插入到该位置后；
     *  6. 重复步骤2~5。
     ************************************************************************/
    std::vector<int> MySort_Insertion(std::vector<int> &arr)
    {
        size_t arrLen = arr.size();
        if (arrLen < 2)
        {
            return arr;
        }
        int temp = 0;
        // TODO: 在已经有序的数组中插入数据，考虑使用二分法插入。
        for (size_t i = 1; i < arrLen; ++i)
        {
            temp = arr[i];

            size_t j = 0;
            for (j = i - 1; j >= 0 && j != size_t(-1); --j)
            {
                if (temp < arr[j])
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j + 1] = temp;
        }

        return arr;
    }

    /*****************************************************************************************************
     * 希尔排序
     * 1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
     * 它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
     * 
     * 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：
     *  1. 选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
     *  2. 按增量序列个数k，对序列进行k 趟排序；
     *  3. 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。
     *     仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
     *****************************************************************************************************/
    std::vector<int> MySort_Shell(std::vector<int> &arr)
    {
        size_t arrLen = arr.size();
        size_t stepSize = arrLen;
        int temp = 0;

        do
        {
            stepSize = stepSize / 2;
            for (size_t i = stepSize; i < arrLen; i += stepSize)
            {
                temp = arr[i];
                size_t j = 0;
                for (j = i - stepSize; j >= 0 && j != 0-stepSize; j -= stepSize)
                {
                    if (temp < arr[j])
                    {
                        arr[j + stepSize] = arr[j];
                    }
                    else
                    {
                        break;
                    }
                }
                arr[j + stepSize] = temp;
            }
        } while (stepSize >= 2);

        return arr;
    }

    /*********************************************************************************************************
     * 归并排序
     * 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
     * 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。 
     *  1. 把长度为n的输入序列分成两个长度为n/2的子序列；
     *  2. 对这两个子序列分别采用归并排序；
     *  3. 将两个排序好的子序列合并成一个最终的排序序列。
     *********************************************************************************************************/
    std::vector<int> MySort_Merge(std::vector<int> &arr)
    {
        int arrLen = (int)arr.size();

        //递归版本
        //this->Recursive_Merge(arr, 0, arrLen - 1);
        //非递归版本

        std::vector<int> copyVector(arrLen, 0);

        std::vector<int> *pInputVector = &arr;
        std::vector<int> *pMergedVector = &copyVector;
        std::vector<int> *pTempVector = NULL;

        for (int segmentSize = 1; segmentSize < arrLen; segmentSize += segmentSize)
        {
            for (int segmentIdx = 0; segmentIdx < arrLen; segmentIdx += segmentSize + segmentSize)
            {
                // 操作 pMergedVector 在输入数组和备份数组间切换
                int startIndex1 = segmentIdx;
                int startIndex2 = segmentIdx + segmentSize;

                int endIndex1 = std::min<int>(segmentIdx + segmentSize, arrLen);
                int endIndex2 = std::min<int>(segmentIdx + segmentSize + segmentSize, arrLen);

                int mergedIndex = segmentIdx;
                while (startIndex1 < endIndex1 && startIndex2 < endIndex2)
                {
                    if (pInputVector->at(startIndex1) < pInputVector->at(startIndex2))
                    {
                        pMergedVector->at(mergedIndex) = pInputVector->at(startIndex1);
                        ++startIndex1;
                    }
                    else
                    {
                        pMergedVector->at(mergedIndex) = pInputVector->at(startIndex2);
                        ++startIndex2;
                    }
                    ++mergedIndex;
                }
                while (startIndex1 < endIndex1)
                {
                    pMergedVector->at(mergedIndex) = pInputVector->at(startIndex1);
                    ++startIndex1;
                    ++mergedIndex;
                }
                while (startIndex2 < endIndex2)
                {
                    pMergedVector->at(mergedIndex) = pInputVector->at(startIndex2);
                    ++startIndex2;
                    ++mergedIndex;
                }
            }

            pTempVector = pInputVector;
            pInputVector = pMergedVector;
            pMergedVector = pTempVector;
        }

        if (pInputVector != &arr)
        {
            arr = *pInputVector;
        }

        return arr;
    }

    /**********************************************************************************************************
     * 快速排序
     * 快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，
     * 则可分别对这两部分记录继续进行排序，以达到整个序列有序。
     * 
     *  快速排序使用分治法来把一个串（list）分为两个子串（sub - lists）。具体算法描述如下：
     *  1. 从数列中挑出一个元素，称为 “基准”（pivot）；
     *  2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
     *     在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
     *  3. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
     **********************************************************************************************************/
    std::vector<int> MySort_Quick(std::vector<int> &arr)
    {
        //Runoob 菜鸟教程
        this->Runoob_QuickSort(arr, 0, (int)arr.size() - 1);
        //递归版本
        //this->Recursive_Quick(arr, 0, (int)arr.size() - 1);
        //非递归版本
        return arr;
    }

    /******************************************************************************************************************************
     * 堆排序
     * 堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
     * 堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
     * 1. 将初始待排序关键字序列(R1，R2，···，Rn)构建成大顶堆，此堆为初始的无序区；
     * 2. 将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1，R2，···，Rn-1)和新的有序区(Rn),且满足R[1，2，···，n-1]<=R[n]；
     * 3. 由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1，R2，···，Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，
     *    得到新的无序区(R1，R2，···，Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
     ******************************************************************************************************************************/
    std::vector<int> MySort_Heap(std::vector<int> &arr)
    {
        return arr;
    }

    /*******************************************************************************
     * 计数排序
     * 计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
     * 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
     * 1. 找出待排序的数组中最大和最小的元素；
     * 2. 统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
     * 3. 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
     * 4. 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
     *******************************************************************************/
    std::vector<int> MySort_Counting(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************
     * 桶排序
     * 桶排序是计数排序的升级版。
     * 它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
     * 桶排序(Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，
     * 每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
     * 
     * 1. 设置一个定量的数组当作空桶；
     * 2. 遍历输入数据，并且把数据一个一个放到对应的桶里去；
     * 3. 对每个不是空的桶进行排序；
     * 4. 从不是空的桶里把排好序的数据拼接起来。
     ************************************************************************/
    std::vector<int> MySort_Bucket(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************
     * 基数排序
     * 基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。
     * 有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
     * 最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。
     * 
     * 1. 取得数组中的最大数，并取得位数；
     * 2. arr为原始数组，从最低位开始取每个位组成radix数组；
     * 3. 对radix进行计数排序（利用计数排序适用于小范围数的特点）；
     ************************************************************************/
    std::vector<int> MySort_Radix(std::vector<int> &arr)
    {
        return arr;
    }

    /************************************************************************
     * 根据具体情况分别调用适合的排序算法
     *     如何判断哪种算法更合适
     ************************************************************************/
    std::vector<int> MySort_STL_Sort(std::vector<int> &arr)
    {
        //std::sort(arr.begin(), arr.end(), std::greater<int>());
        //std::sort(arr.begin(), arr.end(), std::greater_equal<int>());
        std::sort(arr.begin(), arr.end(), std::less<int>());
        //std::sort(arr.begin(), arr.end(), std::less_equal<int>());
        return arr;
    }

private:
    void Recursive_Merge(std::vector<int> &inputVector, int startIdx, int endIdx)
    {
        if (startIdx >= endIdx)
        {
            return;
        }

        int midIndex = (startIdx + endIdx) / 2;
        Recursive_Merge(inputVector, startIdx, midIndex);   // 处理左侧分组
        Recursive_Merge(inputVector, midIndex + 1, endIdx); // 处理右侧分组

        std::vector<int> inputLeft(inputVector.begin() + startIdx, inputVector.begin() + midIndex + 1);
        std::vector<int> inputRight(inputVector.begin() + midIndex + 1, inputVector.begin() + endIdx + 1);

        // 合并
        int indexLeft = 0;
        int indexRight = 0;
        int inputCountLeft = (int)inputLeft.size();
        int inputCountRight = (int)inputRight.size();
        for (int i = startIdx; i <= endIdx; ++i)
        {
            if (indexLeft >= inputCountLeft)
            {
                inputVector[i] = inputRight[indexRight];
                ++indexRight;
            }
            else if (indexRight >= inputCountRight)
            {
                inputVector[i] = inputLeft[indexLeft];
                ++indexLeft;
            }
            else if (inputLeft[indexLeft] < inputRight[indexRight])
            {
                inputVector[i] = inputLeft[indexLeft];
                ++indexLeft;
            }
            else
            {
                inputVector[i] = inputRight[indexRight];
                ++indexRight;
            }
        }
    }

    void Recursive_Quick(std::vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            // 分区
            int baseValue = arr[left];
            int baseIndex = left;
            int partIndex = 0;
            int temp = 0;
            int lesserIndex = left + 1;

            for (int i = lesserIndex; i <= right; ++i)
            {
                if (arr[i] < baseValue)
                {
                    temp = arr[lesserIndex];
                    arr[lesserIndex] = arr[i];
                    arr[i] = temp;
                    ++lesserIndex;
                }
            }

            arr[baseIndex] = arr[lesserIndex - 1];
            arr[lesserIndex - 1] = baseValue;
            partIndex = lesserIndex - 1;

            // 递归处理子分区
            Recursive_Quick(arr, left, partIndex - 1);
            Recursive_Quick(arr, partIndex + 1, right);
        }
    }

    int Runoob_Paritition(std::vector<int> &A, int low, int high)
    {
        int pivot = A[low];
        while (low < high)
        {
            while (low < high && A[high] >= pivot)
            {
                --high;
            }
            A[low] = A[high];
            while (low < high && A[low] <= pivot)
            {
                ++low;
            }
            A[high] = A[low];
        }
        A[low] = pivot;
        return low;
    }

    void Runoob_QuickSort(std::vector<int> &A, int low, int high)
    {
        if (low < high)
        {
            int pivot = Runoob_Paritition(A, low, high);
            Runoob_QuickSort(A, low, pivot - 1);
            Runoob_QuickSort(A, pivot + 1, high);
        }
    }
};
