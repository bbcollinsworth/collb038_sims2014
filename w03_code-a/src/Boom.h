#ifndef BOOM_H
#define BOOM_H

#pragma once

#include "ofMain.h"

class Boom : public ofPoint {
    public:



        void set(float _posX, float _posY, float _velX, float _velY, float _accX, float _accY);

        void update();

        void draw();

        ofPoint pos;
        float velX;
        float velY;
        float accX;
        float accY;
        float gravity;

        float radius;
        float angle;


        vector< ofPoint > tail;


    private:
};

#endif // BOOM_H
