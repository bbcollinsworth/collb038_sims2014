#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Tail.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void makeFlower();
    void reset();
    void setupArduino(const int & version);
    void updateArduino();
    void analogPinChanged(const int & pinNum);

    ofArduino	ard;
	bool		bSetupArduino;
	int reading;


    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    int bloomState = 0;

    float minPetalLoc;
    int bloomCounter;
    int colorState = 0;
    float colorMult = 0;

    //ofPoint sliderLoc;
    float sliderLoc;
    int blow;

    vector<float> spikeRots;
    vector<float> colorMults;
    vector<Particle> particles;
    vector<Particle> pollen;

    //Particle stem;
};
