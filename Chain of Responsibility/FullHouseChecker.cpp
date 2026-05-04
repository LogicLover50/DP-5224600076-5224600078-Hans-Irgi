#include <iostream>
#include <map>
#include "FullHouseChecker.h"

static bool isFullHouse(const Hand& hand)
{
    std::map<int,int> freq;
    for (const auto& c : hand.cards)
        freq[c.rank]++;

    bool hasThree = false, hasTwo = false;
    for (const auto& [rank, cnt] : freq)
    {
        if (cnt == 3) hasThree = true;
        if (cnt == 2) hasTwo   = true;
    }

    return hasThree && hasTwo;
}

HandRank FullHouseChecker::check(const Hand& hand)
{
    if (isFullHouse(hand))
    {
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}