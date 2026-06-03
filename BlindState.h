#pragma once
#include <string>
#include <memory>

class GameManager;
class RewardCommand; 

class BlindState {
public:
    virtual ~BlindState() = default;

    virtual std::string getBlindName() const = 0;
    virtual int getTargetScore() const = 0;
    virtual int getRewardMoney() const = 0;
    virtual bool isSkippable() const { return true; }

    virtual void advance(GameManager& game) = 0;
    virtual std::unique_ptr<RewardCommand> createSkipReward() = 0;
};