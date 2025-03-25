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

        double getX() const {return x;}

        double getY() const {return y;}


        // ### SET ###

        Point& setX(const double x) {
            this->x = x;
            return *this;
        }
        Point& setX(const Point& other) {
            this->x = other.x;
            return *this;
        }

        Point& setY(const double y) {
            this->y = y;
            return *this;
        }
        Point& setY(const Point& other) {
            this->y = other.y;
            return *this;
        }

        Point& set(const double x, const double y) {
            this->y = y;
            return *this;
        }
        Point& set(const Point& other) {
            x = other.x;
            y = other.y;
            return *this;
        }


        // ### operator ###

        Point operator+(const Point& other) const {
            return Point(x + other.x, y + other.y);
        }
        Point operator-(const Point& other) const {
            return Point(x - other.x, y - other.y);
        }
        Point operator*(const Point& other) const {
            return Point(x * other.x, y * other.y);
        }
        Point operator*(double other) const {
            return Point(x * other, y * other);
        }
        Point operator/(const Point& other) const {
            return Point(x / other.x, y / other.y);
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
            x = other.x; y = other.y;
            return *this;
        }

        Point& operator() (double x, double y) {
            this->x = x; this->y = y;
            return *this;
        }
};


std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.getX() << "; " << p.getY() << ")";
    return os;
}