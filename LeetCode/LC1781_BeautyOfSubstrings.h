#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC1781_BeautyOfSubstrings : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        std::cout << "LC1781_BeautyOfSubstrings --> MainEntry" << std::endl;

        //���룺s = "aabcb"
        //�����5
        //���ͣ�����ֵ��Ϊ����ַ�������["aab", "aabc", "aabcb", "abcb", "bcb"] ��ÿһ���ַ���������ֵ��Ϊ 1 ��
        std::string str1 = "aabcb";

        //���룺s = "aabcbaa"
        //�����17
        std::string str2 = "aabcbaa";

        //���룺s = "xzvfsppsjfbxdwkqe"
        //�����64
        std::string str3 = "xzvfsppsjfbxdwkqe";

        std::cout << "LC1781_BeautyOfSubstrings --> Result 1 : " << this->beautySum(str1) << std::endl;
        std::cout << "LC1781_BeautyOfSubstrings --> Result 2 : " << this->beautySum(str2) << std::endl;
        std::cout << "LC1781_BeautyOfSubstrings --> Result 3 : " << this->beautySum(str3) << std::endl;
        return 0;
    }

public:
    int beautySum(std::string s)
    {
        //return this->beautySum_LowMemory(s);
        return this->beautySum_LowTime(s);
    }

private:
    int beautySum_LowMemory(std::string s)
    {
        int retValue = 0;
        int slen = (int)s.length();
        if (slen <= 2) return retValue;

        int letterIndex = 0;
        // �Ӵ����ȴ� 2 �� slen
        for (int len = 3; len <= slen; ++len)
        {
            for (int i = 0; i < slen - len + 1; ++i)
            {
                int letterCount[26] = { 0 };
                int countMax = 0, countMin = INT_MAX;
                for (int j = i; j < i + len ; ++j)
                {
                    letterIndex = s[j] - 'a';
                    letterCount[letterIndex]++;
                }
                for (int j = 0; j < 26; ++j)
                {
                    if (letterCount[j] == 0) continue;
                    countMax = max(countMax, letterCount[j]);
                    countMin = min(countMin, letterCount[j]);
                }
                retValue += countMax - countMin;
            }
        }

        return retValue;
    }

    int beautySum_LowTime(std::string s)
    {
        int retValue = 0;
        int slen = (int)s.length();
        if (slen <= 2) return retValue;

        int letterIndex = 0;
        // �Ӵ����ȴ� 2 �� slen
        for (int len = 3; len <= slen; ++len)
        {
            for (int i = 0; i < slen - len + 1; ++i)
            {
                int letterCount[26] = { 0 };
                int countMax = 0, countMin = INT_MAX;
                for (int j = i; j < i + len; ++j)
                {
                    letterIndex = s[j] - 'a';
                    letterCount[letterIndex]++;
                }
                for (int j = 0; j < 26; ++j)
                {
                    if (letterCount[j] == 0) continue;
                    countMax = max(countMax, letterCount[j]);
                    countMin = min(countMin, letterCount[j]);
                }
                retValue += countMax - countMin;
            }
        }

        return retValue;
    }
};
