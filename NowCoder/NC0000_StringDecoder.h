#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

/*
 * �ַ������룺
 *     (abc)<20> ()�������ظ����ַ�����<>�������ظ��Ĵ�����������Ƕ�ף�
 *     ������Ϊ��abcabc
 *     �������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�
 *     ������ļ������Ƿ��ϸ�ʽҪ��ġ�
 * ʾ����
 * ���룺a(b(c)<3>d)<2>e   �����abcccdbcccde
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
            {// ��ջ
                tempChar = stringStack.top();
                stringStack.pop();
                // ����ƴ��
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
                {// ��ջ
                    // ���ظ��ַ���ƴ��
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

        // �ߵ�ջ
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
