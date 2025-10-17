#include <SDL3/SDL.h>
#include <iostream>
using namespace std;

//Setting Global Values
int w = 800, h = 600;
SDL_Window* window = SDL_CreateWindow("Project-Amoeba", w, h, SDL_WINDOW_RESIZABLE);
SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

class Line {
public:
    int x1, y1, x2, y2;

    void draw_line(int a1, int b1, int a2, int b2) {
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 50);
        SDL_RenderLine(renderer, x1, y1, x2, y2);   
    }
};



int main(int argc, char* argv[]) {
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }
    int a = w / 4;
    Line L1;
    L1.draw_line(a, 0, a, h);

    Line L2;
    L2.draw_line(2 * a, 0, 2 * a, h);

    Line L3;
    L3.draw_line(3 * a, 0, 3 * a, h);


    SDL_RenderPresent(renderer);
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
						printf("Right Arrow Pressed\n");

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