#include <iostream>
#include <vector>
#include <unordered_set>
#include <time.h>

void prime() {
    std::unordered_set<int> seen_primes;
    for (int i = 2; i < 2500; i++) {
        std::vector<int> uniquePrimes;
        int currentPrime = i;
        for (size_t j = 2; j * j <= currentPrime; j++) {
            if (currentPrime % j == 0) {
                if (seen_primes.count(j)) {
                    uniquePrimes.push_back(j);
                }
                if (seen_primes.count(currentPrime / j)) {
                    uniquePrimes.push_back(currentPrime / j);
                }
            }
        }
        if (uniquePrimes.size() == 0) {
            seen_primes.insert(currentPrime);
            uniquePrimes.push_back(currentPrime);
        }
    }
}

int main(void) {
    double totalTime = 0;
    for (int i = 0; i < 5; i++) {
        clock_t start = clock();
        prime();
        totalTime +=  (clock() - start);
    }
    std::cout << "Average execution time after 5 runs: " << totalTime / 5 / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}