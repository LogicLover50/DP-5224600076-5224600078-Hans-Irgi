#include <iostream>
#include "FlushHouseChecker.h"

bool isFlushHouse(const Hand& hand); // helper function

bool FlushHouseChecker::check(const Hand& hand)
{
    if (isFlushHouse(hand))
    {
        std::cout << "Detected FLUSH HOUSE\n";
        return true;
    }

    return false;
}