#include <iostream>
#include <map>
#include "PairChecker.h"

static bool isPair(const Hand& hand)
{
    std::map<int,int> freq;
    for (const auto& c : hand.cards)
        freq[c.rank]++;

    int pairs = 0;
    for (const auto& [rank, cnt] : freq)
        if (cnt >= 2) pairs++;

    return pairs == 1;
}

HandRank PairChecker::check(const Hand& hand)
{
    if (isPair(hand))
    {
        std::cout << "Detected PAIR\n";
        return HandRank::PAIR;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}