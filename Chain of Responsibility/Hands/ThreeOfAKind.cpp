#include <iostream>
#include "ThreeOfAKindChecker.h"

bool isThreerOfAKind(const Hand& hand); // helper function

bool ThreeOfAKindChecker::check(const Hand& hand)
{
    if (isThreeOfAKind(hand))
    {
        std::cout << "Detected THREE OF A KIND\n";
        return true;
    }

    return false;
}