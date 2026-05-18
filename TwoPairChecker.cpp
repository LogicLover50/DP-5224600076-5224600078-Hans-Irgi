#include <iostream>
#include <map>
#include "TwoPairChecker.h"

static bool isTwoPair(const Hand& hand)
{
    std::map<int,int> freq;
    for (const auto& c : hand.cards)
        freq[c.rank]++;

    int pairs = 0;
    for (const auto& [rank, cnt] : freq)
        if (cnt == 2) pairs++;

    return pairs == 2;
}

HandRank TwoPairChecker::check(const Hand& hand)
{
    if (isTwoPair(hand))
    {
        std::cout << "Detected TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}