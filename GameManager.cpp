#include <algorithm>
#include <iostream>
#include "GameManager.h"

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
    this->targetScoreModifier = 1.0f;
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

void GameManager::runSession()
{
    std::cout << "=== Run Started ===\n";

    while (runActive && currentBlind != nullptr)
    {
        std::cout << "\n--------------------------------------------\n";
        std::cout << "Current Ante: " << currentAnte << "\n";
        std::cout << "Active Phase: " << currentBlind->getBlindName() << "\n";
        std::cout << "Target Score Needed: " << static_cast<int>(currentBlind->getTargetScore() * targetScoreModifier) << "\n";
        std::cout << "Current Money: $" << currentMoney << "\n";

        if (currentBlind->isSkippable())
        {
            auto potentialReward = currentBlind->createSkipReward();
            std::cout << "Skip Reward Available: " << potentialReward->getRewardName() << "\n";
            std::cout << "--------------------------------------------\n";
            std::cout << "Choose Action: [1] PLAY Blind  [2] SKIP Blind: ";
        }
        else
        {
            std::cout << "Skip Reward Available: None (Boss Blinds cannot be skipped)\n";
            std::cout << "--------------------------------------------\n";
            std::cout << "Choose Action: [1] PLAY Blind: ";
        }

        int choice;
        std::cin >> choice;

        if (choice == 2 && !currentBlind->isSkippable())
        {
            std::cout << "Invalid choice. You cannot skip this blind!\n";
            continue;
        }
        else if (choice == 2)
        {
            std::cout << "Skipping " << currentBlind->getBlindName() << "...\n";

            auto reward = currentBlind->createSkipReward();
            if (reward)
            {
                addPendingCommand(std::move(reward));
            }

            currentBlind->advance(*this);
        }
        else if (choice == 1)
        {
            triggerCommands(RewardTiming::Start);

            roundScore = 0;
            int actualTarget = static_cast<int>(currentBlind->getTargetScore() * targetScoreModifier);
            int playsLeft = remainingPlays;
            int discardsLeft = remainingDiscards;
            bool roundResolved = false;

            handGenerator.resetDeckForRound();
            Hand playerHand;

            std::cout << "\n--- Entering Match against " << currentBlind->getBlindName() << " ---\n\n";

            while (roundScore < actualTarget && playsLeft > 0)
            {
                std::cout << "========================================\n";
                std::cout << "Target: " << roundScore << " / " << actualTarget << "\n";
                std::cout << "Plays Remaining: " << playsLeft << " | Discards Remaining: " << discardsLeft << "\n";
                std::cout << "========================================\n";

                handGenerator.replenishHand(playerHand);
                ChosenHand chosen = handPlayer.playHand(playerHand);

                if (chosen.isEmpty()) continue;

                auto removeChosenFromHand = [&playerHand](const ChosenHand& selected)
                {
                    for (const auto& selectedCard : selected.cards.cards)
                    {
                        auto it = std::find_if(playerHand.cards.begin(), playerHand.cards.end(), [&selectedCard](const Card& c)
                            {
                                return c.rank == selectedCard.rank && c.suit == selectedCard.suit;
                            });
                        if (it != playerHand.cards.end())
                        {
                            playerHand.cards.erase(it);
                        }
                    }
                };

                std::cout << "\nChoose Action: [1] PLAY selected cards  [2] DISCARD selected cards: ";
                int roundAction;
                std::cin >> roundAction;

                if (roundAction == 1)
                {
                    int score = scoringRule.scoreHand(chosen.cards);
                    roundScore += score;
                    playsLeft--;

                    removeChosenFromHand(chosen);
                    std::cout << "Played Cards. Scored: " << score << " points! Current Round Total: " << roundScore << "\n";
                }
                else if (roundAction == 2)
                {
                    if (discardsLeft > 0)
                    {
                        discardsLeft--;

                        removeChosenFromHand(chosen);
                        std::cout << "Discarded Cards. Drawing new options...\n";
                    }
                    else
                    {
                        std::cout << "Out of discards! Forcing Play Action...\n";

                        int score = scoringRule.scoreHand(chosen.cards);
                        roundScore += score;
                        playsLeft--;

                        removeChosenFromHand(chosen);
                        std::cout << "Scored: " << score << " points! Total Round Score: " << roundScore << "\n";
                    }
                }
            }

            if (roundScore >= actualTarget)
            {
                std::cout << "\nBlind Cleared! Gained $" << currentBlind->getRewardMoney() << "\n";
                currentMoney += currentBlind->getRewardMoney();
                currentBlind->advance(*this);
            }
            else
            {
                std::cout << "\nGame Over! Ran out of hands before reaching the target score.\n";
                runActive = false;
            }
        }
    }
    std::cout << "=== Run Ended ===\n";
}