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

        this->StudentInputTest(argc, argv);

        return 0;
    }

private:
    void StudentInputTest(int argc, char **argv)
    {
        ;
    }
};
