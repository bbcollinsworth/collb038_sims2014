#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    generation = 0;
    //walker = ofPoint(ofRandomWidth(),ofRandomHeight());
    walker = ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    radius = 1;
    radGrow = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    //walker += ofPoint(ofRandomf()*10,ofRandomf()*10);

    walker.x += sin(ofGetFrameNum()*0.05)*radius;
    walker.y += cos(ofGetFrameNum()*0.05)*radius;

    /*
    if (walker.x > ofGetWindowWidth()){
        walker.x = 0;
    } else if (walker.x < 0){
        walker.x = ofGetWindowWidth();
    } else if (walker.y > ofGetWindowHeight()){
        walker.y = 0;
    } else if (walker.y < 0){
        walker.y = ofGetWindowHeight();
    }*/

    //theta = ofMap(walker.x, 0, ofGetWindowWidth(), -180, 180);
    //yfactor = ofMap(walker.y, 0, ofGetWindowWidth(), -90, 90);

    if (radius > ofGetWindowWidth()*0.5){
        radGrow = false;
    }

    if (radius < 1) {
        radGrow = true;
    }

    if (radGrow == true){
        radius *= 1.005;
    } else {
        radius /= 1.005;
    }

}
//-----------------------------------------------------------------------
void ofApp::branch( float length, float angle, int r, int g, int b, int a ) {
    ofPushMatrix();
    ofSetColor(r,g,b,a);
    //ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
    ofTranslate( 0, -length );

    generation++;

    float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1 );

    if( length > 4 ){
        ofPushMatrix();{
            ofRotate( angle + theta - yfactor);//) + noise * 10-5 );
            ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
            branch( length * 0.75, angle*0.8, r * 0.9, g * 0.9, b * 1.1, a*0.85);
        }ofPopMatrix();

        //(abs(sin(ofGetFrameNum()*0.1))*0.9+0.1)

        ofPushMatrix();{
            ofRotate( -angle + theta + yfactor);// - noise * 10-5 );
            ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
            branch( length * 0.75, angle*0.8, r * 0.9, g * 1.1, b * 1.05, a*0.85 );
        }ofPopMatrix();
    }

    ofPopMatrix();

    generation--;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(80,0,0),ofColor(0));

    float pulse = sin(ofGetFrameNum()*0.4);
    float noise = ofNoise(ofGetElapsedTimef()*0.1)*40;
    ofPushMatrix();{
        ofTranslate( ofGetWindowWidth()/2, ofGetWindowHeight()*0.75 );
        branch( ofGetWindowHeight()*0.25+pulse*10, 90, 200-pulse*noise, 180+pulse*noise, 80-pulse*noise, 240 );
    }ofPopMatrix();

    //ofSetColor(255,255,0);
    //ofCircle(walker,10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        if(key == 'f'){
        ofToggleFullscreen();
    }
    if (key == 's'){
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
    theta = ofMap(x, 0, ofGetWindowWidth(), -180, 180);
    yfactor = ofMap(y, 0, ofGetWindowWidth(), -90, 90);
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
