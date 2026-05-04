#include <iostream>
#include <map>
#include "FlushFiveChecker.h"

static bool isFlushFive(const Hand& hand)
{
    if (hand.cards.size() != 5) return false;

    char suit = hand.cards[0].suit;
    for (const auto& c : hand.cards)
        if (c.suit != suit) return false;

    std::map<int,int> freq;
    for (const auto& c : hand.cards)
        freq[c.rank]++;

    return freq.size() == 1;
}

HandRank FlushFiveChecker::check(const Hand& hand)
{
    if (isFlushFive(hand))
    {
        std::cout << "Detected FLUSH FIVE\n";
        return HandRank::FLUSH_FIVE;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}