#pragma once
#include "PokerHandChecker.h"

class ThreeOfAKindChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isThreeOfAKind(const Hand& hand);
};