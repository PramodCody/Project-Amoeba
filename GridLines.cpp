#include "line.h"
#include <SDL3/SDL.h>
#include <iostream>

//To Calculate The GridLines Position
int countR = 0;
int countU = 0;
int m = 5; //movement speed

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

//vertical lines
int nv = 8;
Line Lv[8];

//horizental lines
int nh = 6;
Line Lh[6];


// For Initial Lines
void InitialBG() {
    extern int w, h;

    int a = w / (nv+1);
    //vertical lines
    for (int i = 0; i < nv; i++) {
        Lv[i].draw_line((i + 1) * a, 0, (i + 1) * a, h);
    }

    int b = h / (nh + 1);
    //horizental lines
    for (int i = 0; i < nh; i++) {
        Lh[i].draw_line(0, (i + 1) * b, w, (i + 1) * b);
    }
}


//Resized Lines New Position Calculation
void ResizedValue() {

    //vertical lines
    for (int i = 0; i < nv; i++) {
        Lv[i].x1 -= countR * m;
        Lv[i].x2 -= countR * m;
    }

    //horizental lines
    for (int i = 0; i < nv; i++) {
        Lh[i].y1 += countU * m;
        Lh[i].y2 += countU * m;
    }
}

//TO Update Line Coordinates
void UpdateGrid() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //vertical lines
    for (int i = 0; i < nv; i++) {
        Lv[i].draw_line(Lv[i].x1, Lv[i].y1, Lv[i].x2, Lv[i].y2);
    }

    //horizental lines
    for (int i = 0; i < nh; i++) {
        Lh[i].draw_line(Lh[i].x1, Lh[i].y1, Lh[i].x2, Lh[i].y2);
    }

    SDL_RenderPresent(renderer);
}

//Move GridLines in different direction

void MoveRight() {
    countR += 1;

    for (int i = 0; i < nv; i++) {
        Lv[i].x1 -= m;
        Lv[i].x2 -= m;
    }
}

void MoveUp() {
    countU += 1;

    for (int i = 0; i < nv; i++) {
        Lh[i].y1 += m;
        Lh[i].y2 += m;
    }
}