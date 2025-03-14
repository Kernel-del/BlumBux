#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <math.h>

double round_radian(double angle) {
    return std::remainder(angle, 2 * M_PI);
}

class radian {
    private:
        double angle;
    public:
        radian() {};
        radian(double angle) {
            this->angle = round_radian(angle);
        }
        
        radian operator+(const radian& other) {
            return radian(angle+other.angle);
        }
        radian operator+(const double other) {
            return round_radian(angle+other);
        }

        radian operator-(const radian& other) {
            return radian(angle-other.angle);
        }
        radian operator-(const double other) {
            return round_radian(angle-other);
        }

        radian operator*(const radian& other) {
            return radian(angle*other.angle);
        }
        radian operator*(const double other) {
            return round_radian(angle*other);
        }

        radian operator/(const radian& other) {
            return radian(angle*other.angle);
        }
        radian operator/(const double other) {
            return round_radian(angle/other);
        }

        radian& operator+=(const radian& other) {
            angle = round(angle+other.angle);
            return *this;
        }
        radian& operator+=(const double other) {
            angle = round_radian(angle+other);
            return *this;
        }

        radian& operator-=(const radian& other) {
            angle = round_radian(angle-other.angle);
            return *this;
        }
        radian& operator-=(const double other) {
            angle = round_radian(angle-other);
            return *this;
        }

        radian& operator*=(const radian& other) {
            angle = round_radian(angle*other.angle);
            return *this;
        }
        radian& operator*=(const double other) {
            angle = round_radian(angle*other);
            return *this;
        }

        radian& operator/=(const radian& other) {
            angle = round_radian(angle/other.angle);
            return *this;
        }
        radian& operator/=(const double other) {
            angle = round_radian(angle/other);
            return *this;
        }
};


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
            return Point(x*other.x, y*other.y);
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
            this->x = x;
            this->y = y;
            return *this;
        }
};

class Segment {
    private:
        Point points[2];
    public:
        // ### ИНИЦИАЛИЗАТОРЫ ###

        // Инициализировать отрезок без придания параметров
        Segment() {}
        // Создать отрезок с точками p1, p2
        Segment(Point p1, Point p2) {
            points[0]=p1;
            points[1]=p2;
        }
        // Создать отрезок с точками в координатах x1, y1 и x2, y2
        Segment(double x1, double y1, double x2, double y2) {
            points[0]=Point(x1, y1);
            points[1]=Point(x2, y2);
        }


        // ### GET ###

        Point& getPosP1() {return points[0];}

        Point& getPosP2() {return points[1];}

        double getLen() {return std::sqrt(std::pow(points[0].getX()-points[1].getX(), 2)+std::pow(points[0].getY()-points[1].getY(), 2)); }

        // Выдаёт угол поворота отрезка по отношению к абциссе(в радианах от -1 до 1)
        double getAngleP1() {return round_radian(std::atan2(points[1].getY()-points[0].getY(), points[1].getX()-points[0].getX())); }

        // Выдаёт угол поворота отрезка по отношению к абциссе(в радианах от -1 до 1)
        double getAngleP2() {return round_radian(std::atan2(points[0].getY()-points[1].getY(), points[0].getX()-points[1].getX())); }


        // ### operator ###

        Segment& operator=(const Segment& other) {
            for (int i = 0; i < 2; ++i) {
                points[i] = other.points[i];
            }
            return *this;
        }

        Segment& operator() (const Segment& other) {
            for (int i = 0; i < 2; ++i) {
                points[i] = other.points[i];
            }
            return *this;
        }

        Segment& operator() (Point p1, Point p2) {
            points[0]=p1;
            points[1]=p2;

            return *this;
        }

        Segment& operator() (double x1, double y1, double x2, double y2) {
            points[0]=Point(x1, y1);
            points[1]=Point(x2, y2);

            return *this;
        }

        Point& operator[] (unsigned int index) {
            return points[index];
        }
};

class Beam {

};



class figure {
    private:
        
    public:
        figure() {};
};