//The Includes
#include <SDL3/SDL.h>
#include <iostream>
#include "line.h"

using namespace std;

//The Functions from GridLines.cpp
void InitialBG();
void ResizedValue();
void UpdateGrid();

//the movements function from GridLines.cpp
void CheckX();
void CheckY();
void MoveRight();
void MoveUp();


//Creating Window and Renderer
int w = 400, h = 300;
SDL_Window* window = SDL_CreateWindow("Project-Amoeba", w, h, SDL_WINDOW_RESIZABLE);
SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);


int main(int argc, char* argv[]) {
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

    //For Initial Grid
    InitialBG();
    UpdateGrid();

    //Keep Running
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

                case SDL_EVENT_WINDOW_RESIZED:
                    w = event.window.data1;
                    h = event.window.data2;
                    InitialBG();
                    ResizedValue();
                    UpdateGrid();
                    break;

                case SDL_EVENT_QUIT:
                    running = false;
                    break;


                //The Movements wrt Amoeba
 
                case SDL_EVENT_KEY_DOWN:
                    
                    if (event.key.key == SDLK_RIGHT) {
                        CheckX();
                        MoveRight();
                        UpdateGrid();
                        break;
                    }

                    if (event.key.key == SDLK_UP) {
                        CheckY();
                        MoveUp();
                        UpdateGrid();
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