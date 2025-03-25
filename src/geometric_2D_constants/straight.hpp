#pragma once
#include "import_lib.hpp"


class Straight {
    private:
        Point offset;
        radian angle;
    public:
        // ### ИНИЦИАЛИЗАТОРЫ ###
    
        // Инициализировать луч без задания параметров
        Straight() {}
        // Создать луч с начальными координатами и поворотом
        Straight(const radian& angle) {
            this->angle = angle;
            offset(0, 0);
        }
        Straight(const double angle) {
            this->angle = angle;
            offset(0, 0);
        }
        Straight(const Point& other, const radian& angle) {
            offset = other;
            this->angle = angle;
        }
        Straight(const Point& other, const double angle) {
            offset = other;
            this->angle = angle;
        }
        Straight(const double offsetX, const double offsetY, const radian& angle) {
            offset(offsetX, offsetY);
            this->angle = angle;
        }
        Straight(const double offsetX, const double offsetY, const double angle) {
            offset(offsetX, offsetY);
            this->angle = angle;
        }
    
        // ### GET ###
    
        double getOffsetX() const { return offset.getX(); }
        double getOffsetY() const { return offset.getY(); }
        Point getOffset() const { return offset; }

        double getY(double x) const {
            return std::tan(angle.get()) * (x - offset.getX()) + offset.getY();
        }
        double getX(double y) const {
            return (y - offset.getY()) / std::tan(angle.get()) + offset.getX();
        }
    
        // Возвращает угол поворота луча относительно абсциссы (в радианах)
        radian getAngle() const { return angle; }


        // ### SET ###

        Straight&  setOffsetX(const double offsetX) {
            offset.setX(offsetX);
            return *this;
        }
        Straight&  setOffsetY(const double offsetY) {
            offset.setY(offsetY);
            return *this;
        }
        Straight&  setOffset(const double offsetX, const double offsetY) {
            offset.set(offsetX, offsetY);
            return *this;
        }
        Straight&  setOffset(const Point& offset) {
            this->offset.set(offset);
            return *this;
        }

        Straight&  setAngle(const double angle) {
            this->angle = angle;
            return *this;
        }
        Straight&  setAngle(const radian& angle) {
            this->angle = angle;
            return *this;
        }

        
        // ### operator ###
    
        Straight&  operator=(const radian& angle) {
            offset(0, 0);
            this->angle = angle;
            return *this;
        }
        
        Straight&  operator=(const double angle) {
            offset(0, 0);
            this->angle = angle;
            return *this;
        }
    
        Straight&  operator()(const Straight&  other) {
            offset = other.offset;
            angle = other.angle;
            return *this;
        }
        
        Straight&  operator=(const Straight&  other) {
            offset = other.offset;
            angle = other.angle;
            return *this;
        }
    
        Straight&  operator()(const double offsetX, const double offsetY, const radian& angle) {
            offset(offsetX, offsetY);
            this->angle = angle;
            return *this;
        }
        Straight&  operator()(const double offsetX, const double offsetY, const double angle) {
            offset(offsetX, offsetY);
            this->angle = angle;
            return *this;
        }

        Straight&  operator()(const Point& offset, const radian& angle) {
            this->offset = offset;
            this->angle = angle;
            return *this;
        }

        Straight&  operator()(const Point& offset, const double angle) {
            this->offset = offset;
            this->angle = angle;
            return *this;
        }
};    