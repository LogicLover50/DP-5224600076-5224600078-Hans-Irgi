#include <iostream>
#include "HighCardChecker.h"

bool isHighCard(const Hand& hand)
{
    return hand.value == 11;
}

HandRank HighCardChecker::check(const Hand& hand)
{
    if (isHighCard(hand))
    {
        std::cout << "Detected HIGH CARD\n";
        return HandRank::HIGH_CARD;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}