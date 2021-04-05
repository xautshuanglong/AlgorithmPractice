#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

/*
 * 主要考点：斐波那契，数据类型溢出，先取模后加与先加后取模等同。
 */

class SwordOffer_010_I_Fibonacci : public ILeetCodeEntry
{
#define MOD 1000000007

public:
    int MainEntry() override
    {
        std::cout << "SwordOffer_042_Fibonacci --> MainEntry" << std::endl;
        
        std::cout << "SwordOffer_042_Fibonacci --> Fibonacci(2): " << this->Fibonacci(2) << std::endl;
        std::cout << "SwordOffer_042_Fibonacci --> Fibonacci(5): " << this->Fibonacci(5) << std::endl;
        std::cout << "SwordOffer_042_Fibonacci --> Fibonacci(48): " << this->Fibonacci(95) << std::endl;

        return 0;
    }

public:
    int Fibonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }

        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; ++i)
        {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }

        return c;
    }
};
