#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0005_ZigzagConversion : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0005_ZigzagConversion --> MainEntry" << std::endl;

        //输入：s = "PAYPALISHIRING", numRows = 3
        //输出："PAHNAPLSIIGYIR"
        int numRows1 = 3;
        std::string input1 = "PAYPALISHIRING";
        std::cout << "output1 : " << this->convert(input1, numRows1) << std::endl;

        //输入：s = "PAYPALISHIRING", numRows = 4
        //输出："PINALSIGYAHRPI"
        //解释：
        //P     I    N
        //A   L S  I G
        //Y A   H R
        //P     I
        int numRows2 = 4;
        std::string input2 = "PAYPALISHIRING";
        std::cout << "output2 : " << this->convert(input2, numRows2) << std::endl;

        //输入：s = "A", numRows = 1
        //输出："A"
        int numRows3 = 1;
        std::string input3 = "A";
        std::cout << "output3 : " << this->convert(input3, numRows3) << std::endl;

        //输入：s = "AB", numRows = 1
        //输出："AB"
        int numRows4 = 1;
        std::string input4 = "AB";
        std::cout << "output3 : " << this->convert(input4, numRows4) << std::endl;

        return 0;
    }

public:
    std::string convert(std::string s, int numRows)
    {
        //return this->convert_1(s, numRows);
        return this->convert_2(s, numRows);
    }

    std::string convert_1(std::string s, int numRows)
    {
        std::string retValue;
        std::vector<std::string> vecString(numRows);
        int numRow = 0;
        bool directFlag = true; // true 正向； false 反向；

        for (char tempChar : s)
        {
            vecString[numRow].push_back(tempChar);
            if (directFlag)
            {
                if (numRow < numRows)
                {
                    ++numRow;
                }
                if (numRow >= numRows)
                {
                    numRow -= numRows > 1 ? 2 : 1;
                    directFlag = !directFlag;
                }
            }
            else
            {
                if (numRow >= 0)
                {
                    --numRow;
                }
                if (numRow < 0)
                {
                    numRow += numRows > 1 ? 2 : 1;
                    directFlag = !directFlag;
                }
            }
        }

        for (std::string tempSring : vecString)
        {
            retValue += tempSring;
        }

        return retValue;
    }


    //                    // 正向                                     反向
    //-----------------------------------------------------------------------------------------------------------------
    // 1 2 3 4 5 6 7 8 9  // step = 1 = 特例
    //-----------------------------------------------------------------------------------------------------------------
    // 1 3 5 7 9          // step = 2 = 2 * (numRows - 1 - 0)
    //  2 4 6 8
    //-----------------------------------------------------------------------------------------------------------------
    // 1   5   9          // step = 4 = 2 * (numRows - 1 - 0)         step = x
    //  2 4 6 8           // step = 2 = 2 * (numRows - 1 - 1)         step = 2 = 2 * ((numRows - 1) - (numRows - 1 - 1))
    //   3   7            // step = x                                 step = 4 = 2 * ((numRows - 1) - (numRows - 1 - 2))
    //-----------------------------------------------------------------------------------------------------------------
    // 1     7            // step = 6 = 2 * (numRows - 1)
    //  2   6 8
    //   3 5   9
    //    4
    //-----------------------------------------------------------------------------------------------------------------
    std::string convert_2(std::string s, int numRows)
    {
        if (numRows == 1) return s;

        std::string retValue;
        int strLen = (int)s.length();

        for (int row = 0; row < numRows; ++row)
        {
            for (int col = row; col < strLen; col += 2 * (numRows - 1) + 1);    
        }

        return retValue;
    }
};
