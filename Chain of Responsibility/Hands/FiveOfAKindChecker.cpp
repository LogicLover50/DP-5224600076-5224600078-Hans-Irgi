#include <iostream>
#include "FiveOfAKindChecker.h"

bool isFiveOfAKind(const Hand& hand); // helper function

bool FiveOfAKindChecker::check(const Hand& hand)
{
    if (isFiveOfAKind(hand))
    {
        std::cout << "Detected FiveOfAKind\n";
        return true;
    }

    return false;
}