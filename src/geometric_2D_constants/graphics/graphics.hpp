#pragma once
#include "../import_lib.hpp"
#include "color.hpp"
#include <SDL2/SDL.h>

class Graphics {
    private:
        SDL_Window *win;
        SDL_Renderer *ren;
        SDL_DisplayMode DM;
    public:
        Graphics() {}
        Graphics(const char* title, size_t x, size_t y) {
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
                std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
                throw 1;
            }
            win = SDL_CreateWindow(title, x, y, 640, 480, SDL_WINDOW_SHOWN);
            if (win == nullptr){
                std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
                throw 1;
            }
            ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (ren == nullptr){
                std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
                throw 1;
            }
            if (SDL_GetHint(SDL_HINT_RENDER_VSYNC)) {
                std::cout << "V-Sync включен!" << std::endl;
            } else {
                std::cout << "V-Sync выключен!" << std::endl;
            }
            

            SDL_SetWindowResizable(win, SDL_TRUE); // Изменяемость экрана
            SDL_GetCurrentDisplayMode(0, &DM);
        }


        void set_color(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a) {
            SDL_SetRenderDrawColor(ren, r, g, b, a);
        }
        void set_color(u_int8_t w) {
            SDL_SetRenderDrawColor(ren, w, w, w, 255);
        }
        void set_fullscrean(bool select) {
            SDL_SetWindowFullscreen(win, select);
        }
        
        void clear() {
            SDL_RenderClear(ren);
        }

        void draw_line(u_int32_t x1, u_int32_t y1, u_int32_t x2, u_int32_t y2) {
            SDL_RenderDrawLine(ren, x1, y1, x2, y2);
        }
        void draw_line(const Point& a, const Point& b) {
            SDL_RenderDrawLine(ren, a.getX(), a.getY(), b.getX(), b.getY());
        }

        void draw_triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color c) {
            SDL_Vertex vertices[3] = {
                {{x1, y1}, {c.r, c.g, c.b, c.a}},
                {{x2, y2}, {c.r, c.g, c.b, c.a}},
                {{x3, y3}, {c.r, c.g, c.b, c.a}},
            };
            SDL_RenderGeometry(ren, NULL, vertices, 3, NULL, 0);
        }
        void draw_triangle(Point p1, Point p2, Point p3, Color c) {
            SDL_Vertex vertices[3] = {
                {{static_cast<float>(p1.getX()), static_cast<float>(p1.getY())}, {c.r, c.g, c.b, c.a}},
                {{static_cast<float>(p2.getX()), static_cast<float>(p2.getY())}, {c.r, c.g, c.b, c.a}},
                {{static_cast<float>(p3.getX()), static_cast<float>(p3.getY())}, {c.r, c.g, c.b, c.a}},
            };
            SDL_RenderGeometry(ren, NULL, vertices, 3, NULL, 0);
        }

        void sleep(u_int32_t ms) {
            SDL_Delay(ms);
        }

        void render() {
            SDL_RenderPresent(ren);

        }


        int getScreenWidth() {
            return DM.w;
        }
        int getScreenHeight() {
            return DM.h;
        }


        void setMousePos(int x, int y) {
            SDL_WarpMouseInWindow(win, x, y);
        }


        void quit() {
            SDL_DestroyWindow(win);
            win = NULL;
        
            SDL_DestroyRenderer(ren);
            ren = NULL;

            SDL_Quit();
        }


        void operator () (const char* title, size_t x, size_t y) {
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
                std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
                throw 1;
            }
            win = SDL_CreateWindow(title, x, y, 640, 480, SDL_WINDOW_SHOWN);
            if (win == nullptr){
                std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
                throw 1;
            }
            ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (ren == nullptr){
                std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
                throw 1;
            }
            if (SDL_GetHint(SDL_HINT_RENDER_VSYNC)) {
                std::cout << "V-Sync включен!" << std::endl;
            } else {
                std::cout << "V-Sync выключен!" << std::endl;
            }
            

            SDL_SetWindowResizable(win, SDL_TRUE); // Изменяемость экрана
            SDL_GetCurrentDisplayMode(0, &DM);
        }

        ~Graphics() {
            quit();
        }
};