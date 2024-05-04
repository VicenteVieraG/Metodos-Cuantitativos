#include <iostream>
#include <random>
#include <chrono>
#include <array>
#include <SDL3/SDL.h>

#include <music.h>

namespace MUS {
    unsigned int* generateNote(const unsigned int notesNumber){
        // Create the Markov chain
        // Notes:
        // C C# D D# E F F# G G# A A# B
        const short MARKOV_CHAIN[12][12] = {
            {}
        };
        // Set the generator and distribution
        const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(1, 12);

        // Fill the array with notes
        unsigned int* notes = new unsigned int[notesNumber];
        for(int i = 0;i < notesNumber;i++) notes[i] = distribution(generator);

        return notes;
    }

    int compose(){
        if(SDL_Init(SDL_INIT_AUDIO) != 0){
            std::cerr<<SDL_GetError()<<std::endl;
            return 1;
        }

        // Generate the notes
        const unsigned int NOTES_NUMBER = 100;
        const unsigned int* NOTES = generateNote(NOTES_NUMBER);

        for(int i = 0;i < NOTES_NUMBER;i++){
            switch(NOTES[i]){
                case 1:
                    std::cout<<"C"<<std::endl;
                    break;
                case 2:
                    std::cout<<"C#"<<std::endl;
                    break;
                case 3:
                    std::cout<<"D"<<std::endl;
                    break;
                case 4:
                    std::cout<<"D#"<<std::endl;
                    break;
                case 5:
                    std::cout<<"E"<<std::endl;
                    break;
                case 6:
                    std::cout<<"F"<<std::endl;
                    break;
                case 7:
                    std::cout<<"F#"<<std::endl;
                    break;
                case 8:
                    std::cout<<"G"<<std::endl;
                    break;
                case 9:
                    std::cout<<"G#"<<std::endl;
                    break;
                case 10:
                    std::cout<<"A"<<std::endl;
                    break;
                case 11:
                    std::cout<<"A#"<<std::endl;
                    break;
                case 12:
                    std::cout<<"B"<<std::endl;
                    break;
            }
        }

        std::cout<<"HELLO SDL3"<<std::endl;
        SDL_Quit();

        return 0;
    }
};