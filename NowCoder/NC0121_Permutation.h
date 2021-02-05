#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/************************************************************************/
/* Least Recently Used  ×Ö·û´®ËùÓÐÅÅÁÐ¡£                                 */
/************************************************************************/
class NC0121_Permutation : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
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

class Solution
{
public:
    std::vector<std::string> Permutation(std::string str)
    {
        std::vector<std::string> res;
        if (str.size() == 0) return res;
        permutations(str, 0, (int)str.size(), res);
        return res;
    }

    void permutations(std::string str, int index, int len, std::vector<std::string> &res)
    {
        if (index == len - 1)
        {
            res.push_back(str);
            return;
        }
        for (int i = index; i < len; i++)
        {
            if (i != index && str[i] == str[index])
                continue;
            std::swap(str[i], str[index]);
            permutations(str, index + 1, (int)str.size(), res);
        }
    }
};
