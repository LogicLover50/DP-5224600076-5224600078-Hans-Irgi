#include "ConcreteBlinds.h"
#include "ConcreteCommands.h"
#include "GameManager.h"

// === Small Blind ===
std::string SmallBlindState::getBlindName() const { return "Small Blind"; }
int SmallBlindState::getTargetScore() const { return 300; }
int SmallBlindState::getRewardMoney() const { return 3; }

void SmallBlindState::advance(GameManager& game)
{
    game.transitionTo(std::make_unique<BigBlindState>());
}

std::unique_ptr<RewardCommand> SmallBlindState::createSkipReward()
{
    return std::make_unique<DoubleMoneyCommand>(RewardTiming::Start);
}

// === Big Blind ===
std::string BigBlindState::getBlindName() const { return "Big Blind"; }
int BigBlindState::getTargetScore() const { return 450; }
int BigBlindState::getRewardMoney() const { return 4; }

void BigBlindState::advance(GameManager& game)
{
    game.transitionTo(std::make_unique<BossBlindState>());
}

std::unique_ptr<RewardCommand> BigBlindState::createSkipReward()
{
    return std::make_unique<HalfTargetScoreCommand>(RewardTiming::Start);
}

// === Boss Blind ===
std::string BossBlindState::getBlindName() const { return "Boss Blind"; }
int BossBlindState::getTargetScore() const { return 800; }
int BossBlindState::getRewardMoney() const { return 5; }

void BossBlindState::advance(GameManager& game)
{
    game.addAnte(1);
    game.resetBlindCycle();
    game.transitionTo(std::make_unique<SmallBlindState>());
}

std::unique_ptr<RewardCommand> BossBlindState::createSkipReward()
{
    return std::make_unique<BonusStatsCommand>(RewardTiming::NextAnte);
}