#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    float carNum = ofRandom(80,90);

    for (int i = 0; i < carNum; i++) {
    ofPoint dest = ofPoint( ofRandom(10,ofGetWidth()-10), ofRandom(10,ofGetHeight()-10) );
    destinations.push_back(dest);

    Particle car;
    car.setInit( ofGetWindowSize() * ofRandomuf(), ofPoint(ofRandom(-10,10), ofRandom(-5,5)) );

    //car.color = ofColor(0,int(ofRandom(0,255)),int(ofRandom(0,255)));
    cars.push_back(car);

    ofColor color = ofColor(0,ofRandom(255),ofRandom(255));
    colors.push_back(color);
    cars[i].color = colors[i];

    }

    //ofBackground(255);

    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
//ofSeedRandom();
    // apply steering force

    float area = 50;

    for (int i=0; i<cars.size(); i++){
        cars[i].seek(destinations[i], 1.5, 0.2);

        for (int j=0; j<cars.size(); j++){
            if (i != j) {
                if (cars[i].getPosition().distance(cars[j].getPosition()) < area) {
                    cars[i].color = ofColor(255,0,0);
                    cars[j].color = ofColor(255,0,0);
                    cars[i].addRepulsionForce( cars[j].getPosition(), area,  0.1 );
                    cars[j].addRepulsionForce( cars[i].getPosition(), area,  0.1 );
                    //ofSeedRandom();
                    destinations[i] += ofPoint(ofRandomf(),ofRandomf());
                    //float lerpX = destinations[i].x;
                    //float lerpY = destinations[i].y;
                    //destinations[i].x = ofLerp(lerpX,cars[i].getPosition().distance(destinations[i]).x*-1, 0.1);
                    //destinations[i].y = ofLerp(lerpY,ofGetHeight(), 0.1);
                } else {
                    cars[i].color = colors[i];
                    cars[j].color = colors[j];
                }
            }

        }

        cars[i].update();
        if( cars[i].getPosition().distance(destinations[i]) < 5){
            destinations[i] = ofPoint( ofRandom(10,ofGetWidth()-10), ofRandom(10,ofGetHeight()-10) );
        }
    }

    //car1.seek( dest1, 2, 0.04 );
    //car2.seek( dest2, 1, 0.07 );

    // apply repelling force
    /*
    float area = 200;
    if( car1.getPosition().distance( car2.getPosition() ) < area ){
        car1.color = ofColor(255,0,0);
        car2.color = ofColor(255,0,0);

        car1.addRepulsionForce( car2.getPosition(), area,  0.01 );
        car2.addRepulsionForce( car1.getPosition(), area, 0.01 );
        //dest1.addRepulsionForce( dest2.getPosition(), area,  0.01 );
        //dest2.addRepulsionForce( dest2.getPosition(), area, 0.01 );
        dest2.x+=ofRandom(-1,1)*ofRandomf();
        dest2.y+=ofRandom(-1,1)*ofRandomf();
    }else{
        car1.color = ofColor(0,255,0);
        car2.color = ofColor(0,0,255);
    }
    */

    // update physics
    /*
    car1.update();
    car2.update();

    if( car1.getPosition().distance(dest1) < 5){
        dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }

    if( car2.getPosition().distance(dest2) < 5){
        dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    */
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    for (int i=0; i<cars.size(); i++){
        ofSetColor( cars[i].color );
        ofCircle( destinations[i], 4 );
        cars[i].draw();
    }

    //ofSetColor( car2.color );
    //ofCircle( dest2, 4 );
    //car2.draw();
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
