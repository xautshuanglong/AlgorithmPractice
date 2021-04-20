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

        std::vector<std::vector<int>> memo = std::vector<std::vector<int>>(sLen, std::vector<int>(sLen, INT_MAX));
        retValue = longTime(s, int(sLen), memo);
        //retValue = this->dp(s, memo, 0, sLen - 1);

        return retValue;
    }

    int longTime(std::string &s, int sLen, std::vector<std::vector<int>> &memo)
    {
        for (int i = 0; i < sLen; i++)
        {
            memo[i][i] = 1;
        }
        for (int len = 1; len < sLen; len++)
        {
            for (int i = 0; i + len < sLen; i++)
            {
                memo[i][i + len] = len + 1;
                for (int k = i; k < (i + len); k++)
                {
                    int total = memo[i][k] + memo[k + 1][i + len];
                    if (s[k] == s[i + len])
                    {
                        total--;
                    }
                    memo[i][i + len] = min(total, memo[i][i + len]);
                }

            }
        }
        return memo[0][sLen - 1];
    }

    int dp(std::string &s, std::vector<std::vector<int>> &memo, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        if (memo[i][j] == INT_MAX)
        {
            int tempAns = dp(s, memo, i + 1, j) + 1;
            for (int k = i + 1; k <= j; ++k)
            {
                if (s[k] == s[i])
                {
                    tempAns = min(tempAns, dp(s, memo, i, k - 1) + dp(s, memo, k + 1, j));
                }
            }
            memo[i][j] = tempAns;
        }
        return memo[i][j];
    }
};
