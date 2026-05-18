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
        for (int rank = 2; rank <= 14; ++rank)  // 2-10, J=11, Q=12, K=13, A=14
            deck.push_back({rank, suit});

    // Shuffle with a seeded Mersenne Twister
    std::mt19937 rng(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), rng);

    Hand hand;
    for (int i = 0; i < 5; ++i)
        hand.cards.push_back(deck[i]);

    const std::string rankNames[] = {"","","2","3","4","5","6","7","8","9","10","J","Q","K","A"};

    std::cout << "Dealt hand: ";
    for (const auto& card : hand.cards)
        std::cout << rankNames[card.rank] << card.suit << " ";
    std::cout << "\n";

    return hand;
}