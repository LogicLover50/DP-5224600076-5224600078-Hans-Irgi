#pragma once
#include "Hand.h"
#include "PokerHandChecker.h"
#include "Hands/FlushFiveChecker.h"
#include "Hands/FlushHouseChecker.h"
#include "Hands/FiveOfAKindChecker.h"
#include "Hands/RoyalFlushChecker.h"
#include "Hands/StraightFlushChecker.h"
#include "Hands/FourOfAKindChecker.h"
#include "Hands/FullHouseChecker.h"
#include "Hands/FlushChecker.h"
#include "Hands/StraightChecker.h"
#include "Hands/ThreeOfAKindChecker.h"
#include "Hands/TwoPairChecker.h"
#include "Hands/PairChecker.h"
#include "Hands/HighCardChecker.h"

class ScoringRule{
public:
    ScoringRule();
    int scoreHand(const Hand& hand);

private:
    FlushFiveChecker        flushFiveChecker;
    FlushHouseChecker       flushHouseChecker;
    FiveOfAKindChecker      fiveOfAKindChecker;
    RoyalFlushChecker       royalFlushChecker;
    StraightFlushChecker    straightFlushChecker;
    FourOfAKindChecker      fourOfAKindChecker;
    FullHouseChecker        fullHouseChecker;
    FlushChecker            flushChecker;
    StraightChecker         straightChecker;
    ThreeOfAKindChecker     threeOfAKindChecker;
    TwoPairChecker          twoPairChecker;
    PairChecker             pairChecker;
    HighCardChecker         highCardChecker;

    int convertRankToScore(HandRank rank);
};