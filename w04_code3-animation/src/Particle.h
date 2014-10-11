#pragma once

#include "ofMain.h"
#include "Tail.h"

class Particle : public ofPoint {
public:
    Particle();

    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));

    float   getRadius();
    ofPoint getPosition();
    ofPoint getVelocity();

    float splash;


    void addForce(ofPoint _force);

    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    void addClockwiseForce( ofPoint _pos, float _rad, float _scale);
    void addCounterClockwiseForce( ofPoint _pos, float _rad, float _scale);

    void addFlockingForce(vector<Particle> &_particles, float _neighborhoodRadius, float _alignmentScale = 0.33, float _separationScale = 0.33, float _cohesionScale = 0.33);
    float getHeading();

    void addWaveForce(float _heading);
    void addGravity();

    void bounceOnWall();
    void infiniteWalls();

    void update();
    void draw();

    //ofColor tailColor;

    //int tailColor;
    ofColor tailVary;
    float tailWidth;

    vector <Tail> tail;

private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;

    float radius;
    float damp;
};
