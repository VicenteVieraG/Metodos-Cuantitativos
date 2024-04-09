#include <iostream>
#include <bitset>

// Implementation of the Middle Squared method with a seed size of 6 digits.
// The seed must be even in order to find an evenly distributed 6 digit number.
void middleSquare(unsigned long int seed);

int main(int argc, char** argv){
    std::cout<<"ADIOS MUNDO"<<std::endl;
    
    return 0;
}

void middleSquare(unsigned long int seed){
    std::bitset<64> N(seed);
    seed *= seed;

}