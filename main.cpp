#include "GameManager.h"
#include "ConcreteBlinds.h"
#include <memory>

int main()
{
    GameManager gameManager;
    gameManager.transitionTo(std::make_unique<SmallBlindState>());
    gameManager.runSession();
    return 0;
}