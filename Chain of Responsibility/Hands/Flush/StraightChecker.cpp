#include <iostream>
#include "StraightChecker.h"

bool isStraight(const Hand& hand); // helper function

bool StraightChecker::check(const Hand& hand)
{
    if (isStraight(hand))
    {
        std::cout << "Detected STRAIGHT\n";
        return true;
    }

    return false;
}