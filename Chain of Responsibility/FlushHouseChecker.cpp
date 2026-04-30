#include <iostream>
#include "FlushHouseChecker.h"

bool isFlushHouse(const Hand& hand)
{
    return hand.value == 11;
}

HandRank FlushHouseChecker::check(const Hand& hand)
{
    if (isFlushHouse(hand))
    {
        std::cout << "Detected FLUSH HOUSE\n";
        return HandRank::FLUSH_HOUSE;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}