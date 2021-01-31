#pragma once

class ILeetCodeEntry
{
public:
    ILeetCodeEntry() {}
    virtual ~ILeetCodeEntry() {}

    virtual int MainEntry() = 0;
};
