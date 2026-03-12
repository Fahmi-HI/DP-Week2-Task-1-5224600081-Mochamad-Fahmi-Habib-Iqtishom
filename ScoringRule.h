#ifndef SCORING_RULE_H
#define SCORING_RULE_H

class IScoringRule {
public:
    virtual int ComputeScore(int input) = 0;
};

class BasicScoring : public IScoringRule {
public:
    int ComputeScore(int input) override {
        return input;
    }
};

#endif