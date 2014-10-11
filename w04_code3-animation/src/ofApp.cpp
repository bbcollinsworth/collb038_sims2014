#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //  Create 100 Particles
    //
    for (int i = 0; i < 40; i++) {
        Particle newParticle;
        newParticle.setInit(ofPoint(ofGetWidth()*0.5,ofGetHeight()*0.5),
                            ofPoint(ofRandom(-0.1, 0.1), -0.1 ));
        particles.push_back(newParticle);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint mouse = ofPoint(mouseX,mouseY);

    for (int i = 0; i < particles.size(); i++) {

        particles[i].addFlockingForce(particles, 200, 0.33, 0.1, 0.02);
        particles[i].addAttractionForce(ofPoint(ofGetWidth()*0.5,ofGetHeight()*0.5), 1000, 0.0001);
        particles[i].addRepulsionForce(ofPoint(ofGetWidth()*0.5,ofGetHeight()*0.5), 100, 0.9);
        particles[i].addWaveForce(particles[i].getHeading());
        //particles[i].addGravity();
        particles[i].update();
        particles[i].infiniteWalls();

        cout << particles[i].getHeading() << endl;
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    if(ofGetKeyPressed('s')){
        ofBeginSaveScreenAsPDF(ofGetTimestampString()+".pdf");
    }

    ofBackground(213, 205, 169);
	ofSetColor(255);



    for (auto &it: particles) {

        it.draw();
    }


    if(ofGetKeyPressed('s')){
        ofEndSaveScreenAsPDF();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
