#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0664_StrangePrinter : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0664_StrangePrinter --> MainEntry" << std::endl;

        //输入: "aaabbb"
        //输出 : 2
        //解释 : 首先打印 "aaa" 然后打印 "bbb"。
        std::string inputString1 = "aaabbb";
        std::cout << "LC0664_StrangePrinter --> Result 2 : " << this->strangePrinter(inputString1) << std::endl;

        //输入 : "aba"
        //输出 : 2
        //解释 : 首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
        std::string inputString2 = "aba";
        std::cout << "LC0664_StrangePrinter --> Result 2 : " << this->strangePrinter(inputString2) << std::endl;

        return 0;
    }

public:
    int strangePrinter(std::string s)
    {
        if (s.empty()) return 0;

        int retValue = 0;
        size_t sLen = s.length();
        
        std::string noRepeatStr;
        noRepeatStr.append(1, s[0]);
        for (size_t i = 1; i < sLen; ++i)
        {
            if (s[i] != s[i - 1])
            {
                noRepeatStr.append(1, s[i]);
            }
        }

        return retValue;
    }
};
