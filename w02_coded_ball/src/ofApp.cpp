
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    moon.set(60,0);

}

//--------------------------------------------------------------
void ofApp::update(){


    moon.update(0.005, ofPoint(mouseX, mouseY));

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);


    ofPushMatrix();
   // ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);

    ofSetColor(0,0,255);
    ofCircle(0, 0, 10);

    moon.draw();
    ofPopMatrix();
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
