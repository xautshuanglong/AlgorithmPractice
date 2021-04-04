#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0070_ClimbStairs : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0070_ClimbStairs --> MainEntry" << std::endl;
        int nKind = this->ClimbStairs(44);
        std::cout << "LC0070_ClimbStairs --> Result: " << nKind << std::endl;
        return 0;
    }

public:
    int ClimbStairs(int nStep)
    {
        //return this->ClimbStairs_LessTime(nStep);
        return this->ClimbStairs_LessMemory(nStep);
    }

    int ClimbStairs_LessTime(int nStep)
    {
        int retValue = 0;

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
            retValue += ok;
        }
        else
        {
            nStepFlag[nStep] = 0;
        }

        return retValue;
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
* Á½Êý½»»»
* a       b
* a = a ^ b
* b = a ^ b
* a = a ^ b
*/
