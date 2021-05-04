#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

class NC0000_Test_I : public INowCoderEntry
{
public:
    int MainEntry(int argc, char **argv) override
    {
        std::vector<int> inputVec;
        std::string arrStr;
        int weightMax = 0;

        std::cin >> arrStr;
        std::cin >> weightMax;

        //std::cout << arrStr << std::endl;
        //std::cout << arrCount << std::endl;

        int strLen = (int)arrStr.size();
        int findOffset = 0;
        size_t findIndex = std::string::npos;
        do 
        {
            findIndex = arrStr.find(',', findOffset);
            std::string numStr = arrStr.substr(findOffset, findIndex - findOffset);
            int num = atoi(numStr.c_str());
            inputVec.push_back(num);
            findOffset = (int)findIndex + 1;
        } while (findIndex != std::string::npos);

        std::cout << MaxCount(inputVec, weightMax);
        return 0;
    }

private:
    int MaxCount(std::vector<int> &inputVec, int weightMax)
    {
        int count = 0;
        int weightSum = 0;

        std::sort(inputVec.begin(), inputVec.end());

        for (int num : inputVec)
        {
            if (weightSum + num <= weightMax)
            {
                weightSum += num;
                ++count;
            }
            else
            {
                break;
            }
            //std::cout << num << std::endl;
        }

        return count;
    }
};


//#include <iostream>
//using namespace std;
//int main() {
//    int a, b;
//    while (cin >> a >> b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//        cout << a + b << endl;
//}