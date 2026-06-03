#pragma once

class GameManager; 

enum class RewardTiming
{
    Start,
    NextBlind,
    NextAnte
};

class RewardCommand {
protected:
    RewardTiming timing;
public:
    RewardCommand(RewardTiming t) : timing(t) {}
    virtual ~RewardCommand() = default;

    RewardTiming getTiming() const { return timing; }
    virtual void execute(GameManager& game) = 0;
    virtual std::string getRewardName() const = 0;
};