#ifndef REWARD_RULE_H
#define REWARD_RULE_H

class IRewardRule {
public:
    virtual int ComputeReward(int baseScore, int round) = 0;
};

class BasicReward : public IRewardRule {
public:
    int ComputeReward(int baseScore, int round) override {
        return baseScore;
    }
};

class ModifiedReward : public IRewardRule {
public:
    int ComputeReward(int baseScore, int round) override {
        return baseScore +2;
    }
};

#endif