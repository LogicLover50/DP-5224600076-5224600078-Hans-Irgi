#include <iostream>
#include "FourOfAKindChecker.h"

bool isFourOfAKind(const Hand& hand); // helper function

bool FourOfAKindChecker::check(const Hand& hand)
{
    if (isFourOfAKind(hand))
    {
        std::cout << "Detected FOUR OF A KIND\n";
        return true;
    }

    return false;
}