#include <iostream>
#include <vector>
#include <ctime>

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

int main(void) {
    double totalTime = 0;
    for (int i = 0; i < 5; i++) {
        clock_t start = clock();
        prime();
        totalTime += (double) (clock() - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Average execution time after 5 runs: " << totalTime / 5 << " seconds\n";
    return 0;
}