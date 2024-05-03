#include <music.h>

#include <iostream>
#include <SDL3/SDL.h>


namespace MUS {
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