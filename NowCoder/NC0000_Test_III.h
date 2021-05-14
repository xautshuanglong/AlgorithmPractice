#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

class NC0000_Test_III : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
    {
        std::vector<int> inputArr;
        int num;

        while (std::cin >> num)
        {
            if (num < 1 || num > 10000)
            {
                return 0;
            }
            inputArr.push_back(num);
        }

        std::cout << LowDiff(inputArr);
        return 0;
    }

private:
    int LowDiff(std::vector<int> &inputArr)
    {
        int retValue = INT_MAX;
        int diff = 0;
        int sumFirst = 0;
        int sumSecond = 0;

        std::vector<int> first;
        std::vector<int> second;

        for (size_t i = 0; i < inputArr.size() / 2; ++i)
        {
            first.push_back(inputArr[i]);
            sumFirst += inputArr[i];

            second.push_back(inputArr[i + 5]);
            sumSecond += inputArr[i + 5];
        }

        diff = sumSecond - sumFirst;
        if (diff < 0)
        {
            diff = diff * -1;
        }
        retValue = min(retValue, diff);

        for (int i = 0; i < inputArr.size() / 2; ++i)
        {
            for (int j = 0; j < inputArr.size() / 2; ++j)
            {
            }
        }

        return retValue;
    }
};
