#include <iostream>
#include <map>
#include "FourOfAKindChecker.h"

static bool isFourOfAKind(const Hand& hand)
{
    std::map<int,int> freq;
    for (const auto& c : hand.cards)
        freq[c.rank]++;

    for (const auto& [rank, cnt] : freq)
        if (cnt == 4) return true;

    return false;
}

HandRank FourOfAKindChecker::check(const Hand& hand)
{
    if (isFourOfAKind(hand))
    {
        std::cout << "Detected FOUR OF A KIND\n";
        return HandRank::FOUR_OF_A_KIND;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}