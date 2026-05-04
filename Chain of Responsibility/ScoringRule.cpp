#include <iostream>
#include "ScoringRule.h"

ScoringRule::ScoringRule()
{
    flushFiveChecker.setNext(&flushHouseChecker);
    flushHouseChecker.setNext(&fiveOfAKindChecker);
    fiveOfAKindChecker.setNext(&royalFlushChecker);
    royalFlushChecker.setNext(&straightFlushChecker);
    straightFlushChecker.setNext(&fourOfAKindChecker);
    fourOfAKindChecker.setNext(&fullHouseChecker);
    fullHouseChecker.setNext(&flushChecker);
    flushChecker.setNext(&straightChecker);
    straightChecker.setNext(&threeOfAKindChecker);
    threeOfAKindChecker.setNext(&twoPairChecker);
    twoPairChecker.setNext(&pairChecker);
    pairChecker.setNext(&highCardChecker);
}

int ScoringRule::scoreHand(const Hand& hand)
{
    std::cout << "Calculating hand score...\n";

    HandRank rank = flushFiveChecker.check(hand);
    int score = convertRankToScore(rank);

    std::cout << "Final score = " << score << "\n";
    return score;
}

int ScoringRule::convertRankToScore(HandRank rank)
{
    switch (rank)
    {
    case HandRank::FLUSH_FIVE:      return 160;
    case HandRank::FLUSH_HOUSE:     return 140;
    case HandRank::FIVE_OF_A_KIND:  return 120;
    case HandRank::ROYAL_FLUSH:     return 100;
    case HandRank::STRAIGHT_FLUSH:  return 90;
    case HandRank::FOUR_OF_A_KIND:  return 80;
    case HandRank::FULL_HOUSE:      return 70;
    case HandRank::FLUSH:           return 60;
    case HandRank::STRAIGHT:        return 50;
    case HandRank::THREE_OF_A_KIND: return 40;
    case HandRank::TWO_PAIR:        return 30;
    case HandRank::PAIR:            return 20;
    case HandRank::HIGH_CARD:       return 5;
    default:                        return 5;
    }
}