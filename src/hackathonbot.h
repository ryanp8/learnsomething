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
    double balance;
    double purchasePrice;
    bool holding;
    int consecutiveIncreasing;
    int consecutiveDecreasing;
    double consecutiveCloseStart;
    std::vector<double> priceHistory;
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
