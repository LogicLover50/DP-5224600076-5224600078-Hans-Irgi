#include <iostream>
#include "StraightChecker.h"

bool isStraight(const Hand& hand)
{
    return hand.value == 11;
}

HandRank StraightChecker::check(const Hand& hand)
{
    if (isStraight(hand))
    {
        std::cout << "Detected STRAIGHT\n";
        return HandRank::STRAIGHT;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}