#include <iostream>
#include "FlushChecker.h"

static bool isFlush(const Hand& hand)
{
    if (hand.cards.empty()) return false;

    char suit = hand.cards[0].suit;
    for (const auto& c : hand.cards)
        if (c.suit != suit) return false;

    return true;
}

HandRank FlushChecker::check(const Hand& hand)
{
    if (isFlush(hand))
    {
        std::cout << "Detected FLUSH\n";
        return HandRank::FLUSH;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}