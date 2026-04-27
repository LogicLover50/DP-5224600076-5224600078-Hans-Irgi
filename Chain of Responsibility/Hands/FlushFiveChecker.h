#pragma once
#include "PokerHandChecker.h"

class FlushFiveChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isFlushFive(const Hand& hand);
};