#pragma once
#include "IScore.h"
#include "../ChosenHand.h"

// Base Class untuk semua Joker (Gabungan Observer & Decorator)
class IJoker : public IScore {
protected:
    IScore* wrappedScore = nullptr;

public:
    virtual ~IJoker() = default;

    // --- DECORATOR ---
    void setNextScore(IScore* score) {
        wrappedScore = score;
    }

    // --- OBSERVER HOOKS ---
    virtual void onHandPlayed(const ChosenHand& hand) {}
    virtual void onBlindCleared() {}
};