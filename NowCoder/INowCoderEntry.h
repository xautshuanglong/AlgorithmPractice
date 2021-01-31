#pragma once

class INowCoderEntry
{
public:
    INowCoderEntry() {}
    virtual ~INowCoderEntry() {}

    virtual int MainEntry() = 0;
};
