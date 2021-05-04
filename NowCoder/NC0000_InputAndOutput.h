#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

class NC0000_InputAndOutput : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
    {
        std::cout << "NC0000_InputAndOutput --> MainEntry" << std::endl;

        for (int i = 0; i < argc; ++i)
        {
            std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
        }

        //this->StudentInputTest(argc, argv);

        //std::string testMsg;
        //std::cin >> std::noskipws >> testMsg;
        //std::cin >> std::skipws >> testMsg;
        //std::cout << testMsg << std::endl;

        char tempBuffer[50] = { 0 };
        std::cin.getline(tempBuffer, 50);
        std::cout << tempBuffer << std::endl;
        std::cout << std::defaultfloat << 1.546 << std::endl;
        std::cout.unsetf(std::cout.flags());

        return 0;
    }

private:
    void StudentInputTest(int argc, char **argv)
    {
        //输入：3
        // liming,1410
        // zhangsan,1562
        // lisi,1355
        //输出：
        // zhangsan,1562
        // liming,1410
        // lisi,1355
        //对于上例，输入一般采用以下的方法

        struct StudentStruct
        {
            std::string name;
            std::string num;
        };

        StudentStruct *pStudent = nullptr;

        int N;//学生总数
        int Count = 0;
        while (std::cin >> N)
        {
            Count = N;
            pStudent = new StudentStruct[N];
            for (int i = 0; i < N; i++)
            {
                std::cin >> pStudent[i].name >> pStudent[i].num;//输入姓名和学号
            }
        }
        if (pStudent != nullptr)
        {
            std::cout << "N = " << Count << std::endl;
            for (int i = 0; i < Count; ++i)
            {
                std::cout << pStudent[i].name << ", " << pStudent[i].num << std::endl;
            }
        }

        if (pStudent != nullptr)
        {
            delete[] pStudent;
        }
    }
};
