#pragma once
#include "PokerHandChecker.h"

class StraightFlushChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isStraightFlush(const Hand& hand);
};