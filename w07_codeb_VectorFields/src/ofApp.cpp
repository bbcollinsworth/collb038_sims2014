#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );

    ofBackground(0);

    sliderMin = ofGetWidth()-160;
    sliderMax = 50;

    randomMin = -1;
    randomMax = 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    myField.draw();

    ofSetColor(200);
    ofRect(ofPoint(ofGetWidth()-170,50),120,50);
    ofSetColor(0,255,50);
    ofRect(ofPoint(sliderMin,50),(ofGetWidth()-110)-sliderMin,50);
    ofRect(ofPoint(ofGetWidth()-110,50),sliderMax,50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom();
    }else if( key == '2' ){
        myField.setPerlin();
    }else if( key == '3' ){
        myField.setCustomA(randomMin,randomMax);
    }else if( key == '4' ){
        myField.setRandomModA(randomMin,randomMax);
    }else if( key == '5' ){
        myField.setCustomB(randomMin,randomMax);
    }else if( key == '6' ){
        myField.setCustomC(randomMin,randomMax);
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

if (mouseX >= ofGetWidth()-160 && mouseX < ofGetWidth()-110){
    sliderMin = mouseX;
}
if (mouseX > ofGetWidth()-110 && mouseX <= ofGetWidth()-60){
    sliderMax = ofMap(mouseX, ofGetWidth()-110, ofGetWidth()-60, 1,50);
}

randomMin = ofMap(sliderMin,ofGetWidth()-160,ofGetWidth()-110,-1,0);
randomMax = ofMap(sliderMax,0,50,0,1);

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
