#include <iostream>
#include <algorithm>
#include <random>
#include "HandGenerator.h"

HandGenerator::HandGenerator() : rng(std::random_device{}())
{
    std::cout << "Generating Hand...\n";

    const char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits)
        for (int rank = 2; rank <= 14; ++rank)
            fullDeck.push_back({rank, suit});
}

void HandGenerator::resetDeckForRound()
{
    std::cout << "Shuffling Deck...\n";

    currentRoundDeck = fullDeck;
    std::shuffle(currentRoundDeck.begin(), currentRoundDeck.end(), rng);
}

void HandGenerator::replenishHand(Hand& currentHand)
{
    std::cout << "Drawing Hand...\n";

    while (currentHand.cards.size() < 8 && !currentRoundDeck.empty())
    {
        currentHand.cards.push_back(currentRoundDeck.back());
        currentRoundDeck.pop_back();
    }
}