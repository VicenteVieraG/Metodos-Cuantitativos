#include <iostream>
#include <vector>
#include <cmath>

namespace randy {
    /* 
        @brief This function creates randNum times random numbers using the Middle-Square method created by Von Neuman.
        @param randNum Number of random numbers to be generated.
        @param seed Number taken as a seed for the generation process.
        @param digits Number of digits to take from the middle.
    */
    void middleSquare(unsigned long int randNum, unsigned long long seed, unsigned int digits){
        // Apply left and right shift to get the middle number
        unsigned long int shift = 0;

        // Digits of the current seed
        unsigned long int totalDigits = 0;

        do{
            seed *= seed;

            totalDigits = static_cast<unsigned long int>(std::log10(seed));
            shift = (totalDigits - digits) / 2;

            seed = (seed / static_cast<unsigned long long>(std::pow(10, shift))) %
                    static_cast<unsigned long long>(std::pow(10, digits));

            randNum--;
            std::cout<<randNum+1<<". "<<seed<<std::endl;
        }while(randNum != 0 && seed != 0);
    }

    /* 
        @brief Lineal Congruential Generator (Generador lineal congruencial) algorithm implementation. The chosen parmeter values are taken from the book "Numerical Recipes".
        @param Seed used to start generating random numbers.
        @param randNum Amount of random number generated.
    */
    std::vector<unsigned long long> GLC(const unsigned long long seed, unsigned int randNum){
        const unsigned int m = 0xFFFFFFFF; // 2^32 - 1
        const unsigned int a = 1664525;
        const unsigned int c = 1013904223;

        std::vector<unsigned long long> numbers(randNum, 0);

        // Calculation
        unsigned long long X_i = seed;
        do{
            X_i = (a * X_i + c) & m;
            numbers[randNum - 1] = X_i;            
        }while(--randNum != 0);

        return numbers;
    }
};