#include <iostream>
#include <vector>
#include <algorithm>
#include "RoyalFlushChecker.h"

static bool isRoyalFlush(const Hand& hand)
{
    if (hand.cards.size() != 5) return false;

    char suit = hand.cards[0].suit;
    for (const auto& c : hand.cards)
        if (c.suit != suit) return false;

    std::vector<int> ranks;
    for (const auto& c : hand.cards)
        ranks.push_back(c.rank);

    std::sort(ranks.begin(), ranks.end());
    if (ranks[0]==10 && ranks[1]==11 && ranks[2]==12 && ranks[3]==13 && ranks[4]==14) return true;

    return false;
}

HandRank RoyalFlushChecker::check(const Hand& hand)
{
    if (isRoyalFlush(hand))
    {
        std::cout << "Detected ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}