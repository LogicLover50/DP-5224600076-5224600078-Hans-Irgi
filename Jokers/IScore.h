#pragma once
#include "..\ChosenHand.h"

// Interface dasar Decorator yang kini menerima data ChosenHand
class IScore {
public:
    virtual ~IScore() = default;
    virtual int getScore(const ChosenHand& hand) const = 0;
};