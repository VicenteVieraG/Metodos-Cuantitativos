#include <iostream>
#include <vector>

#include <rand.h>

namespace hist_plot {
    void plotHist(){
        const unsigned int NUMBERS = 20;
        const unsigned long long SEED = 1;

        const std::vector<unsigned long long> X = randy::GLC(SEED, NUMBERS);

        for(auto num : X) std::cout<<num<<std::endl;
    }
};