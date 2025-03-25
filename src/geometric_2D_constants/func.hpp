#pragma once
#include "import_lib.hpp"

namespace func {
    // Функция для вычисления точки пересечения двух лучей.
    // Пересечение считается допустимым, если оно находится впереди начала обоих лучей.
    std::vector<Point> getIntersectionPoint(const Ray& a, const Ray& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём

        // Начальные точки лучей a и b.
        double x1 = a.getStartPos().getX();
        double y1 = a.getStartPos().getY();
        double x2 = b.getStartPos().getX();
        double y2 = b.getStartPos().getY();

        // Углы лучей a и b.
        double theta1 = a.getAngle().get();
        double theta2 = b.getAngle().get();

        // Вычисляем синусы и косинусы углов для оптимизации.
        double sin_theta1 = std::sin(theta1);
        double cos_theta1 = std::cos(theta1);
        double sin_theta2 = std::sin(theta2);
        double cos_theta2 = std::cos(theta2);

        // Разница координат между началом лучей.
        double dx = x2 - x1;
        double dy = y2 - y1;

        // Вычисляем знаменатель, определяющий, параллельны ли лучи.
        double denominator = sin_theta2 * cos_theta1 - cos_theta2 * sin_theta1;
        if (std::fabs(denominator) < EPSILON) {
            // Лучи параллельны или почти параллельны.
            return std::vector<Point>(1, Point(NAN, NAN));
        }

        // Вычисляем параметры t и u для лучей a и b соответственно.
        double t = (dx * sin_theta2 - dy * cos_theta2) / denominator;
        double u = (dx * sin_theta1 - dy * cos_theta1) / denominator;

        // Проверяем, что точка пересечения находится впереди начала обоих лучей.
        if (t < 0 || u < 0) {
            return std::vector<Point>(1, Point(NAN, NAN));
        }

        // Возвращаем точку пересечения, смещая начало луча a на t вдоль его направления.
        return std::vector<Point>(1, Point(x1 + t * cos_theta1, y1 + t * sin_theta1));
    }

    // Функция для вычисления точки пересечения луча и отрезка.
    // Пересечение допустимо, если оно находится впереди начала луча и внутри отрезка.
    std::vector<Point> getIntersectionPoint(const Ray& a, const Segment& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём

        // Начальная точка и направление луча a.
        double x1 = a.getStartPos().getX();
        double y1 = a.getStartPos().getY();
        double dx1 = std::cos(a.getAngle().get());
        double dy1 = std::sin(a.getAngle().get());

        // Конечные точки отрезка b.
        double x3 = b.getPosP1().getX();
        double y3 = b.getPosP1().getY();
        double x4 = b.getPosP2().getX();
        double y4 = b.getPosP2().getY();

        // Направление отрезка b.
        double dx2 = x4 - x3;
        double dy2 = y4 - y3;

        // Вычисляем знаменатель параметрической формы.
        double denominator = dx1 * dy2 - dy1 * dx2;
        if (std::fabs(denominator) < EPSILON) {
            // Луч и отрезок параллельны или почти параллельны.
            return std::vector<Point>(0);
        }

        // Вычисляем параметры: t для луча a и u для отрезка b.
        double t = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / denominator;
        double u = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / denominator;

        // Проверяем, что точка пересечения находится на луче (t >= 0) и внутри отрезка (0 <= u <= 1).
        if (t >= 0 && u >= 0 && u <= 1) {
            return std::vector<Point>(1, Point(x1 + t * dx1, y1 + t * dy1));
        } else {
            return std::vector<Point>(0);
        }
    }

    // Функция для вычисления точки пересечения отрезка и луча (перестановка аргументов).
    std::vector<Point> getIntersectionPoint(const Segment& a, const Ray& b) {
        return getIntersectionPoint(b, a);
    }

