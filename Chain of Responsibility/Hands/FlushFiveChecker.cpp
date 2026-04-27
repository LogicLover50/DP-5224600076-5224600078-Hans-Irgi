#include <iostream>
#include "FlushFiveChecker.h"

bool isFlushFive(const Hand& hand); // helper function

bool FlushFiveChecker::check(const Hand& hand)
{
    if (isFlushFive(hand))
    {
        std::cout << "Detected FLUSH\n";
        return true;
    }

    return false;
}