#ifndef RUN_SESSION_H
#define RUN_SESSION_H

#include "InputGenerator.h"
#include "ScoringRule.h"
#include "RewardRule.h"
#include "ShopSystem.h"

class RunSession {
public:
    RunSession(IInputGenerator* inputGen,
               IScoringRule* scoring,
               IRewardRule* reward);

    void StartRun();

private:
    IInputGenerator* inputGen_;
    IScoringRule* scoring_;
    IRewardRule* reward_;
    ShopSystem shop_;

    int money_;
};

#endif