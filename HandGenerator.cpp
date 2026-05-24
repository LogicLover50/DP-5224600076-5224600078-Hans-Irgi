#include <iostream>
#include <algorithm>
#include <random>
#include "HandGenerator.h"

Hand HandGenerator::generateHand()
{
    std::cout << "Generating hand...\n";

    std::vector<Card> deck;
    const char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits)
        for (int rank = 2; rank <= 14; ++rank)
            deck.push_back({rank, suit});

    std::mt19937 rng(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), rng);

    Hand hand;
    for (int i = 0; i < 8; ++i)
        hand.cards.push_back(deck[i]);

    return hand;
}