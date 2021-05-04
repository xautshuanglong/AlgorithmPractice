#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

class NC0000_Test_II : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
    {
        std::string inputStr;
        std::cin >> inputStr;

        std::cout << this->LongSubStrIncrease(inputStr);

        return 0;
    }

private:
    int LongSubStrIncrease(std::string inputStr)
    {
        int retValue = 0;
        if (inputStr.empty())
        {
            return 0;
        }

        int strLen = (int)inputStr.size();
        if (strLen > 255)
        {
            return 0;
        }

        char curChar = 0;
        char preChar = 0;
        int startIndex = 0;
        int endIndex = 0;
        bool presentFlag = false;
        if ('0' <= inputStr.at(0) && inputStr.at(0) <= '9')
        {
            presentFlag = true;
        }
        for (int i = 1; i < strLen; ++i)
        {
            preChar = inputStr.at(i - 1);
            curChar = inputStr.at(i);

            if ('0' <= curChar && curChar <= '9')
            {// 合法字符
                presentFlag = true;
                if (curChar>=preChar)
                {
                    endIndex = i;
                }
                else
                {
                    retValue = max(retValue, endIndex - startIndex + 1);
                    startIndex = i;
                    endIndex = i;
                }
            }
            else
            {// 非法字符
                if (presentFlag)
                {
                    retValue = max(retValue, endIndex - startIndex + 1);
                }
                ++i;
                startIndex = i;
                endIndex = i;
            }
        }
        if (presentFlag)
        {
            retValue = max(retValue, endIndex - startIndex + 1);
        }

        return retValue;
    }
};
