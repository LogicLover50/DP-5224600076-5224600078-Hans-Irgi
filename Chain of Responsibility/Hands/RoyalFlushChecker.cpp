#include <iostream>
#include "RoyalFlushChecker.h"

bool isRoyalFlush(const Hand& hand); // helper function

bool RoyalFlushChecker::check(const Hand& hand)
{
    if (isRoyalFlush(hand))
    {
        std::cout << "Detected ROYAL FLUSH\n";
        return true;
    }

    return false;
}