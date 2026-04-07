#include <iostream>
#include "FlushChecker.h"

bool isFlush(const Hand& hand); // helper function

bool FlushChecker::check(const Hand& hand)
{
    if (isFlush(hand))
    {
        std::cout << "Detected FLUSH\n";
        return true;
    }

    return false;
}