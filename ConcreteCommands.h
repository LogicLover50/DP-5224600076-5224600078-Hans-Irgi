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

// === DOUBLE MONEY COMMAND ===
class DoubleMoneyCommand : public RewardCommand {
public:
    DoubleMoneyCommand(RewardTiming t) : RewardCommand(t) {}
    void execute(GameManager& game) override
    {
        std::cout << "[REWARD ACTIVATED] Investment Payoff: Current money doubled!\n";
        game.doubleCurrentMoney();
    }
    std::string getRewardName() const override { return "Double Money Tag (Doubles current cash)"; }
};

// === HALF TARGET SCORE COMMAND ===
class HalfTargetScoreCommand : public RewardCommand {
public:
    HalfTargetScoreCommand(RewardTiming t) : RewardCommand(t) {}
    void execute(GameManager& game) override
    {
        std::cout << "[REWARD ACTIVATED] Weakened Defenses: Next blind target score halved!\n";
        game.applyHalfTargetModifier();
    }
    std::string getRewardName() const override { return "Handicap Tag (Halves target score of next blind)"; }
};

// === BONUS STATS COMMAND (+1 Hand, +1 Discard) ===
class BonusStatsCommand : public RewardCommand {
public:
    BonusStatsCommand(RewardTiming t) : RewardCommand(t) {}
    void execute(GameManager& game) override
    {
        std::cout << "[REWARD ACTIVATED] Tactical Safety: Gained +1 Play Hand and +1 Discard!\n";
        game.addMaxPlays(1);
        game.addDiscards(1);
    }
    std::string getRewardName() const override { return "Tactical Tag (+1 Hand Play & +1 Discard next blind)"; }
};