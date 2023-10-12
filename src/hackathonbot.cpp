//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"

HackathonBot::HackathonBot() {
    this->balance = 0.0;
    this->purchasePrice = 100.0;
    this->holding = true;
    this->consecutiveIncreasing = 1;
    this->consecutiveDecreasing = 1;
    this->consecutiveCloseStart = 100.0;
    this->priceHistory = {100.0};
};

void HackathonBot::takeAction(float price) {
    if (this->priceHistory.size() > 0) {
        if (price > this->priceHistory.back()) {
            this->consecutiveIncreasing++;
            this->consecutiveDecreasing = 0;
        }
        else if (price < this->priceHistory.back()) {
            this->consecutiveIncreasing = 0;
            this->consecutiveDecreasing++;
        }
    }

    this->priceHistory.push_back(price);

    if (!this->holding) {
        if (price < 52) {
            this->balance -= price;
            this->holding = true;
        }
        else if (this->consecutiveIncreasing == 52 || this->consecutiveDecreasing == 49) {
            this->balance += price;
            this->holding = false;
        }
        else if (this->consecutiveDecreasing == 5) {
            this->balance -= price;
            this->holding = true;
        }
    }
    else {
        if (price < this->purchasePrice * 0.62 || price > this->purchasePrice * 1.89) {
            this->balance += price;
            this->holding = false;
        }
        else if (this->priceHistory.size() >= 10) {
            int start = this->priceHistory.size() - 10;
            double startPrice = this->priceHistory[start];
            bool allGood = true;
            for (int i = start; i < this->priceHistory.size(); i++) {
                if (abs(this->priceHistory[i] - startPrice) / startPrice > 0.05) {
                    allGood = false;
                    break;
                }
            }
            if (allGood) {
                this->balance += price;
                this->holding = false;
            }
        }
        else if (this->priceHistory.size() >= 4) {
            size_t s = this->priceHistory.size();
            double p0 = this->priceHistory[s - 4];
            double p1 = this->priceHistory[s - 3];
            double p2 = this->priceHistory[s - 2];
            double p3 = this->priceHistory[s - 1];

            if ((p1 >= p0 * 1.2 && p2 >= p1 * 0.85 && p3 >= p2 * 1.3)
                && ((p3 - p0) >= p0 * 1.45)) {
                this->balance += price;
                this->holding = false;
            }
            else if ((p1 >= 0.85 * p0 && p2 >= p1 * 1.15 && p3 <= p2 * 0.75)
                    && (p3 - p0 <= p0 * 0.45)) {
                    this->balance += price;
                    this->holding = false;
                }
        }
    }
};

double HackathonBot::getBalance() {
    return this->balance;
}

bool HackathonBot::isHolding() {
    return this->holding;
}