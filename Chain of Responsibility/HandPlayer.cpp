#include <iostream>
#include "HandPlayer.h"

ChosenHand HandPlayer::playHand(const Hand& hand)
{
    std::cout << "Player selects cards to play...\n";
    ChosenHand chosen(hand);
    return chosen;
}