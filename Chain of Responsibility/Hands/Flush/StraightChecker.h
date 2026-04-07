#pragma once
#include "PokerHandChecker.h"

class StraightChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isStraight(const Hand& hand);
};