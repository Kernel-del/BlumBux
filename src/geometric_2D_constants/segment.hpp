#pragma once
#include "import_lib.hpp"


class Segment {
    private:
        Point points[2];
    public:
        // ### ИНИЦИАЛИЗАТОРЫ ###

        // Инициализировать отрезок без придания параметров
        Segment() {}
        // Создать отрезок с точками p1, p2
        Segment(const Point& p1, const Point& p2) {
            points[0]=p1;
            points[1]=p2;
        }
        // Создать отрезок с точками в координатах x1, y1 и x2, y2
        Segment(double x1, double y1, double x2, double y2) {
            points[0]=Point(x1, y1);
            points[1]=Point(x2, y2);
        }


        // ### GET ###

        Point getPosP1() const {return points[0];}

        Point getPosP2() const {return points[1];}

        double getLen() const {return std::sqrt(std::pow(points[0].getX()-points[1].getX(), 2)+std::pow(points[0].getY()-points[1].getY(), 2)); }

        // Выдаёт угол поворота отрезка по отношению к абциссе(в радианах от -1 до 1)
        radian getAngleP1() const {return radian(std::atan2(points[1].getY()-points[0].getY(), points[1].getX()-points[0].getX())); }

        // Выдаёт угол поворота отрезка по отношению к абциссе(в радианах от -1 до 1)
        radian getAngleP2() const {return radian(std::atan2(points[0].getY()-points[1].getY(), points[0].getX()-points[1].getX())); }


        // ### SET ###

        Segment& setPosP1(const Point& posP1) {
            points[0] = posP1;
            return *this;
        }
        Segment& setPosP1(const double x, const double y) {
            points[0] = Point(x, y);
            return *this;
        }

        Segment& setPosP2(const Point& posP2) {
            points[1] = posP2;
            return *this;
        }
        Segment& setPosP2(const double x, const double y) {
            points[1] = Point(x, y);
            return *this;
        }


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

        Segment& operator() (const Point& p1, const Point& p2) {
            points[0]=p1;
            points[1]=p2;

            return *this;
        }

        Segment& operator() (const double x1, const double y1, const double x2, const double y2) {
            points[0]=Point(x1, y1);
            points[1]=Point(x2, y2);

            return *this;
        }

        Point operator[] (unsigned int index) const {
            return points[index];
        }
};