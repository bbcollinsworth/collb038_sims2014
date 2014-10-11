#ifndef MYCLASS_H
#define MYCLASS_H

#pragma once

#include "ofMain.h"

class MyClass : public ofPoint {
    public:



        void set(ofPoint _pos, float _vel, float _rad, float _length, float _rot, float _gStart);

        void update(float _rotUp);

        void draw();

        void ofGetRad();
        void getY();
        void branch(float _branchRot);

        float branchRot;

        float xInit;
        float yInit;

        ofPoint pos;
        float vel;
        float dec;
        float gravity;

        float gStart;
        float velInit;
        float branchLength;
        float branchRand;
        float branchRandD;

        float radius;
        float radInit;

        float angle;


        vector< ofPoint > tail;


    private:
};

#endif // MYCLASS_H
