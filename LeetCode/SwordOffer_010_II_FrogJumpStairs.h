#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class SwordOffer_010_II_FrogJumpStairs : public ILeetCodeEntry
{
#define MOD 1000000007

public:
    int MainEntry() override
    {
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> MainEntry" << std::endl;
        int nWays = this->numWays(44);
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> 0: " << this->numWays(0) << std::endl;
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> 1: " << this->numWays(1) << std::endl;
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> 2: " << this->numWays(2) << std::endl;
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> 7: " << this->numWays(7) << std::endl;
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> 44: " << this->numWays(44) << std::endl;
        return 0;
    }

public:
    int numWays(int nStep)
    {
        return this->FrogJumpStairs_LessTime(nStep);
        //return this->FrogJumpStairs_LessMemory(nStep);
    }

    int FrogJumpStairs_LessTime(int nStep)
    {
        int retValue = 0;

        if (mapStepWays.count(nStep))
        {
            return mapStepWays[nStep];
        }

        if (nStep == 0)
        {
            return 1;
        }
        else if (nStep < 0)
        {
            return 0;
        }

        int ok = (FrogJumpStairs_LessTime(nStep - 1) + FrogJumpStairs_LessTime(nStep - 2)) % MOD;
        if (ok)
        {
            mapStepWays[nStep] = ok;
            retValue += ok;
        }
        else
        {
            mapStepWays[nStep] = 0;
        }

        return retValue;
    }

    int FrogJumpStairs_LessMemory(int nStep)
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
    std::unordered_map<int, int> mapStepWays;
};
