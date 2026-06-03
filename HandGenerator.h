#pragma once
#include <vector>
#include <random>
#include "Hand.h"

class HandGenerator {
private:
    std::vector<Card> fullDeck;
    std::vector<Card> currentRoundDeck;
    std::mt19937 rng;

public:
    HandGenerator();
    void resetDeckForRound(); 
    void replenishHand(Hand& currentHand); 
};