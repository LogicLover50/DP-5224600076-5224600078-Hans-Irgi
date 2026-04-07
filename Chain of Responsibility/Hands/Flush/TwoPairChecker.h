#pragma once
#include "PokerHandChecker.h"

class TwoPairChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isTwoPair(const Hand& hand);
};