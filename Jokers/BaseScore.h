#pragma once
#include "IScore.h"

// Menyimpan skor mentah awal dari ScoringRule
class BaseScore : public IScore {
private:
    int baseValue;
public:
    explicit BaseScore(int score) : baseValue(score) {}

    int getScore(const ChosenHand& hand) const override {
        return baseValue;
    }
};