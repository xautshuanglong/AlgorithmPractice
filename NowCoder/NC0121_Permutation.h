#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/************************************************************************/
/* Least Recently Used  ×Ö·û´®ËùÓÐÅÅÁÐ¡£                                 */
/************************************************************************/
class NC0121_Permutation : public INowCoderEntry
{
public:
    int MainEntry() override
    {
        std::cout << "NC0121_Permutation --> MainEntry" << std::endl;

        std::string inputStr = "ab";
        std::vector<std::string> reuslt = this->Permutation(inputStr);
        NowCoderVectorPrint(reuslt);

        return 0;
    }

    std::vector<std::string> Permutation(std::string inputString)
    {
        std::vector<std::string> retValue;
        std::string outStr;

        size_t strLen = outStr.length();
        for (size_t i = 0; i < strLen; i++)
        {
            for (size_t j = 0; j < strLen; j++)
            {
                for (size_t k = 0; k < strLen; k++)
                {

                }
            }
        }
        std::swap(inputString[0], inputString[1]);
        return retValue;
    }
};
