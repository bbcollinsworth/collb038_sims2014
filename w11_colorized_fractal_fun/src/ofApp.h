#pragma once

#include "ofMain.h"

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


    void branch( float length, float angle, int r, int g, int b, int a );

    float theta = 0;
    float yfactor = 0;
    int generation;
    ofPoint walker;
    float radius;
    bool radGrow;
    //int r,g,b;
};
