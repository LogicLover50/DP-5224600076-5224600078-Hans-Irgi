#include <iostream>
#include <vector>
#include <algorithm>
#include "StraightFlushChecker.h"

static bool isStraightFlush(const Hand& hand)
{
    if (hand.cards.size() != 5) return false;

    char suit = hand.cards[0].suit;
    for (const auto& c : hand.cards)
        if (c.suit != suit) return false;

    std::vector<int> ranks;
    for (const auto& c : hand.cards)
        ranks.push_back(c.rank);

    std::sort(ranks.begin(), ranks.end());
    for (int i = 1; i < (int)ranks.size(); ++i)
        if (ranks[i] == ranks[i-1]) return false;

    if (ranks[4] - ranks[0] == 4) return true;
    if (ranks[4] == 14 && ranks[0] == 2 && ranks[3] == 5) return true;

    return false;
}

HandRank StraightFlushChecker::check(const Hand& hand)
{
    if (isStraightFlush(hand))
    {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}