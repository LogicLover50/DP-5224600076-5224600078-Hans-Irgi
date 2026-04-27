#include <iostream>
#include "HighCardChecker.h"

bool isHighCard(const Hand& hand); // helper function

bool HighCardChecker::check(const Hand& hand)
{
    if (isHighCard(hand))
    {
        std::cout << "Detected HIGH CARD\n";
        return true;
    }

    return false;
}