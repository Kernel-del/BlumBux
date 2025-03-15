#pragma once
#include "import_lib.hpp"

namespace func {
    Point getIntersectionPoint(Ray a, Ray b) {
        double x1 = a.getStartPos().getX(), y1 = a.getStartPos().getY();
        double x2 = b.getStartPos().getX(), y2 = b.getStartPos().getY();
        double theta1 = a.getAngle().d(), theta2 = b.getAngle().d();

        double sin_theta1 = std::sin(theta1), cos_theta1 = std::cos(theta1);
        double sin_theta2 = std::sin(theta2), cos_theta2 = std::cos(theta2);

        double dx = x2 - x1, dy = y2 - y1;
        double denominator = sin_theta2 * cos_theta1 - cos_theta2 * sin_theta1;

        if (std::fabs(denominator) < 1e-9) return Point(NAN, NAN); // Параллельные лучи

        double t = (dx * sin_theta2 - dy * cos_theta2) / denominator;
        if (t < 0) return Point(NAN, NAN); // Пересечение "позади" первого луча

        return Point(x1 + t * cos_theta1, y1 + t * sin_theta1);
    }

    Point getIntersectionPoint(Ray a, Segment b) {
        double x1 = a.getStartPos().getX(), y1 = a.getStartPos().getY();
        double dx1 = std::cos(a.getAngle().d()), dy1 = std::sin(a.getAngle().d());
        double x3 = b.getPosP1().getX(), y3 = b.getPosP1().getY();
        double x4 = b.getPosP2().getX(), y4 = b.getPosP2().getY();
        
        double dx2 = x4 - x3, dy2 = y4 - y3;
        double denominator = dx1 * dy2 - dy1 * dx2;
        if (std::fabs(denominator) < 1e-9) return Point(NAN, NAN);
        
        double t = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / denominator;
        double u = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / denominator;
        
        return (t >= 0 && u >= 0 && u <= 1) ? Point(x1 + t * dx1, y1 + t * dy1) : Point(NAN, NAN);
    }

    Point getIntersectionPoint(Segment a, Ray b) {
        return getIntersectionPoint(b, a);
    }

    Point getIntersectionPoint(Segment a, Segment b) {
        double x1 = a.getPosP1().getX(), y1 = a.getPosP1().getY();
        double x2 = a.getPosP2().getX(), y2 = a.getPosP2().getY();
        double x3 = b.getPosP1().getX(), y3 = b.getPosP1().getY();
        double x4 = b.getPosP2().getX(), y4 = b.getPosP2().getY();
        
        double dx1 = x2 - x1, dy1 = y2 - y1;
        double dx2 = x4 - x3, dy2 = y4 - y3;
        
        double det = dx1 * dy2 - dy1 * dx2;
        if (std::abs(det) < 1e-9) return Point(NAN, NAN); // Отрезки параллельны или совпадают

        double t = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / det;
        double u = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / det;

        return (t >= 0 && t <= 1 && u >= 0 && u <= 1) ? Point(x1 + t * dx1, y1 + t * dy1) : Point(NAN, NAN);
    }
}