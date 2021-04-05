#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class SwordOffer_010_II_FrogJumpStairs : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> MainEntry" << std::endl;
        int nWays = this->numWays(44);
        std::cout << "SwordOffer_010_II_FrogJumpStairs --> Result: " << nWays << std::endl;
        return 0;
    }

public:
    int numWays(int nStep)
    {
        return 0;
    }
};
