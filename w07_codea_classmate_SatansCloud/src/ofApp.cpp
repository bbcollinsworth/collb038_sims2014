#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
	ofSetFrameRate(60);



    ofBackground(0);



    //create the particles
    num = 500;

    for(int i =0; i < num; i++){

        Particle p;
        MyParticles.push_back(p);
        MyParticles[i].init();


    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i =0; i < num; i++){
        MyParticles[i].update(MyParticles);
        MyParticles[i].bounding();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
   // ofBackground(0,5);
    //ofBackground(255,255,240);
	//ofSetColor(255);

    //note that easy cam gives you the ability to move the "camera" w/ mouse
    ofPushMatrix();

    //cam.begin();
    //light.enable();
    //ofEnableLighting();
    //glEnable(GL_DEPTH_TEST);

    //drawing my particles
    for(int i = 0; i < num; i++){
        MyParticles[i].draw();
    }

    //glDisable(GL_DEPTH_TEST);
    //ofDisableLighting();
    //light.disable();
    //cam.end();

    ofPopMatrix();

        //UNCOMMENT TO SAVE IMAGES
    //string frameCount = ofToString(20000+ofGetFrameNum());
    //string fileName = "Images/" + frameCount + ".png";
    //ofSaveScreen(fileName);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        ofToggleFullscreen();
    }

    if(key == 's'){
        string frameCount = ofToString(20000+ofGetFrameNum());
        string fileName = "Images/" + frameCount + ".jpg";
        ofSaveScreen(fileName);
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
