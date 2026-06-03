#pragma once
#include "BlindState.h"
#include <memory>
#include <string>

class SmallBlindState : public BlindState {
public:
    std::string getBlindName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;

    void advance(GameManager& game) override;
    std::unique_ptr<RewardCommand> createSkipReward() override;
};

class BigBlindState : public BlindState {
public:
    std::string getBlindName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;

    void advance(GameManager& game) override;
    std::unique_ptr<RewardCommand> createSkipReward() override;
};

class BossBlindState : public BlindState {
public:
    std::string getBlindName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;
    bool isSkippable() const override { return false; }

    void advance(GameManager& game) override;
    std::unique_ptr<RewardCommand> createSkipReward() override;
};