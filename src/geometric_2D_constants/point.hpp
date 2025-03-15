#pragma once
#include "import_lib.hpp"

class Point {
    private:
        double x;
        double y;
    public:
        // ### ИНИЦИАЛИЗАТОРЫ ###

        // Инициализировать точку без придания параметров
        Point() {}
        // Создать точку
        Point(double x, double y): x(x), y(y) {}
        Point(const Point& other): x(other.x), y(other.y) {}
        

        // ### GET ###

        double& getX() {return x;}

        double& getY() {return y;}


        // ### operator ###

        Point operator+(const Point& other) {
            return Point(x+other.x, y+other.y);
        }

        Point operator-(const Point& other) {
            return Point(x-other.x, y-other.y);
        }

        Point operator*(const Point& other) {
            return Point(x*other.x, y*other.y);
        }

        Point operator/(const Point& other) {
            return Point(x/other.x, y/other.y);
        }

        Point& operator+=(const Point& other) {
            x += other.x; y += other.y;
            return *this;
        }

        Point& operator-=(const Point& other) {
            x -= other.x; y -= other.y;
            return *this;
        }

        Point& operator*=(const Point& other) {
            x *= other.x; y *= other.y;
            return *this;
        }

        Point& operator/=(const Point& other) {
            x /= other.x; y /= other.y;
            return *this;
        }

        Point& operator=(const Point& other) {
            x = other.x; y = other.y;
            return *this;
        }

        Point& operator() (const Point& other) {
            x /= other.x; y /= other.y;
            return *this;
        }

        Point& operator() (double x, double y) {
            this->x = x; this->y = y;
            return *this;
        }
};