#include <iostream>
#include "TwoPairChecker.h"

bool isTwoPair(const Hand& hand); // helper function

bool TwoPairChecker::check(const Hand& hand)
{
    if (isTwoPair(hand))
    {
        std::cout << "Detected TWO PAIR\n";
        return true;
    }

    return false;
}