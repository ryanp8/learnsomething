#include <iostream>
#include <vector>
#include <time.h>

void prime() {
    for (int i = 2; i < 2500; i++) {
        std::vector<int> uniquePrimes;
        int currentPrime = i;
        for (size_t j = 2; j * j <= currentPrime; j++) {
            if (currentPrime % j == 0) {
                while (currentPrime % j == 0) {
                    currentPrime /= j;
                }
                uniquePrimes.push_back(j);
            }
        }
        if (currentPrime != 1) {
            uniquePrimes.push_back(currentPrime);
        }
    }
}