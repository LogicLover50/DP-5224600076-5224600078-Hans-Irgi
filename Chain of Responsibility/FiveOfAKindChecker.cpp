#include <iostream>
#include <map>
#include "FiveOfAKindChecker.h"

static bool isFiveOfAKind(const Hand& hand)
{
    if (hand.cards.empty()) return false;

    std::map<int,int> freq;
    for (const auto& c : hand.cards) 
        freq[c.rank]++;

    return freq.size() == 1 && hand.cards.size() == 5;
}

HandRank FiveOfAKindChecker::check(const Hand& hand)
{
    if (isFiveOfAKind(hand))
    {
        std::cout << "Detected FIVE OF A KIND\n";
        return HandRank::FIVE_OF_A_KIND;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}