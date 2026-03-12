#include <iostream>
#include <cstdlib>
#include <ctime>

#include "RunSession.h"

int main() {

    srand(time(0));

    RandomInputGenerator input;
    BasicScoring scoring;
    ModifiedReward reward;

    RunSession session(&input, &scoring, &reward);

    session.StartRun();

    return 0;
}