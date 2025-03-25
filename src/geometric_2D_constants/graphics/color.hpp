#pragma once
#include <iostream>

class Color
{
    public:
        u_int8_t r=0;
        u_int8_t g=0;
        u_int8_t b=0;
        u_int8_t a=255;

        Color() {}
        Color(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a): r(r), g(g), b(b), a(a) {}
        Color(u_int8_t r, u_int8_t g, u_int8_t b): r(r), g(g), b(b) {}
        Color(u_int8_t w): r(w), g(w), b(w), a(w) {}
        Color(const Color& other): r(other.r), g(other.g), b(other.b), a(other.a) {}
        
        Color& operator() (u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a) {
            this->r=r;
            this->g=g;
            this->b=b;
            this->a=a;
            return *this;
        }
        Color& operator() (u_int8_t w) {
            this->r=w;
            this->g=w;
            this->b=w;
            this->a=a;
            return *this;
        }
        Color& operator() (const Color& other) {
            this->r=other.r;
            this->g=other.g;
            this->b=other.b;
            this->a=other.a;
            return *this;
        }

        Color& operator= (const Color& other) {
            this->r=other.r;
            this->g=other.g;
            this->b=other.b;
            this->a=other.a;
            return *this;
        }
};
