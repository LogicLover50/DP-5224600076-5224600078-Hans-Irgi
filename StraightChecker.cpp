#include <iostream>
#include <vector>
#include <algorithm>
#include "StraightChecker.h"

static bool isStraight(const Hand& hand)
{
    if (hand.cards.size() != 5) return false;

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