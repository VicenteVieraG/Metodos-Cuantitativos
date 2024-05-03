#include <iostream>
#include <random>
#include <chrono>
#include <array>
#include <SDL3/SDL.h>

#include <music.h>

namespace MUS {
    void generateNote(){
        // Create the Markov chain
        // Notes:
        // C C# D D# E F F# G G# A A# B
        // const short MARKOV_CHAIN[12][12] = {
        //     {}
        // };
        // Set the generator and distribution
        const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(1, 12);
    }

    int compose(){
        if(SDL_Init(SDL_INIT_AUDIO) != 0){
            std::cerr<<SDL_GetError()<<std::endl;
            return 1;
        }

        std::cout<<"HELLO SDL3"<<std::endl;
        SDL_Quit();

        return 0;
    }
};