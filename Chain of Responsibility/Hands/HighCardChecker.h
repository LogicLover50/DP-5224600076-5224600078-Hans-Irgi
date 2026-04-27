#pragma once
#include "PokerHandChecker.h"

class HighCardChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isHighCard(const Hand& hand);
};