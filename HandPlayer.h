#pragma once
#include "Hand.h"
#include "ChosenHand.h"

class HandPlayer{
public:
    ChosenHand playHand(const Hand& hand);
};