//
//  Particle.h
//  myFlocking
//
//  Created by Regina Flores on 9/25/14.
//
//
#pragma once
#include "ofMain.h"
#include "Tail.h"


class Particle{
public:

    Particle();

    void init();
    void bounding();
    void draw();
    void update( vector<Particle> &particles );

    //these functions return ofPoints v1,v2,v3
    ofPoint cohesion(vector<Particle> &particles);
    ofPoint separation(vector<Particle> &particles);
    ofPoint allignment(vector<Particle> &particles);

    //note that these are variables
    ofPoint pos;
    ofPoint vel;
    int radius;

    int colorMap;

    void addForce(ofPoint _force);

    bool haveNextNextGaussian = false;
    float nextNextGaussian;

    float ofxGaussian();


    void addGravity();
    void addWindForce();

    float getBreakPoint();
    float getPetalLoc();

    int breakCounter;
    float breakPoint;
    float rotSeed;
    float step;

    //char type;
    bool isLeaf;



    ofColor tailVary;
    float tailWidth;
    float velMag;

    vector <Tail> tail;
    //vector <float> cols;





};
