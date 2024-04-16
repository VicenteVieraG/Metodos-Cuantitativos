#include <iostream>
#include <vector>
#include <sciplot/sciplot.hpp>

#include <rand.h>

int main(int argc, char** argv){
    const unsigned int NUMBERS = 10;
    const unsigned long long SEED = 1;
    sciplot::Plot2D p;
    
    std::vector<unsigned long long> X = randy::GLC(SEED, NUMBERS);

    p.drawHistogram(X);

    const sciplot::Figure fig = {{p}};
    const sciplot::Canvas canvas = {{fig}};

    canvas.show();

    // for(unsigned long long data : X){
    //     std::cout<<data<<std::endl;
    // }

    return 0;
}