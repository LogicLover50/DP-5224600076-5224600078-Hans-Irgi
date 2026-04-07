#include <iostream>
#include "PairChecker.h"

bool isPair(const Hand& hand); // helper function

bool PairChecker::check(const Hand& hand)
{
    if (isPair(hand))
    {
        std::cout << "Detected PAIR\n";
        return true;
    }

    return false;
}