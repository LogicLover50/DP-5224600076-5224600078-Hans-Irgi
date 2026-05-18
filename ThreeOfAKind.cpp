#include <iostream>
#include <map>
#include "ThreeOfAKindChecker.h"

static bool isThreeOfAKind(const Hand& hand)
{
    std::map<int,int> freq;
    for (const auto& c : hand.cards)
        freq[c.rank]++;

    for (const auto& [rank, cnt] : freq)
        if (cnt == 3) return true;

    return false;
}

HandRank ThreeOfAKindChecker::check(const Hand& hand)
{
    if (isThreeOfAKind(hand))
    {
        std::cout << "Detected THREE OF A KIND\n";
        return HandRank::THREE_OF_A_KIND;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}