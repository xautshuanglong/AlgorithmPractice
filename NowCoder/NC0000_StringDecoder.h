#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/*
 * 字符串解码：
 *     (abc)<20> ()里面是重复的字符串，<>里面是重复的次数，可以有嵌套，
 *     解码结果为：abcabc
 *     你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，
 *     且输入的尖括号是符合格式要求的。
 * 示例：
 * 输入：a(b(c)<3>d)<2>e   输出：abcccdbcccde
 *
 */

class NC0000_StringDecoder : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
    {
        std::string str1 = "(abc)<2>";
        this->PrintDecodedString(str1);
        std::cout << std::endl;

        std::string str2 = "a(b(c)<3>d)<2>e";
        this->PrintDecodedString(str2);
        std::cout << std::endl;

        return 0;
    }

private:
    void PrintDecodedString(std::string &inputStr)
    {
        char tempChar = 0;
        int sLen = (int)inputStr.length();
        int num = 0;
        std::stack<char> stringStack;
        std::string tempString;
        for (int i = 0; i < sLen; ++i)
        {
            tempChar = inputStr[i];
            if (tempChar == '>')
            {// 出栈
                tempChar = stringStack.top();
                stringStack.pop();
                // 数字拼接
                num = 0;
                while (tempChar != '<')
                {
                    num = num * 10 + (tempChar - '0');
                    tempChar = stringStack.top();
                    stringStack.pop();
                }
                tempChar = stringStack.top();
                stringStack.pop();
                if (tempChar == ')')
                {// 出栈
                    // 待重复字符串拼接
                    tempChar = stringStack.top();
                    stringStack.pop();
                    std::vector<char> tempCharQue;
                    while (tempChar != '(')
                    {
                        tempCharQue.push_back(tempChar);
                        tempChar = stringStack.top();
                        stringStack.pop();
                    }
                    for (int i = 0; i < num; ++i)
                    {
                        for (int i = tempCharQue.size() - 1; i >= 0; --i)
                        {
                            tempChar = tempCharQue[i];
                            stringStack.push(tempChar);
                        }
                    }
                }
            }
            else
            {
                stringStack.push(tempChar);
            }
        }

        // 颠倒栈
        std::stack<char> output;
        while (stringStack.size())
        {
            output.push(stringStack.top());
            stringStack.pop();
        }
        while (output.size())
        {
            std::cout << output.top();
            output.pop();
        }
    }
};
