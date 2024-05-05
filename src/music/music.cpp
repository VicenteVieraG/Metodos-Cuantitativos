#include <iostream>
#include <string>
#include <utility>
#include <random>
#include <chrono>

#include <SDL3/SDL.h>

#include <music.h>

namespace MUS {
    // Create the Markov chain
    const std::pair<unsigned int, unsigned int> MARKOV_CHAIN[12][12] = {
        // C        C#        D        D#        E         F         F#         G        G#         A        A#         B
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q0
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q1
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q2
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q3
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q4
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q5
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q6
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q7
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q8
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q9
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q10
        {{0, 5}, {6, 20}, {21, 30}, {31, 33}, {34, 44}, {45, 46}, {47, 67}, {68, 78}, {79, 80}, {81, 90}, {91, 92}, {93, 100}}, // q11
    };

    std::string* generateNote(const unsigned int notesNumber){
        // Set the generator and distribution
        const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(0, 100);

        // Fill the roulette with notes
        unsigned int* roulette = new unsigned int[notesNumber];
        for(int i = 0;i < notesNumber;i++) roulette[i] = distribution(generator);

        // Fill the notes array
        const unsigned int NOTES_NUMBER = 12;
        unsigned int state = 0;
        std::string* notes = new std::string[notesNumber];

        for(unsigned int i = 0;i < notesNumber;i++){
            // Traverse Markov Chain
            for(unsigned int j = 0;j < NOTES_NUMBER;j++){
                if(MARKOV_CHAIN[state][j].first <= roulette[i] && MARKOV_CHAIN[state][j].second >= roulette[i]){
                    // Set new state and add the corresponding key
                    state = j;
                    switch(state){
                        case 0: notes[i] = "C";break;
                        case 1: notes[i] = "C#";break;
                        case 2: notes[i] = "D";break;
                        case 3: notes[i] = "D#";break;
                        case 4: notes[i] = "E";break;
                        case 5: notes[i] = "F";break;
                        case 6: notes[i] = "F#";break;
                        case 7: notes[i] = "G";break;
                        case 8: notes[i] = "G#";break;
                        case 9: notes[i] = "A";break;
                        case 10: notes[i] = "A#";break;
                        case 11: notes[i] = "B";break;
                    }
                    break;
                }
            }
        }
        delete[] roulette;

        return notes;
    }

    int compose(){
        if(SDL_Init(SDL_INIT_AUDIO) != 0){
            std::cerr<<SDL_GetError()<<std::endl;
            return 1;
        }

        const unsigned int NOTES_NUMBER = 100;
        const std::string* NOTES = generateNote(NOTES_NUMBER);
        for(unsigned int i = 0;i < NOTES_NUMBER;i++) std::cout<<NOTES[i]<<std::endl;

        SDL_Quit();

        return 0;
    }
};