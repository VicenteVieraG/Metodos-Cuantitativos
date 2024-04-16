#ifndef RAND_H
#define RAND_H

#include <vector>

namespace randy {
    void middleSquare(unsigned long int randNum, unsigned long long seed, unsigned int digits);
    std::vector<unsigned long long> GLC(const unsigned long long seed, unsigned int randNum);
};

#endif