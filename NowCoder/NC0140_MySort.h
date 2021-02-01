#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

class NC0140_MySort : public INowCoderEntry
{
public:
    int MainEntry() override
    {
        std::cout << "NC0140_MySort --> MainEntry" << std::endl;
        return 0;
    }

public:
    std::vector<int> MySort(std::vector<int> &arr)
    {
        // write code here
    }
};
