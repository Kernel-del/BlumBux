#pragma once
#include "import_lib.hpp"


class Ray {
    private:
        Point startPos;
        radian angle;
    public:
        // ### ИНИЦИАЛИЗАТОРЫ ###
    
        // Инициализировать луч без задания параметров
        Ray() {}
        // Создать луч с начальными координатами и поворотом
        Ray(Point startPos, radian angle) {
            this->startPos = startPos;
            this->angle = angle;
        }
        Ray(Point startPos, double angle) {
            this->startPos = startPos;
            this->angle = angle;
        }
    
        // Создать луч с начальными координатами и поворотом
        Ray(double x, double y, radian angle) {
            startPos = Point(x, y);
            this->angle = angle;
        }
        Ray(double x, double y, double angle) {
            startPos = Point(x, y);
            this->angle = angle;
        }
    
        // ### GET ###
    
        Point& getStartPos() { return startPos; }
    
        // Возвращает угол поворота луча относительно абсциссы (в радианах)
        radian& getAngle() { return angle; }
        
        // ### operator ###
    
        Ray& operator=(const Ray& other) {
            startPos = other.startPos;
            angle = other.angle;
            return *this;
        }
    
        Ray& operator()(const Ray& other) {
            startPos = other.startPos;
            angle = other.angle;
            return *this;
        }
    
        Ray& operator()(Point startPos, radian angle) {
            this->startPos = startPos;
            this->angle = angle;
            return *this;
        }
        Ray& operator()(Point startPos, double angle) {
            this->startPos = startPos;
            this->angle = angle;
            return *this;
        }
    
        Ray& operator()(double x, double y, double angle) {
            startPos = Point(x, y);
            this->angle = angle;
            return *this;
        }
};    