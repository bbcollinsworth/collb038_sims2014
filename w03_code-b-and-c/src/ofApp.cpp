
#include "ofApp.h"
#include "MyClass.h"



//--------------------------------------------------------------
void ofApp::setup(){


    float treeNum = 24;

    for (int j=1; j<=treeNum; j++){
            float treeStart = ofGetWidth()*0.5 + ofRandom(-ofGetWidth()/2+20,ofGetWidth()/2-20);
    float trunkNum = ofRandom(5,8);

    for (int i = 1; i <= trunkNum; i ++){

    MyClass tree;
    tree.set(ofPoint(treeStart,ofGetHeight()),-1,ofRandom(2,10),ofRandom(500,700),ofRandom(-40,40),80+120*i/trunkNum);
    trees.push_back(tree);
            }

    }

}

//--------------------------------------------------------------
void ofApp::update(){



    for (int i=0; i < trees.size(); i++){
    trees[i].update(ofRandom(0,40));

    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,50,30);


    for (int i=0; i < trees.size(); i++){
        trees[i].draw();
        ofSetColor(0,0,80,4);
        ofRect(0,0,ofGetWidth(),ofGetHeight());
    }
ofSetColor(0,0,80,20);
        ofRect(0,0,ofGetWidth(),ofGetHeight());

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
