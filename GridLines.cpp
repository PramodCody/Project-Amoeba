#include "Line.h"
#include <SDL3/SDL.h>

//Defining Line Class
extern SDL_Window* window;
extern SDL_Renderer* renderer;

Line::Line() : x1(0), y1(0), x2(0), y2(0) {}

void Line::draw_line(int a1, int b1, int a2, int b2) {
	x1 = a1;
	y1 = b1;
	x2 = a2;
	y2 = b2;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderLine(renderer, x1, y1, x2, y2);

}

// Creating Line Objects
Line L1, L2, L3;


// For Initial Lines
void InitialBG() {
    extern int w, h;
    int a = w / 4;

    L1.draw_line(a, 0, a, h);
    L2.draw_line(2 * a, 0, 2 * a, h);
    L3.draw_line(3 * a, 0, 3 * a, h);

}

//void ResizedWindow() {
//    extern int x, y;
//    int w = x;
//    int h = y;
//    int a = w / 4;
//
//    L1.draw_line(a, 0, a, h);
//    L2.draw_line(2 * a, 0, 2 * a, h);
//    L3.draw_line(3 * a, 0, 3 * a, h);
//}

//TO Update Line Coordinates
void UpdateGrid() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    L1.draw_line(L1.x1, L1.y1, L1.x2, L1.y2);
    L2.draw_line(L2.x1, L2.y1, L2.x2, L2.y2);
    L3.draw_line(L3.x1, L3.y1, L3.x2, L3.y2);

    SDL_RenderPresent(renderer);
}

//Move GridLines
void MoveRight(int m) {
    L1.x1 -= m;
    L2.x1 -= m;
    L3.x1 -= m;

    L1.x2 -= m;
    L2.x2 -= m;
    L3.x2 -= m;
}