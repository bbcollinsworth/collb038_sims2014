#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){


	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:

	ofSetVerticalSync(true);

	// set background:

	ofEnableAlphaBlending();
	ofBackground(0,10,50);
	ofSetBackgroundAuto(false);




}

//--------------------------------------------------------------
void ofApp::update(){
	wave.update(ofPoint(ofGetWidth()*0.25,ofGetHeight()*0.5));

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,10,50,10);
	wave.draw();


}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
}
