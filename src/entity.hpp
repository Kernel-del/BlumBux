#pragma once

#include "geometric_2D_constants/import_lib.hpp"


class Entity {
    protected:
        bool view = true;
        Point pos = Point(0.0, 0.0);
        int chunk_pos = 0;
        radian rotation = 0;
    public:
        Entity() {}
        Entity(double pos_x, double pos_y, radian rotartion=0, int chunk_pos=0): rotation(rotartion), chunk_pos(chunk_pos) {
            pos(pos_x, pos_y);
        }
        Entity(double pos_x, double pos_y, double rotartion=0, int chunk_pos=0): rotation(rotartion), chunk_pos(chunk_pos) {
            pos(pos_x, pos_y);
        }
        Entity(Point pos, radian rotartion=0, int chunk_pos=0): rotation(rotartion), chunk_pos(chunk_pos) {
            this->pos = pos;
        }
        Entity(Point pos, double rotartion=0, int chunk_pos=0): rotation(rotartion), chunk_pos(chunk_pos) {
            this->pos = pos;
        }


        virtual Entity operator() (double pos_x, double pos_y, radian rotartion=0, int chunk_pos=0) {
            this->rotation = rotation;
            pos(pos_x, pos_y);
            this->chunk_pos = chunk_pos;
            return *this;
        }
        virtual Entity operator() (double pos_x, double pos_y, double rotartion=0, int chunk_pos=0) {
            this->rotation = rotation;
            pos(pos_x, pos_y);
            this->chunk_pos = chunk_pos;
            return *this;
        }
        virtual Entity operator() (Point pos, radian rotartion=0, int chunk_pos=0) {
            this->rotation = rotation;
            this->pos = pos;
            this->chunk_pos = chunk_pos;
            return *this;
        }
        virtual Entity operator() (Point pos, double rotartion=0, int chunk_pos=0) {
            this->rotation = rotation;
            this->pos = pos;
            this->chunk_pos = chunk_pos;
            return *this;
        }
        virtual Entity operator() (Entity other) {
            this->pos = other.pos;
            this->rotation = other.rotation;
            this->chunk_pos = other.chunk_pos;
            return *this;
        }


        virtual Entity operator= (Entity other) {
            this->pos = other.pos;
            this->rotation = other.rotation;
            this->chunk_pos = other.chunk_pos;
            return *this;
        }


        virtual Entity updateChunk() {
            int chunk_x = static_cast<int>(pos.getX()) / 1024;
            int chunk_y = static_cast<int>(pos.getY()) / 1024;
        
            int chunk_delta_x = (chunk_pos % 65536 + chunk_x) % 65536;
            int chunk_delta_y = (chunk_pos / 65536 + chunk_y) % 65536;
        
            chunk_pos = chunk_delta_y * 65536 + chunk_delta_x;
            
            return *this;
        }
        


        ~Entity() {
            view = false;
        }
};


class Player : public Entity {
    protected:
        radian fov = 60;
        double sensitivity=1.0;
        double step = 0.2;
    public:
        Player(): Entity() {}
        Player(Point pos=Point(0, 0), radian rotation=0, int chunk_pos=0, double fov=60, double sensitivity=1, double step=0.2): Entity(pos, rotation, chunk_pos) {}
};
