#include <iostream>
#include "TwoPairChecker.h"

bool isTwoPair(const Hand& hand)
{
    return hand.value == 11;
}

HandRank TwoPairChecker::check(const Hand& hand)
{
    if (isTwoPair(hand))
    {
        std::cout << "Detected TWOPAIR\n";
        return HandRank::TWO_PAIR;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}