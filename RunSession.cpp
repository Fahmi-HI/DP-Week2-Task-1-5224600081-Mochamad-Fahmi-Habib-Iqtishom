#include <iostream>
#include "RunSession.h"

RunSession::RunSession(IInputGenerator* inputGen,
                       IScoringRule* scoring,
                       IRewardRule* reward)
{
    inputGen_ = inputGen;
    scoring_ = scoring;
    reward_ = reward;
    money_ = 0;
}

void RunSession::StartRun() {

    std::cout << "=== RUN START ===\n\n";

    for(int round = 1; round <= 3; round++) {

        std::cout << "Round " << round << "\n";

        int input = inputGen_->GenerateInput();
        std::cout << "[PLAY] input generated: " << input << "\n";

        int score = scoring_->ComputeScore(input);
        std::cout << "[SCORE] base score: " << score << "\n";

        int reward = reward_->ComputeReward(score, round);
        money_ += reward;

        std::cout << "[REWARD] gain: " << reward
                  << " | money: " << money_ << "\n";

        shop_.ShowShop();

        std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final money: " << money_ << "\n";
}