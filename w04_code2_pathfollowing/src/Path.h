#pragma once

#include "ofMain.h"

#ifndef PATH_H
#define PATH_H


class Path {
public:
    Path();

    void setInit(float _startY, float _finishY, float _radius);

    ofPoint start;
    ofPoint finish;
    float radius;

    ofPoint getStart();
    ofPoint getFinish();

    //void addPoint(ofPoint _pos);
    void draw();
    void addPoint(ofPoint _pos);


    vector <ofPoint> pathPoints;

    virtual ~Path();

protected:
private:
};

#endif // PATH_H
