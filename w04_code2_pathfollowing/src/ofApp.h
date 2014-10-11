#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Path.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    //void follow(Path p);

    //ofPoint dest1, dest2;
    //Particle car1, car2;

    vector <ofPoint> destinations;
    vector <Particle> cars;
    vector <ofColor> colors;

    float pathRadius;

    Path path;

};