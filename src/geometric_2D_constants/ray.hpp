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
        Ray(const Point& startPos, const radian& angle): startPos(startPos), angle(angle) {}
        Ray(const Point& startPos, const double angle): startPos(startPos), angle(angle) {}
    
        // Создать луч с начальными координатами и поворотом
        Ray(const double x, const double y, const radian& angle): startPos(x, y), angle(angle) {}
        Ray(const double x, const double y, const double angle): startPos(x, y), angle(angle) {}
    
        // ### GET ###
    
        Point getStartPos() const { return startPos; }
    
        // Возвращает угол поворота луча относительно абсциссы (в радианах)
        radian getAngle() const { return angle; }


        // ### SET ###

        Ray& setStartPos(const Point& startPos) {
            this->startPos = startPos;
            return *this;
        }
        Ray& setStartPos(const double x, const double y) {
            startPos(x, y);
            return *this;
        }

        Ray& setAngle(const double angle) {
            this->angle = angle;
            return *this;
        }
        Ray& setAngle(const radian& angle) {
            this->angle = angle;
            return *this;
        }

        
        // ### operator ###
    
        Ray& operator=(const Ray& other) {
            this->startPos = other.startPos;
            this->angle = other.angle;
            return *this;
        }
    
        Ray& operator()(const Ray& other) {
            this->startPos = other.startPos;
            this->angle = other.angle;
            return *this;
        }
    
        Ray& operator()(const Point& startPos, const radian& angle) {
            this->startPos = startPos;
            this->angle = angle;
            return *this;
        }
        Ray& operator()(const Point& startPos, const double angle) {
            this->startPos = startPos;
            this->angle = angle;
            return *this;
        }
    
        Ray& operator()(const double x, const double y, const double angle) {
            this->startPos(x, y);
            this->angle = angle;
            return *this;
        }

        Ray& operator()(const double x, const double y, const radian& angle) {
            this->startPos(x, y);
            this->angle = angle;
            return *this;
        }
};    