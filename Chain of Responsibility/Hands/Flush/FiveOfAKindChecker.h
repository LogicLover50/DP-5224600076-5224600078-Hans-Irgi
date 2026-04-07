#pragma once
#include "PokerHandChecker.h"

class FiveOfAKindChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isFiveOfAKind(const Hand& hand);
};