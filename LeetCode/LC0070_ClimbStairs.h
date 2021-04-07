#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0070_ClimbStairs : public ILeetCodeEntry
{
#define MOD 1000000007

public:
    int MainEntry() override
    {
        std::cout << "LC0070_ClimbStairs --> MainEntry" << std::endl;
        std::cout << "LC0070_ClimbStairs --> 5 : " << this->ClimbStairs(5) << std::endl;
        std::cout << "LC0070_ClimbStairs --> 44 : " << this->ClimbStairs(61) << std::endl;
        return 0;
    }

public:
    int ClimbStairs(int nStep)
    {
        //return this->ClimbStairs_LessTime(nStep);
        //return this->ClimbStairs_LessMemory(nStep);
        //return this->KidUpstairs_LessTime(nStep);
        return this->KidUpstairs_LessMemory(nStep);
    }

    int ClimbStairs_LessTime(int nStep)
    {
        if (nStepFlag.count(nStep))
        {
            return nStepFlag[nStep];
        }

        if (nStep == 0)
        {
            return 1;
        }
        else if (nStep < 0)
        {
            return 0;
        }

        int ok = ClimbStairs_LessTime(nStep - 1) + ClimbStairs_LessTime(nStep - 2);
        if (ok)
        {
            nStepFlag[nStep] = ok;
        }

        return ok;
    }

    int ClimbStairs_LessMemory(int nStep)
    {
        if (nStep == 1)
        {
            return 1;
        }
        else if (nStep == 2)
        {
            return 2;
        }

        int a = 1, b = 2;
        for (int i = 3; i <= nStep; ++i)
        {
            b = a + b;
            a = b - a;
        }

        return b;
    }

    int KidUpstairs_LessTime(int nStep)
    {
        if (nStepFlag.count(nStep))
        {
            return nStepFlag[nStep];
        }

        if (nStep == 1)
        {
            return 1;
        }
        if (nStep == 2)
        {
            return 2;
        }
        if (nStep == 3)
        {
            return 4;
        }

        // 三个值相加存在运行时越界
        //unsigned int ok = KidUpstairs_LessTime(nStep - 1) + KidUpstairs_LessTime(nStep - 2) + KidUpstairs_LessTime(nStep - 3);
        int ok = 0;
        ok += KidUpstairs_LessTime(nStep - 1);
        ok %= MOD;
        ok += KidUpstairs_LessTime(nStep - 2);
        ok %= MOD;
        ok += KidUpstairs_LessTime(nStep - 3);
        ok %= MOD;
        if (ok)
        {
            nStepFlag[nStep] = ok;
        }

        return nStepFlag[nStep];
    }

    int KidUpstairs_LessMemory(int nStep)
    {
        if (nStep == 1)
        {
            return 1;
        }
        else if (nStep == 2)
        {
            return 2;
        }
        else if (nStep == 3)
        {
            return 4;
        }

        int a = 1, b = 2, c = 4, d = 0;
        for (int i = 4; i <= nStep; ++i)
        {
            d = a + b;
            d %= MOD;
            d += c;
            d %= MOD;

            a = b;
            b = c;
            c = d;
        }

        return d;
    }

private:
    std::unordered_map<int, int> nStepFlag;
};

/*
* 0          0                       1
* 1          n(1-1)  +  n(1-2)       n(0) + n(-1) = 1
* 2          n(2-1)  +  n(2-2)       n(1) + n(0)  = 1 + 1 = 2
* 3          n(3-1)  +  n(3-2)       n(2) + n(1)  = 2 + 1 = 3
* 4          n(4-1)  +  n(4-2)       n(3) + n(2)  = 3 + 2 = 5
* ...        ...     +  ...
* x          n(x-1)  +  n(x-2)
*/

/*
* 两数交换
* a       b
* a = a ^ b
* b = a ^ b
* a = a ^ b
*/
