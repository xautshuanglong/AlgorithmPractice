#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0005_LongestPalindromicSubstring : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0005_LongestPalindromicSubstring --> MainEntry" << std::endl;

        //输入：s = "babad"
        //输出："bab"
        //解释："aba" 同样是符合题意的答案。
        std::string input1 = "babad";
        std::string expect1 = "bab";
        std::cout << "expect1 : " << expect1 << std::endl;
        std::cout << "output1 : " << this->longestPalindrome(input1) << std::endl;

        //输入：s = "cbbd"
        //输出："bb"
        std::string input2 = "cbbd";
        std::string expect2 = "bb";
        std::cout << "expect2 : " << expect2 << std::endl;
        std::cout << "output2 : " << this->longestPalindrome(input2) << std::endl;

        //输入：s = "a"
        //输出："a"
        std::string input3 = "a";
        std::string expect3 = "a";
        std::cout << "expect3 : " << expect3 << std::endl;
        std::cout << "output3 : " << this->longestPalindrome(input3) << std::endl;

        //输入：s = "ac"
        //输出："a"
        std::string input4 = "ac";
        std::string expect4 = "a";
        std::cout << "expect4 : " << expect4 << std::endl;
        std::cout << "output4 : " << this->longestPalindrome(input4) << std::endl;

        return 0;
    }

public:
    std::string longestPalindrome(std::string s)
    {
        std::string retValue;
        return retValue;
    }
};
