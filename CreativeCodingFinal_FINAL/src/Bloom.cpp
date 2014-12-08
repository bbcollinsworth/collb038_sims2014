#include "Bloom.h"

Bloom::Bloom()
{
    //ctor
}

void Bloom::setup(ofVec3f _bloomPoint){

    bloomPoint = _bloomPoint;
    //int bloomGB = int(ofRandom(190,245));
    float bloomGB = float(ofRandom(150,245));
    ofFloatColor bloomColor = ofFloatColor(1,bloomGB/255,(bloomGB+10)/255);
    for (int i = 0; i < 6; i++){
        Petal p;
        p.setup(bloomPoint,bloomColor);
        petals.push_back(p);
    }
}

void Bloom::update(){

    for (int i=0; i < petals.size(); i++){
    //if (petalMade == true) {
        petals[i].update();
    //}
    }

}

void Bloom::draw(){

    int noiseFactor = bloomPoint.y*0.1;
    ofPushMatrix();
    ofTranslate(bloomPoint);

    float noise = ofNoise( noiseFactor, ofGetFrameNum() * 0.02 );
    //float noise = ofNoise( noiseFactor, ofGetElapsedTimef() * 1 );

    ofRotate(noise*10);

    for (int i=0; i < petals.size(); i++){
    //if (petalMade == true) {
        float step = 60;
        ofRotate(step);
        petals[i].draw();
    }
    ofPopMatrix();

}

Bloom::~Bloom()
{
    //dtor
}
