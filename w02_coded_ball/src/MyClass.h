#ifndef MYCLASS_H
#define MYCLASS_H

#pragma once

#include "ofMain.h"

class MyClass : public ofPoint {
    public:



        void set(float _dist, float _intAngle);

        void update(float _step, ofPoint _pos);

        void draw();

        ofPoint pos;

        float radius;
        float angle;
        float xSpeed;
        float ySpeed;
        float gravity;

        vector< ofPoint > tail;


    private:
};

#endif // MYCLASS_H
