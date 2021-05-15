#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0394_DecodeString : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC0394_DecodeString --> MainEntry" << std::endl;

        //示例 1：
        //输入：s = "3[a]2[bc]"
        //输出："aaabcbc"
        std::string sample1 = "3[a]2[bc]";
        std::string result1 = "aaabcbc";
        std::cout << "Expected Result: " << result1 << "    Real Result: " << this->decodeString(sample1) << std::endl;

        //示例 2：
        //输入：s = "3[a2[c]]"
        //输出："accaccacc"
        std::string sample2 = "3[a2[c]]";
        std::string result2 = "accaccacc";
        std::cout << "Expected Result: " << result2 << "    Real Result: " << this->decodeString(sample2) << std::endl;
        
        //示例 3：
        //输入：s = "2[abc]3[cd]ef"
        //输出："abcabccdcdcdef"
        std::string sample3 = "2[abc]3[cd]ef";
        std::string result3 = "abcabccdcdcdef";
        std::cout << "Expected Result: " << result3 << "    Real Result: " << this->decodeString(sample3) << std::endl;

        //示例 4：
        //输入：s = "abc3[cd]xyz"
        //输出："abccdcdcdxyz"
        std::string sample4 = "abc3[cd]xyz";
        std::string result4 = "abccdcdcdxyz";
        std::cout << "Expected Result: " << result4 << "    Real Result: " << this->decodeString(sample4) << std::endl;

        //示例 5：
        //输入：s = "100[leetcode]"
        //输出："leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        std::string sample5 = "100[leetcode]";
        std::string result5 = "10 x leetcode";
        std::cout << "Expected Result: " << result5 << "    Real Result: " << this->decodeString(sample5) << std::endl;

        return 0;
    }

public:
    std::string decodeString(std::string inputStr)
    {
        std::string retValue;

        char tempChar = 0;
        std::stack<char> charStack;
        int strLen = (int)inputStr.length();

        for (int i = 0; i < strLen; ++i)
        {
            tempChar = inputStr[i];
            if (tempChar == ']') // 弹出需要重复的字符
            {
                tempChar = charStack.top();
                charStack.pop();
                std::vector<char> charVector;
                while (tempChar != '[')
                {
                    charVector.push_back(tempChar);
                    tempChar = charStack.top();
                    charStack.pop();
                }
                // 处理重复次数
                std::stack<char> numStack;
                tempChar = charStack.top();
                int copyCount = 0;
                while ('0' <= tempChar && tempChar <= '9')
                {
                    charStack.pop();
                    numStack.push(tempChar);
                    if (charStack.size())
                    {
                        tempChar = charStack.top();
                    }
                    else
                    {
                        break;
                    }
                }
                while (numStack.size())
                {
                    tempChar = numStack.top();
                    numStack.pop();
                    copyCount = copyCount * 10 + tempChar - '0';
                }
                while (copyCount > 0)
                {
                    std::vector<char>::reverse_iterator charIt = charVector.rbegin();
                    std::vector<char>::reverse_iterator charEnd = charVector.rend();
                    while (charIt != charEnd)
                    {
                        charStack.push(*charIt);
                        ++charIt;
                    }
                    --copyCount;
                }
            }
            else
            {
                charStack.push(tempChar);
            }
        }

        while (charStack.size())
        {
            tempChar = charStack.top();
            charStack.pop();
            retValue.insert(0, 1, tempChar);
        }

        return retValue;
    }
};
