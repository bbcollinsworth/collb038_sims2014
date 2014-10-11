
#include "ofApp.h"
#include "MyClass.h"
#include "Boom.h"

//--------------------------------------------------------------
void ofApp::setup(){

    boomCount = 0;

    for (int i = 1; i <= 3; i ++){
    MyClass shell;
    shell.set(ofPoint(ofGetWidth()*i/4,ofGetHeight()),-1,-1*ofRandom(0.005,0.01));
    shells.push_back(shell);
    }



}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i=0; i < shells.size(); i++){

            if (shells[i].vel < 0) {
                shells[i].update();
            } else if (shells[i].vel >= 0) {
                if (boomCount == 40 || boomCount == 80 ) {
                    sparkSet(shells[i].x,shells[i].y);
                }
                 boomCount++;
                 sparkUpdate();
            }
    }
}


//--------------------------------------------------------------
void ofApp::sparkSet(float _startX, float _startY) {


    for (int i = 1; i <= 50; i ++){
    Boom spark;
    spark.set(_startX,_startY,ofRandom(-1,1),ofRandom(-1,1),ofRandom(-0.01,0.01),ofRandom(-0.01,0.01));
    sparks.push_back(spark);
    }



}

//--------------------------------------------------------------
void ofApp::sparkUpdate(){

    for (int i=0; i < sparks.size(); i++){
    sparks[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);


    //ofPushMatrix();
   // ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);

    for (int i=0; i < shells.size(); i++){
        shells[i].draw();
    }

    for (int i=0; i < sparks.size(); i++){
        sparks[i].draw();
    }
    //ofPopMatrix();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
