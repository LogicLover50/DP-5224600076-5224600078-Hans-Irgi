#include "GameManager.h"
#include "ConcreteBlinds.h"
#include "Jokers/JollyJoker.h"
#include "Jokers/MultiplierJoker.h"
#include "Jokers/HalfJoker.h"
#include "Jokers/GreenJoker.h"
#include <memory>

int main()
{
    GameManager gameManager;

    // Inject keempat Joker ke dalam game
    gameManager.addJoker(std::make_unique<JollyJoker>());
    gameManager.addJoker(std::make_unique<HalfJoker>());
    gameManager.addJoker(std::make_unique<GreenJoker>());
    gameManager.addJoker(std::make_unique<MultiplierJoker>()); // Multiplier ditaruh terakhir agar efeknya maksimal
    
    gameManager.transitionTo(std::make_unique<SmallBlindState>());
    gameManager.runSession();
    return 0;
}
