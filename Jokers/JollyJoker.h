#pragma once
#include "IJoker.h"
#include <iostream>

// Joker 1 (Pure Decorator): Memberikan flat +50 Chips/Score tanpa syarat
class JollyJoker : public IJoker {
public:
    int getScore(const ChosenHand& hand) const override {
        int currentScore = wrappedScore ? wrappedScore->getScore(hand) : 0;
        std::cout << "[Joker] Jolly Joker aktif: +50 Score\n";
        return currentScore + 50;
    }
};