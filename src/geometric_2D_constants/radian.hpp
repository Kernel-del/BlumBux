#pragma once
#include "import_lib.hpp"

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

        // получить градус в формате double
        double d () {
            return angle;
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
            return radian(angle/other.angle);
        }
        radian operator/(const double other) {
            return round_radian(angle/other);
        }

        radian& operator+=(const radian& other) {
            angle = round_radian(angle+other.angle);
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