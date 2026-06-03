#pragma once
#include "IJoker.h"
#include <iostream>

// Joker 3 (Conditional Decorator): +40 Skor JIKA kartu yang dimainkan 3 atau kurang
class HalfJoker : public IJoker {
public:
    int getScore(const ChosenHand& hand) const override {
        int currentScore = wrappedScore ? wrappedScore->getScore(hand) : 0;

        // Membaca data dari parameter ChosenHand
        if (hand.cards.cards.size() <= 3) {
            std::cout << "[Joker] Half Joker aktif (Kartu <= 3): +40 Score\n";
            return currentScore + 40;
        }
        return currentScore;
    }
};