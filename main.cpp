#include <SDL3/SDL.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	// Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        cerr << "SDL could not initialize: " << SDL_GetError() << endl;
        return 1;
    }

    //Setting Global Values
	int w = 800, h = 600;

	// Create a window
    SDL_Window* window = SDL_CreateWindow("Project-Amoeba", w, h, SDL_WINDOW_RESIZABLE);

	// Check if window was created successfully
    if (!window) {
        std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }




	// Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	//For Opacity Control
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	//Set renderer Draw Color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 50);
	//Creating Lines
	int nw = 10; // Number of Horizental lines
    for (int i = 0; i < nw; i++) {
        SDL_RenderLine(renderer, (i + 1) * w / (nw + 1), 0, (i + 1) * w / (nw + 1), h);
    }
	int nh = 8;  // Number of Vertical lines
    for (int i = 0; i < nh; i++) {
        SDL_RenderLine(renderer, 0, (i + 1) * h / (nh + 1), w, (i + 1) * h / (nh + 1));
    }



	//Show the Drawing on the Window
    SDL_RenderPresent(renderer);




    //Keep Running
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        SDL_Delay(16); // ~60 FPS
    }

    //Ending Code
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
