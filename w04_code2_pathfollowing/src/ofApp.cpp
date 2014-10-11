#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    pathRadius = 25;

    int yHeight = ofGetHeight();
    //Path path;
    path.setInit(yHeight*ofRandomuf(),yHeight*ofRandomuf(),pathRadius);

    cout << "Random: " << ofRandomuf() << endl;



    float carNum = 50;

    for (int i = 0; i < carNum; i++) {


    Particle car;
    car.setInit(ofPoint(0,ofGetHeight()*ofRandomuf()), ofPoint(ofRandomuf(),ofRandomf()));
    cars.push_back(car);

    ofColor color = ofColor(ofRandom(10,200),ofRandom(0,100),ofRandom(0,50));
    colors.push_back(color);
    cars[i].color = colors[i];
    }

    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

    // apply steering force
    //float area = 50;

    for (int i=0; i<cars.size(); i++){
        cars[i].update();
        cars[i].follow(path.getStart(),path.getFinish(),pathRadius);
        cars[i].infiniteDrive();


    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,240,219);

    path.draw();

    for (int i=0; i<cars.size(); i++){
        ofSetColor( cars[i].color );
        cars[i].draw();
    }

}

//--------------------------------------------------------------
/*
void ofApp::follow(Path path){

    for (int i=0; i<cars.size(); i++){
        ofPoint predict = cars[i].getVelocity();
        predict.normalize();
        predict *= 20;
        ofPoint predictLoc = cars[i].getPosition() + predict;
        ofPoint a = p.start;
        ofPoint b = p.finish;

    }

}
*/

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
