#include <SDL3/SDL.h>
#include <iostream>
using namespace std;

//Setting Global Values
int w = 800, h = 600;
int a = w / 4;
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
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderLine(renderer, x1, y1, x2, y2);
    }
};

Line L1, L2, L3;

void Show_Background() {
    L1.draw_line(L1.x1, L1.y1, L1.x2, L1.y2);
    L2.draw_line(L2.x1, L2.y1, L2.x2, L2.y2);
    L3.draw_line(L3.x1, L3.y1, L3.x2, L3.y2);

    SDL_RenderPresent(renderer);
}

void MoveRight(int m) {
    L1.x1 -= m;
    L2.x1 -= m;
    L3.x1 -= m;

    L1.x2 -= m;
    L2.x2 -= m;
    L3.x2 -= m;
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

    L1.draw_line(a, 0, a, h);
    L2.draw_line(2 * a, 0, 2 * a, h);
    L3.draw_line(3 * a, 0, 3 * a, h);

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