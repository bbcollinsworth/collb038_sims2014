#pragma once

#include "ofMain.h"
#include "Path.h"

class Particle {
public:
    Particle();

    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));

    ofPoint getPosition();
    float   getRadius();
    ofPoint getVelocity();
    ofPoint getNormalPoint(ofPoint p, ofPoint a, ofPoint b);
    ofPoint normalPoint;
    ofPoint target;

    void addForce(ofPoint _force);

    void follow(ofPoint _pathStart, ofPoint _pathFinish, float _pathRad);

    void seek( ofPoint dest, float _speed, float _force );

    void infiniteDrive();


    void update();
    void draw();

    ofColor color;

    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    void addClockwiseForce( ofPoint _pos, float _rad, float _scale);
    void addCounterClockwiseForce( ofPoint _pos, float _rad, float _scale);

private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;

    float radius;
    float damp;
    float maxSpeed;
};
