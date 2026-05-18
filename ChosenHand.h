#pragma once
#include "Hand.h"
#include <string>

class ChosenHand{
public:
    Hand cards;
    std::string handName;

    ChosenHand() = default;
    explicit ChosenHand(const Hand& hand) : cards(hand) {}

    bool isEmpty() const { return cards.cards.empty(); }
};