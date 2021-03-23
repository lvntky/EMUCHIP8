#include <stdio.h>
#include "D:\GitHub\EMUCHIP8\include\SDL2\SDL.h" //SDL.h
#include "D:\GitHub\EMUCHIP8\include\chip8.h" //chip8.h

int main(int argc, char** argv)
{   
    struct chip8 chip8; //creating a chip8 struct variable
    //tiny memory implementation here
    chip8_memory_set(&chip8.memory, 0x400, 'L');
    printf("%c\n", chip8_memory_get(&chip8.memory, 50));

    SDL_Init(SDL_INIT_EVERYTHING); 
    SDL_Window* window = SDL_CreateWindow(
        CHIP8_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER,
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    while (1){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                goto out;
            }
            
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_Rect r;
        r.x = 0;
        r.y = 0;
        r.h = 40;
        r.w = 40;
        SDL_RenderFillRect(renderer, &r);
        SDL_RenderPresent(renderer);
    }
     
out:
    SDL_DestroyWindow(window);
    return 0;
}