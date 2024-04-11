#include <iostream>
#include <cmath>

namespace randy {
    /* 
        @brief This function creates randNum times random numbers using the Middle-Square method created by Von Neuman.
        @param randNum Number of random numbers to be generated.
        @param seed Number taken as a seed for the generation process.
        @param digits Number of digits to take from the middle.
    */
    void middleSquare(unsigned long int randNum, unsigned long long seed, unsigned int digits){
        seed *= seed;

        // Apply left and right shift to get the middle number
        unsigned long int shift = 0;

        // Digits of the current seed
        unsigned long int totalDigits = 0;

        do{
            std::cout<<seed<<" || "<<randNum<<" || "<<sizeof(seed)<<std::endl;

            // Get the total number of digits
            totalDigits = static_cast<unsigned long int>(std::log10(seed));

            shift = (totalDigits - digits) / 2;
            seed = (seed / static_cast<unsigned int>(std::pow(10, shift))) %
                    static_cast<unsigned int>(std::pow(10, digits));

            randNum--;
        }while(randNum != 0);
    }
};