// NowCoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "NC0078_ReverseList.h"
#include "NC0093_LRU.h"
#include "NC0121_Permutation.h"
#include "NC0140_MySort.h"

int main(int argc, char** argv)
{
    //NC0078_ReverseList     instance;
    //NC0093_LRU             instance;
    //NC0140_MySort          instance;
    NC0121_Permutation     instance;

    INowCoderEntry *pNowCoderEntry = &instance;
    return pNowCoderEntry->MainEntry(argc, argv);
}





#include <iostream>
#include <cstdio>

using namespace std;

bool IsCharNum(char c)
{
    bool retValue = false;
    if ('0' <= c && c <= '9')
    {
        retValue = true;
    }
    return retValue;
}

int CharToNum(char c)
{
    return c - '0';
}

bool IsGoodChar(char c)
{
    bool retValue = false;
    if (c == '+' || c == '-')
    {
        retValue = true;
    }
    else if ('a' <= c && c <= 'z')
    {
        retValue = true;
    }
    else if ('A' <= c && c <= 'Z')
    {
        retValue = true;
    }
    else if ('0' <= c && c <= '9')
    {
        retValue = true;
    }
    return retValue;
}

bool IsQuackChar(char c)
{
    bool retValue = false;

    if (c=='q' || c == 'u' || c == 'a' || c == 'c' || c == 'k')
    {
        retValue = true;
    }

    return retValue;
}

int QuackCharIndex(char c)
{
    int retValue = 0;
    switch (c)
    {
    case 'q':
        retValue = 0;
        break;
    case 'u':
        retValue = 1;
        break;
    case 'a':
        retValue = 2;
        break;
    case 'c':
        retValue = 3;
        break;
    case 'k':
        retValue = 4;
        break;
    default:
        break;
    }
    return retValue;
}

int main3()
{
    int sum = 0;

    std::string inputString;
    cin >> inputString;
    inputString.append(";");
    size_t strLen = inputString.size();

    std::vector<std::string> textAarr;

    size_t foundIdx = 0;
    size_t startIdx = 0;
    do 
    {
        foundIdx = inputString.find(';', startIdx);
        if (foundIdx != std::string::npos)
        {
            textAarr.push_back(inputString.substr(startIdx, foundIdx - startIdx + 1));
        }
        else
        {
            textAarr.push_back(inputString.substr(startIdx, strLen - startIdx + 1));
        }
        startIdx = foundIdx + 1;
    } while (foundIdx != std::string::npos);

    for (size_t i = 0; i < textAarr.size(); ++i)
    {
        if (textAarr[i].length() == 0)
        {
            textAarr.erase(textAarr.begin() + i);
            --i;
        }
        else
        {
            while (textAarr[i].size())
            {
                if (textAarr[i][0] == ' ' || textAarr[i][0] == '\t')
                {
                    textAarr[i] = textAarr[i].substr(1, textAarr[i].size() - 1);
                }
                else
                {
                    break;
                }
            }
            if (textAarr.size() >=2 && textAarr[i][0]=='-' && textAarr[i][1]=='-')
            {
                size_t foundIdx = textAarr[i].find('\n');
                if (foundIdx != std::string::npos && textAarr[i][foundIdx-1]!=';')
                {
                    textAarr[i] = textAarr[i].substr(foundIdx+1, textAarr[i].size()- foundIdx-1);
                }
            }
            if (textAarr[i].length() == 0)
            {
                textAarr.erase(textAarr.begin() + i);
                --i;
            }
        }
    }

    std::cout << textAarr.size() << std::endl;

    return 0;
}

// 2
int main2()
{
    int sum = 0;

    std::string inputString;
    cin >> inputString;
    std::vector<std::vector<int>> quackIndex(5);

    int strLen = (int)inputString.size();
    if (strLen < 1 || strLen > 10000)
    {
        return -1;
    }

    for (int i = 0; i < strLen; ++i)
    {
        if (!IsQuackChar(inputString[i]))
        {
            return -1;
        }
    }

    const std::string quackStr = "quack";
    while (true)
    {
        size_t foundIdx = 0;
        for (size_t i = 0; i < quackStr.size(); ++i)
        {
            foundIdx = inputString.find(quackStr[i], foundIdx);
            if (foundIdx == std::string::npos)
            {
                goto RETURN_LABEL;
            }
            else
            {
                inputString[foundIdx] = 'N';
            }
        }
        ++sum;
    }

RETURN_LABEL:

    cout << sum << endl;

    return 0;
}

// 1
int main1()
{
    int sum = 0;
    std::string inputString;
    cin >> inputString;
    //cout << "input: " << inputString << std::endl;

    int strLen = (int)inputString.length();
    int tempNum = 0;
    int minusNum = 0;

    for (int i = 0; i < strLen; i++)
    {
        if (!IsGoodChar(inputString[i]))
        {
            cout << 0 << endl;
            return 0;
        }
        if (inputString[i] == '-')
        {
            minusNum = 0;
            do 
            {
                ++i;
                if (!IsGoodChar(inputString[i]))
                {
                    cout << 0 << endl;
                    return 0;
                }
                if (IsCharNum(inputString[i]))
                {
                    tempNum = CharToNum(inputString[i]);
                    minusNum = minusNum * 10 + tempNum;
                }
                else
                {
                    break;
                }
            } while (i < strLen);

            sum = sum - minusNum;
        }
        else if (IsCharNum(inputString[i]))
        {
            sum = sum + CharToNum(inputString[i]);
        }
    }
    cout << sum << endl;

    return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
