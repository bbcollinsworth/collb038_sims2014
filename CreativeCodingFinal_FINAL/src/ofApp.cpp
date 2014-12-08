#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);

    record = false;

    recStart = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < trees.size(); i++){
        trees[i].update();
    }

}


//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor (255, 245, 210), ofColor (210, 195, 160));

    for (int i = 0; i < trees.size(); i++){
        trees[i].draw();
    }

    //TO SAVE EVERY FRAME
    if (record == true){
        string frameCount = ofToString(20000+ofGetFrameNum());
        string fileName = "filmImages/" + currentDate + "/" + frameCount + ".png";
        ofSaveScreen(fileName);

        int recFrames = ofGetFrameNum()-recStart;
        float recTime = recFrames / 60;

        cout << "Frames: " << recFrames << endl;
        cout << "Time: " << recTime << endl;
    }
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

    //THIS CREATES A NEW TREE!!
    if(key == 't'){
        ofVec3f treeInit = ofVec3f(0,ofGetHeight()*ofRandom(0.1,0.9),0);
        int angleInit = int(ofRandom(70,130));

        Tree t;
        t.setup(treeInit,angleInit,trees.size());
        trees.push_back(t);
    }

    //THIS SAVES EVERY FRAME
    if(key == 'r'){
            record = true;
            recStart = ofGetFrameNum();
            currentDate = ofGetTimestampString();
        }

    if(key == 'e'){
            record = false;
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