    // Функция для вычисления точки пересечения двух отрезков.
    // Пересечение считается корректным, если точка лежит в пределах обоих отрезков.
    std::vector<Point> getIntersectionPoint(const Segment& a, const Segment& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём

        // Координаты отрезка a.
        double x1 = a.getPosP1().getX();
        double y1 = a.getPosP1().getY();
        double x2 = a.getPosP2().getX();
        double y2 = a.getPosP2().getY();

        // Координаты отрезка b.
        double x3 = b.getPosP1().getX();
        double y3 = b.getPosP1().getY();
        double x4 = b.getPosP2().getX();
        double y4 = b.getPosP2().getY();

        // Вычисляем направления отрезков.
        double dx1 = x2 - x1;
        double dy1 = y2 - y1;
        double dx2 = x4 - x3;
        double dy2 = y4 - y3;

        // Вычисляем детерминант для проверки на параллельность.
        double det = dx1 * dy2 - dy1 * dx2;
        if (std::fabs(det) < EPSILON) {
            // Отрезки параллельны или совпадают.
            return std::vector<Point>(1, Point(NAN, NAN));
        }

        // Вычисляем параметры t и u для определения точки пересечения.
        double t = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / det;
        double u = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / det;

        // Проверяем, что точка пересечения лежит в пределах обоих отрезков.
        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            return std::vector<Point>(1, Point(x1 + t * dx1, y1 + t * dy1));
        } else {
            return std::vector<Point>(1, Point(NAN, NAN));
        }
    }

    // Функция для вычисления точек пересечения прямой и окружности.
    std::vector<Point> getIntersectionPoint(const Straight& a, const Circle& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём
        std::vector<Point> points;

        // Координаты окружности b.
        double x2 = b.getCenterPos().getX();
        double y2 = b.getCenterPos().getY();
        double r = b.getRadius();

        // Координаты прямой a.
        double x1 = x2;
        double y1 = a.getY(x1);
        double angle = a.getAngle().get();

        double sin_angle = std::sin(angle);
        double cos_angle = std::cos(angle);

        // Разница координат между центром окружности и началом луча.
        double dx = x2 - x1;
        double dy = y2 - y1;

        // Расстояние от начала луча до центра окружности.
        double l = std::hypot(dx, dy);
        // Вычисляем разницу между направлением на центр окружности и направлением луча.
        double diff = std::atan2(dy, dx) - angle;

        // Проекция расстояния на направление луча.
        double l2 = l * std::cos(diff);
        // Перпендикулярное расстояние от центра окружности до луча.
        double oc = l * std::sin(diff);

        // Если выражение под корнем отрицательно, пересечения нет.
        double delta = r * r - oc * oc;
        if (delta < -EPSILON)
            return points; // нет пересечений

        // Корректируем возможные незначительные отрицательные значения.
        delta = std::max(delta, 0.0);
        double cd = std::sqrt(delta);

        // Вычисляем параметры (расстояния вдоль луча) для точек пересечения.
        double t1 = l2 - cd;
        double t2 = l2 + cd;

        // Для луча важен знак: пересечение имеет смысл, если параметр t >= 0.
        if (t1 >= -EPSILON)
            points.push_back(Point(t1 * cos_angle + x1, t1 * sin_angle + y1));

        // Если точки различаются, добавляем вторую.
        if (std::abs(t2 - t1) > EPSILON && t2 >= -EPSILON)
            points.push_back(Point(t2 * cos_angle + x1, t2 * sin_angle + y1));

        return points;
    }

    // Функция для вычисления точек пересечения луча и окружности.
    std::vector<Point> getIntersectionPoint(const Ray& a, const Circle& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём
        std::vector<Point> points;

        // Центр и радиус окружности b.
        double x2 = b.getCenterPos().getX();
        double y2 = b.getCenterPos().getY();
        double r = b.getRadius();

        // Начало и направление луча a.
        double x1 = a.getStartPos().getX();
        double y1 = a.getStartPos().getY();
        double angle = a.getAngle().get();

        double sin_angle = std::sin(angle);
        double cos_angle = std::cos(angle);

        // Разница координат между центром окружности и началом луча.
        double dx = x2 - x1;
        double dy = y2 - y1;

        // Расстояние от начала луча до центра окружности.
        double l = std::hypot(dx, dy);
        // Вычисляем разницу между направлением на центр окружности и направлением луча.
        double diff = std::atan2(dy, dx) - angle;

        // Проекция расстояния на направление луча.
        double l2 = l * std::cos(diff);
        // Перпендикулярное расстояние от центра окружности до луча.
        double oc = l * std::sin(diff);

        // Если выражение под корнем отрицательно, пересечения нет.
        double delta = r * r - oc * oc;
        if (delta < -EPSILON)
            return points; // нет пересечений

        // Корректируем возможные незначительные отрицательные значения.
        delta = std::max(delta, 0.0);
        double cd = std::sqrt(delta);

        // Вычисляем параметры (расстояния вдоль луча) для точек пересечения.
        double t1 = l2 - cd;
        double t2 = l2 + cd;

        // Для луча важен знак: пересечение имеет смысл, если параметр t >= 0.
        if (t1 >= -EPSILON)
            points.push_back(Point(t1 * cos_angle + x1, t1 * sin_angle + y1));

        // Если точки различаются, добавляем вторую.
        if (std::abs(t2 - t1) > EPSILON && t2 >= -EPSILON)
            points.push_back(Point(t2 * cos_angle + x1, t2 * sin_angle + y1));

        return points;
    }




    // Функция для вычисление растояния меж лучом и кругом
    double getDistanceToPoint(const Ray& a, const Point& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём

        // Получаем начальные координаты лучей a и b
        double x1 = a.getStartPos().getX();
        double y1 = a.getStartPos().getY();
        double x2 = b.getX();
        double y2 = b.getY();
        
        // Получаем углы лучей a и b
        double theta1 = a.getAngle().get();

        // Вычисляем синусы и косинусы углов для оптимизации дальнейших вычислений
        double sin_theta1 = std::sin(theta1);
        double cos_theta1 = std::cos(theta1);

        // Разница координат между началом луча и круга
        double dx = x2 - x1;
        double dy = y2 - y1;

        double l = std::hypot(dx, dy);


        // Возвращаем точку пересечения, смещая начальную точку луча на t вдоль направления луча
        return l * std::sin(std::atan2(dy, dx)-a.getAngle().get());
    }
    double getDistanceToPoint(const Straight& a, const Point& b) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём

        // Получаем начальные координаты лучей a и b
        double x1 = a.getOffsetY();
        double y1 = a.getOffsetX();
        double x2 = b.getX();
        double y2 = b.getY();
        
        // Получаем углы лучей a и b
        double theta1 = a.getAngle().get();

        // Вычисляем синусы и косинусы углов для оптимизации дальнейших вычислений
        double sin_theta1 = std::sin(theta1);
        double cos_theta1 = std::cos(theta1);

        // Разница координат между началом луча и круга
        double dx = x2 - x1;
        double dy = y2 - y1;

        double l = std::hypot(dx, dy);


        // Возвращаем точку пересечения, смещая начальную точку луча на t вдоль направления луча
        return l * std::sin(std::atan2(dy, dx)-a.getAngle().get());
    }

    double getDistanceToPoint(const Straight& a, const Circle& circle) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём
        // Вычисляем расстояние от центра круга до прямой с помощью уже существующей функции
        return getDistanceToPoint(a, circle.getCenterPos()) - circle.getRadius();
    }
    double getDistanceToPoint(const Ray& a, const Circle& circle) {
        const double EPSILON = 1e-9; // Допуск для сравнения с нулём
        // Вычисляем расстояние от центра круга до прямой с помощью уже существующей функции
        return getDistanceToPoint(a, circle.getCenterPos()) - circle.getRadius();
    }
    
    double getDistanceToPoint(const Point& a, const Point& b) {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        return std::hypot(dx, dy);
    }


    radian getAngle(const Point& a, const Point& b, const Point& c) {
        Point da = a-b;
        Point db = c-b;
        return  radian(std::atan2(da.getY(), da.getX())-std::atan2(db.getY(), db.getX()));
    }
}