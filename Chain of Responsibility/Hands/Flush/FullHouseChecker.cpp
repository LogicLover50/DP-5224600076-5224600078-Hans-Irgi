#include <iostream>
#include "FullHouseChecker.h"

bool isFullHouse(const Hand& hand); // helper function

bool FullHouseChecker::check(const Hand& hand)
{
    if (isFullHouse(hand))
    {
        std::cout << "Detected FULL HOUSE\n";
        return true;
    }

    return false;
}