#pragma once
#include "import_lib.hpp"

// double round_radian(double angle) {
//     return std::remainder(angle, 2 * M_PI);
// }

class radian {
    private:
        double angle;
    public:
        radian() {};
        radian(const double angle) : angle(angle) {}


        // ### GET ###
        // получить градус в формате double
        double get() const {
            return angle;
        }


        // ### SET ###
        radian& set(const double angle) {
            this->angle = angle;
            return *this;
        }
        radian& set(const radian& other) {
            this->angle = other.angle;
            return *this;
        }

        radian operator+(const radian& other) const {
            return radian(angle + other.angle);
        }
        radian operator+(const double other) const {
            return radian(angle + other);
        }

        radian operator-(const radian& other) const {
            return radian(angle - other.angle);
        }
        radian operator-(const double other) const {
            return radian(angle - other);
        }

        radian operator*(const radian& other) const {
            return radian(angle * other.angle);
        }
        radian operator*(const double other) const {
            return radian(angle * other);
        }

        radian operator/(const radian& other) const {
            return radian(angle / other.angle);
        }
        radian operator/(const double other) const {
            return radian(angle / other);
        }

        radian& operator+=(const radian& other) {
            angle = angle + other.angle;
            return *this;
        }
        radian& operator+=(const double other) {
            angle = angle + other;
            return *this;
        }

        radian& operator-=(const radian& other) {
            angle = angle - other.angle;
            return *this;
        }
        radian& operator-=(const double other) {
            angle = angle - other;
            return *this;
        }

        radian& operator*=(const radian& other) {
            angle = angle * other.angle;
            return *this;
        }
        radian& operator*=(const double other) {
            angle = angle * other;
            return *this;
        }

        radian& operator/=(const radian& other) {
            angle = angle / other.angle;
            return *this;
        }
        radian& operator/=(const double other) {
            angle = angle / other;
            return *this;
        }

        radian& operator=(const radian& other) {
            this->angle = other.angle;
            return *this;
        }
        radian& operator=(const double angle) {
            this->angle = angle;
            return *this;
        }
};