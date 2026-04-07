#pragma once
#include "PokerHandChecker.h"

class FourOfAKindChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isFourOfAKind(const Hand& hand);
};