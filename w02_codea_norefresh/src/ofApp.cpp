#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){


	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:

	ofSetVerticalSync(true);

	// set background:

	ofEnableAlphaBlending();

	ofBackground(50,10,0,1);
	ofSetBackgroundAuto(false);


	// set the position of the rectangle:

	myCreature.x = 0;
	myCreature.y = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
	myCreature.xenoToPoint(ofPoint(mouseX, mouseY),ofPoint(myCreature.x,myCreature.y));
}

//--------------------------------------------------------------
void ofApp::draw(){
	myCreature.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    ofSaveFrame();
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
    string fileName;
fileName = "screen.png";
ofSaveScreen(fileName);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
}
