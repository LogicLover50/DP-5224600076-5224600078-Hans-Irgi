#pragma once
#include "C:\Users\Gaming 3\Documents\2gas\Kuliah\Design Pattern\Revised\DP-5224600076-5224600078-Hans-Irgi-main\ChosenHand.h"

// Interface dasar Decorator yang kini menerima data ChosenHand
class IScore {
public:
    virtual ~IScore() = default;
    virtual int getScore(const ChosenHand& hand) const = 0;
};