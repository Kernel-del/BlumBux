#pragma once
#include "import_lib.hpp"
#include <cmath>

class Circle : public Point {
private:
    double radius;
public:
    // ### ИНИЦИАЛИЗАТОРЫ ###

    // Инициализировать круг без задания параметров
    Circle() : Point(), radius(0) {}
    // Создать круг с начальными координатами и радиусом
    Circle(const Point& centerPos, double radius) : Point(centerPos), radius(radius) {}
    Circle(double x, double y, double radius) : Point(x, y), radius(radius) {}

    // ### GET ###

    Point getCenterPos() const { return static_cast<const Point&>(*this); }
    double getRadius() const { return radius; }
    double getDiameter() const { return radius * 2; }
    double getPerimeter() const { return 2 * M_PI * radius; }
    double getArea() const { return M_PI * std::pow(radius, 2); }

    // ### SET ###

    Circle& setCenterPos(const Point& centerPos) {
        set(centerPos);
        return *this;
    }
    Circle& setCenterPos(double x, double y) {
        set(x, y);
        return *this;
    }

    Circle& setRadius(double radius) {
        this->radius = radius;
        return *this;
    }

    // ### operator ###

    Circle& operator=(const Circle& other) {
        if (this != &other) {
            set(other);
            radius = other.radius;
        }
        return *this;
    }

    Circle& operator()(const Circle& other) {
        set(other);
        radius = other.radius;
        return *this;
    }

    Circle& operator()(const Point& centerPos, double radius) {
        set(centerPos);
        this->radius = radius;
        return *this;
    }

    Circle& operator()(double x, double y, double radius) {
        set(x, y);
        this->radius = radius;
        return *this;
    }
};