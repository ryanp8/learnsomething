//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
private:
    double balance = 0.0;
    double purchasePrice = 100.0;
    bool holding = true;
    int consecutiveIncreasing = 1;
    int consecutiveDecreasing = 1;
    double consecutiveCloseStart = 100.0;
    std::vector<double> priceHistory = {100.0};
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
