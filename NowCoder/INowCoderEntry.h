#pragma once

class INowCoderEntry
{
public:
    INowCoderEntry() {}
    virtual ~INowCoderEntry() {}

    virtual int MainEntry(int argc, char **argv) = 0;
};
