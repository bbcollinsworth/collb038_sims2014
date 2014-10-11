#ifndef MYCLASS_H
#define MYCLASS_H

#pragma once

#include "ofMain.h"

class MyClass : public ofPoint {
    public:



        void set(ofPoint _pos, float _vel, float _acc);

        void update();

        void draw();

        ofPoint pos;
        float vel;
        float acc;
        float gravity;

        float radius;
        float angle;


        vector< ofPoint > tail;


    private:
};

#endif // MYCLASS_H
