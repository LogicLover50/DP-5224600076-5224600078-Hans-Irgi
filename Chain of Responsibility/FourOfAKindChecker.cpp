#include <iostream>
#include "FourOfAKindChecker.h"

bool isFourOfAKind(const Hand& hand)
{
    return hand.value == 11;
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