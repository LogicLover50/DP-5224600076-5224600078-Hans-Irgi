#include <iostream>
#include "GameManager.h"
#include "Jokers/BaseScore.h" // Tambahan Header BaseScore

GameManager::GameManager()
{
    currentBlind = std::make_unique<SmallBlindState>();
}

void GameManager::transitionTo(std::unique_ptr<BlindState> newState)
{
    currentBlind = std::move(newState);
}

void GameManager::addPendingCommand(std::unique_ptr<RewardCommand> cmd)
{
    pendingCommands.push_back(std::move(cmd));
}

void GameManager::resetBlindCycle()
{
    std::cout << "[SYSTEM] Advanced to the next Ante. Resetting round counters!\n";
    this->remainingPlays = 4;
    this->remainingDiscards = 4;
}

void GameManager::triggerCommands(RewardTiming timing)
{
    auto it = pendingCommands.begin();
    while (it != pendingCommands.end())
    {
        if ((*it)->getTiming() == timing)
        {
            (*it)->execute(*this);
            it = pendingCommands.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// menambah fungsi untuk implementasi joker
void GameManager::addJoker(std::unique_ptr<IJoker> joker)
{
    activeJokers.push_back(std::move(joker));
}

//runSession diubah untuk bisa memanggil fungsi joker
void GameManager::runSession()
{
    std::cout << "=== Run Started ===\n";
    while (runActive && currentBlind != nullptr)
    {
        std::cout << "\n--------------------------------------------\n";
        std::cout << "Current Ante: " << currentAnte << "\n";
        std::cout << "Active Phase: " << currentBlind->getBlindName() << "\n";
        std::cout << "Target Score Needed: " << currentBlind->getTargetScore() << "\n";
        std::cout << "--------------------------------------------\n";
        std::cout << "Choose Action: [1] PLAY Blind  [2] SKIP Blind: ";
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            triggerCommands(RewardTiming::Start);
            roundScore = 0;
            Hand hand = handGenerator.generateHand();
            ChosenHand chosen = handPlayer.playHand(hand);

            // 1. OBSERVER PATTERN: Beritahu Joker kartu baru saja dimainkan
            for (auto& joker : activeJokers) {
                joker->onHandPlayed(chosen);
            }

            int rawScore = scoringRule.scoreHand(chosen.cards);

            // 2. DECORATOR PATTERN: Rangkai Joker dari kiri ke kanan
            BaseScore baseScore(rawScore);
            IScore* finalScoreObj = &baseScore;

            for (auto& joker : activeJokers) {
                joker->setNextScore(finalScoreObj);
                finalScoreObj = joker.get(); // Dapatkan raw pointer untuk rantai Decorator
            }

            // Eksekusi total skor
            int finalHandScore = finalScoreObj->getScore(chosen);
            addRoundScore(finalHandScore);

            std::cout << "Raw Score: " << rawScore << " | After Jokers: " << finalHandScore
                << " | Total Round Score: " << roundScore << "\n";

            if (roundScore >= currentBlind->getTargetScore())
            {
                std::cout << "Blind Cleared! Gained $" << currentBlind->getRewardMoney() << "\n";

                // 3. OBSERVER PATTERN: Beritahu Joker ronde sukses diselesaikan
                for (auto& joker : activeJokers) {
                    joker->onBlindCleared();
                }

                currentBlind->advance(*this);
            }
            else
            {
                std::cout << "Failed to beat the target score.\n";
                runActive = false;
            }
        }
        else if (choice == 2)
        {
            std::cout << "Skipping " << currentBlind->getBlindName() << "...\n";
            auto reward = currentBlind->createSkipReward();
            if (reward) {
                addPendingCommand(std::move(reward));
            }
            currentBlind->advance(*this);
        }
    }
    std::cout << "=== Run Ended ===\n";
}
