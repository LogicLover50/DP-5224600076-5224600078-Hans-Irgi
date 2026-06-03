#pragma once
#include "IJoker.h"
#include <iostream>

// Joker 2 (Pure Decorator): Mengalikan skor akhir x2
class MultiplierJoker : public IJoker {
public:
    int getScore(const ChosenHand& hand) const override {
        int currentScore = wrappedScore ? wrappedScore->getScore(hand) : 0;
        std::cout << "[Joker] Multiplier Joker aktif: Score x2!\n";
        return currentScore * 2;
    }
};