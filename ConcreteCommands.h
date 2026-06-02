#pragma once
#include "RewardCommand.h"
#include "GameManager.h"
#include <iostream>

// === BONUS HAND COMMAND ===
class BonusHandCommand : public RewardCommand {
public:
    BonusHandCommand(RewardTiming t) : RewardCommand(t) {}

    void execute(GameManager& game) override
    {
        std::cout << "[REWARD ACTIVATED] Bonus Hand applied! (+1 Max Hand Play)\n";
        game.addMaxPlays(1); 
    }
};

// === FREE PLAYING CARD COMMAND ===
class FreePlayingCardCommand : public RewardCommand {
public:
    FreePlayingCardCommand(RewardTiming t) : RewardCommand(t) {}

    void execute(GameManager& game) override
    {
        std::cout << "[REWARD ACTIVATED] Free Playing Card generated and added to your running deck!\n";
    }
};