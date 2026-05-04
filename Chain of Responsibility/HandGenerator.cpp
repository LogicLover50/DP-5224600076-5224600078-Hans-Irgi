#include <iostream>
#include "HandGenerator.h"

Hand HandGenerator::generateHand()
{
    std::cout << "Generating hand...\n";
    Hand hand;
    hand.cards.push_back({10, 'H'});
    hand.cards.push_back({11, 'H'});
    hand.cards.push_back({12, 'H'});
    hand.cards.push_back({13, 'H'});
    hand.cards.push_back({14, 'H'});
    return hand;
}