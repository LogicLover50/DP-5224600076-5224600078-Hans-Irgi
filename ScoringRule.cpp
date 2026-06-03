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
    case HandRank::FLUSH_FIVE:      return 420;
    case HandRank::FLUSH_HOUSE:     return 390;
    case HandRank::FIVE_OF_A_KIND:  return 360;
    case HandRank::ROYAL_FLUSH:     return 300;
    case HandRank::STRAIGHT_FLUSH:  return 270;
    case HandRank::FOUR_OF_A_KIND:  return 240;
    case HandRank::FULL_HOUSE:      return 210;
    case HandRank::FLUSH:           return 180;
    case HandRank::STRAIGHT:        return 150;
    case HandRank::THREE_OF_A_KIND: return 120;
    case HandRank::TWO_PAIR:        return 90;
    case HandRank::PAIR:            return 60;
    case HandRank::HIGH_CARD:       return 30;
    default:                        return 30;
    }
}