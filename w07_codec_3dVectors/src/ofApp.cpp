#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    resolution = 10;

    ofBackgroundGradient(ofColor (255), ofColor (128));

for (int i =0; i  < 100; i++){
 Particle p;
 p.setInit(ofPoint(ofRandomHeight(),ofRandomWidth()),ofPoint(ofRandomf(),ofRandomf()));
 particles.push_back(p);
}

for (int i =0; i  < 10; i++){
    VectorField vf;
    vf.setup(ofGetWidth(), ofGetHeight(), resolution);
    vf.setNoise(i+1);
    vfs.push_back(vf);
}

}

//--------------------------------------------------------------
void ofApp::update(){

    light.setDiffuseColor(ofFloatColor(1.0,1.0,0.0));
    light.setPosition(ofPoint(50.0,50.0,50.0));

    ofPoint mouse = ofPoint(mouseX,mouseY);
    //vf.addRepulsionForce(mouse, 100, 1.0);

    for (int i =0; i  < particles.size(); i++){
        for (int j=0; j < vfs.size(); j++){
            particles[i].addForce(vfs[j].getForce(particles[i].getPosition()));
            particles[i].infiniteWalls();
            particles[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    light.enable();
    ofEnableLighting();

    ofBackgroundGradient(ofColor (100,80,0), ofColor (50,45,0));

    for (int i =0; i  < particles.size(); i++){
        particles[i].draw();
    }

    for (int i =0; i  < vfs.size(); i++){
        ofPushMatrix();
        ofTranslate(0,0,i*resolution);
        vfs[i].draw();
        ofPopMatrix();
    }

    ofDisableLighting();
    light.disable();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        ofToggleFullscreen();
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
