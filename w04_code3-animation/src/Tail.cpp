#include "Tail.h"

Tail::Tail()
{

    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;

    //ctor
}

void Tail::setInit(ofPoint _pos,ofColor _blueVary,float _tailRad) {
    pos = _pos;
    //blueVary = _blueVary;
    tailColor = _blueVary;
    tailRad = _tailRad;
    //tailColor = ofColor(0,0,200+blueVary);
}

void Tail::update() {

}

void Tail::draw(int _sinOffset, int _tailGrow) {
    //tailColor = ofColor(0,0,200+_blueVary);

    //ofPushMatrix();
    //ofTranslate(pos);
        //ofRotate(50);

    float randSin = _tailGrow;
    sinOffset = _sinOffset;

    ofSetColor(tailColor);
    ofRectMode(CENTER);
    //ofRect(pos,(tailRad+sin((ofGetFrameNum()+ofRandomf()*10)*randSin*0.01)*2)+_tailGrow*0.4,
            //            (tailRad+sin((ofGetFrameNum()+ofRandomf()*10)*randSin*0.01)*2)+_tailGrow*0.4);

    //ofPopMatrix();
        //
        ofCircle(pos,(tailRad+sin((ofGetFrameNum()+ofRandomf()*10)*randSin*0.001)*2)+_tailGrow*0.4);

}

Tail::~Tail()
{
    //dtor
}
