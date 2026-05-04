#pragma once
#include "Hand.h"
#include "PokerHandChecker.h"
#include "FlushFiveChecker.h"
#include "FlushHouseChecker.h"
#include "FiveOfAKindChecker.h"
#include "RoyalFlushChecker.h"
#include "StraightFlushChecker.h"
#include "FourOfAKindChecker.h"
#include "FullHouseChecker.h"
#include "FlushChecker.h"
#include "StraightChecker.h"
#include "ThreeOfAKindChecker.h"
#include "TwoPairChecker.h"
#include "PairChecker.h"
#include "HighCardChecker.h"

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