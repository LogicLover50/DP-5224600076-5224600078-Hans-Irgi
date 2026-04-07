#pragma once
#include "PokerHandChecker.h"

class FullHouseChecker : public PokerHandChecker{
public:
    bool check(const Hand& hand) override;
    bool isFullHouse(const Hand& hand);
};