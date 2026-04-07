#include <iostream>
#include "StraightFlushChecker.h"

bool isStraightFlush(const Hand& hand); // helper function

bool StraightFlushChecker::check(const Hand& hand)
{
    if (isStraightFlush(hand))
    {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return true;
    }

    return false;
}