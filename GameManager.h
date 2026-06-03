#pragma once
#include <vector>
#include <memory>
#include "BlindState.h"
#include "ConcreteBlinds.h"
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "RewardCommand.h"
#include "ScoringRule.h"
#include "Jokers/IJoker.h" // Menambah Header Joker

class GameManager {
public:
    GameManager();
    void runSession();

    void transitionTo(std::unique_ptr<BlindState> newState);
    void addPendingCommand(std::unique_ptr<RewardCommand> cmd);
    void triggerCommands(RewardTiming timing);

    // Menambah fungsi untuk Joker
    void addJoker(std::unique_ptr<IJoker> joker);

    void addAnte(int val) { currentAnte += val; }
    void resetAnteCycle() { currentAnte = 1; }
    void resetBlindCycle();
    void addMaxPlays(int val) { remainingPlays += val; }
    void addRoundScore(int score) { roundScore += score; }
    int getRoundScore() const { return roundScore; }

    void doubleCurrentMoney() { currentMoney *= 2; }
    void applyHalfTargetModifier() { targetScoreModifier = 0.5f; }
    void addDiscards(int val) { remainingDiscards += val; }

private:
    int currentAnte = 1;
    int roundScore = 0;
    int remainingPlays = 4;
    int remainingDiscards = 4;
    bool runActive = true;

    int currentMoney = 4;
    float targetScoreModifier = 1.0f;

    HandGenerator handGenerator;
    HandPlayer    handPlayer;
    ScoringRule   scoringRule; 

    std::unique_ptr<BlindState> currentBlind;
    std::vector<std::unique_ptr<RewardCommand>> pendingCommands;

    // Inventory Joker
    std::vector<std::unique_ptr<IJoker>> activeJokers;
};
