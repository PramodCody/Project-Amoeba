#include <SDL3/SDL.h>
#include <iostream>
#include "Line.h"

using namespace std;
void InitialBG();
void Show_Background();
void MoveRight(int m);

//Creating Window and Renderer
int w = 800, h = 600;
SDL_Window* window = SDL_CreateWindow("Project-Amoeba", w, h, SDL_WINDOW_RESIZABLE);
SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);


int main(int argc, char* argv[]) {
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

    InitialBG();
    Show_Background();
    
    //Keep Running
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

                case SDL_EVENT_QUIT:
                    running = false;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_RIGHT) {
                        //To Set Background white so, previous lines disappeares
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        SDL_RenderClear(renderer);

                        MoveRight(5);
                        Show_Background();
                        break;
                    }

                SDL_Delay(16); // ~60 FPS

            }
        }
    }

    //Ending Code
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}