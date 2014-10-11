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
