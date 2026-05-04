#include <iostream>
#include <map>
#include "FlushHouseChecker.h"

static bool isFlushHouse(const Hand& hand)
{
    if (hand.cards.size() != 5) return false;

    char suit = hand.cards[0].suit;
    for (const auto& c : hand.cards)
        if (c.suit != suit) return false;

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