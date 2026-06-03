#pragma once
#include "IJoker.h"
#include <iostream>

// Joker 4 (Observer + Decorator): +10 Skor setiap kali tangan dimainkan.
class GreenJoker : public IJoker {
private:
    int bonusScore = 0;

public:
    void onHandPlayed(const ChosenHand& hand) override {
        bonusScore += 10;
        std::cout << "[Joker] Green Joker bereaksi! Potensi bonus naik jadi +" << bonusScore << "\n";
    }

    int getScore(const ChosenHand& hand) const override {
        int currentScore = wrappedScore ? wrappedScore->getScore(hand) : 0;
        std::cout << "[Joker] Green Joker menambahkan +" << bonusScore << " Score\n";
        return currentScore + bonusScore;
    }
};