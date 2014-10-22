#pragma once

#ifndef TAIL_H
#define TAIL_H

#include "ofMain.h"


class Tail
{
    public:
        Tail();
        void setInit(ofPoint _pos, ofColor _blueVary, float _tailRad);
        void update();
        void draw(int _sinOffset, int _tailGrow);

        float tailRad;

        ofPoint pos;

        int blueVary;
        int sinOffset;
        ofColor tailColor;


        virtual ~Tail();
    protected:
    private:
};

#endif // TAIL_H
