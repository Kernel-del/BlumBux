#include <iostream>
#include "src/geometric_2D_constants/import_lib.hpp"
#include "src/geometric_2D_constants/graphics/graphics.cpp"


int main() {
    Graphics g_engine("New project", 1000, 1000);
    bool running = true;

    Ray b(0, 0, 0);
    Circle a(20, 0, 10);

    double fov_player = 120;
    double step = 0.2;

    int x, y; // Корды курсора
    double real_fov = fov_player*M_PI/180;
    while (running){
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_a) {
                    b.setAngle(b.getAngle()-0.02);
                }
                if (event.key.keysym.sym == SDLK_d) {
                    b.setAngle(b.getAngle()+0.02);
                }
                if (event.key.keysym.sym == SDLK_w) {
                    std::cout<<"Нажата w!\n";
                    b.setStartPos(b.getStartPos().getX()+std::cos(b.getAngle().get())*step, b.getStartPos().getY()+std::sin(b.getAngle().get())*step);
                }
                if (event.key.keysym.sym == SDLK_s) {
                    std::cout<<"Нажата w!\n";
                    b.setStartPos(b.getStartPos().getX()-std::cos(b.getAngle().get())*step, b.getStartPos().getY()-std::sin(b.getAngle().get())*step);
                }
            }
        }

        g_engine.set_color(0, 0, 0, 0);
        g_engine.clear();
        
        
        for (int i = 0; i < g_engine.getScreenWidth(); ++i) {
            Ray pixel(b);
            double angle_offset = -real_fov / 2.0 + real_fov * i / g_engine.getScreenWidth();
            pixel.setAngle(b.getAngle() + angle_offset);
        
            std::vector<Point> points = func::getIntersectionPoint(pixel, a);
            
            if (!points.empty()) {
                double raw_distance = func::getDistanceToPoint(b.getStartPos(), points[0]);
                double corrected_distance = raw_distance * cos(angle_offset * M_PI / 180.0); // Учитываем градусы
                
                if (corrected_distance > 0) {
                    double len = g_engine.getScreenHeight() / (2.0 * corrected_distance);
                    
                    int brightness = std::max(0, std::min(255, static_cast<int>(255.0 / corrected_distance)));
                    g_engine.set_color(brightness);
                    
                    g_engine.draw_line(Point(i, g_engine.getScreenHeight() / 2 - len),
                                       Point(i, g_engine.getScreenHeight() / 2 + len));
                }
            }
        }
        
        g_engine.render();
        
    }
    g_engine.quit();
    return 0;
}