#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    bloomCounter = 0;
    makeFlower();
    sliderLoc = 70;
}

//--------------------------------------------------------------

void ofApp::makeFlower(){

    //colorState = int(ofRandom(3));
    colorState++;

    for (int i=0; i<6; i++){
        float colorMult=ofRandomuf();
        colorMults.push_back(colorMult);
    }

    cout << colorState << endl;

    int totalParticles = 100;

    for (int i = 0; i < totalParticles; i++) {
        Particle newParticle;

        //float spikeRot = ofRandom(15,30);
        //spikeRots.push_back(spikeRot);
        ofPoint spikeSeed;
        spikeSeed.x = sin(i+ofRandom(19,20));
        spikeSeed.y = cos(i+ofRandom(19,20));

        float spikeScale = ofMap(i,0,totalParticles,3,1.5);
        //float spikeScale = ofMap(i,0,totalParticles,2.5,1);

        newParticle.setInit(ofPoint(0,0),spikeSeed.scale(spikeScale),colorMults);
        particles.push_back(newParticle);

        float pollenScale = ofMap(i,0,totalParticles,0.5,0.1);

        Particle newPollen;
        newPollen.setInit(ofPoint(0,0),spikeSeed.scale(pollenScale),colorMults);
        pollen.push_back(newPollen);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    blow = ofMap(sliderLoc, 50,150, 730,740);
    //cout << "Blow: " << blow << endl;
    //cout << ofGetWidth() << ", " << ofGetHeight() << endl;

    minPetalLoc = ofGetWidth();

    for (int i = 0; i < particles.size(); i++) {
        particles[i].addForce(particles[i].getVelocity()*-0.001);
        particles[i].update();
        pollen[i].addForce(pollen[i].getVelocity()*-0.005);
        pollen[i].update();

        //if (ofGetFrameNum() > particles[i].breakPoint && particles.size() > 0){
        if (particles[i].getPetalLoc() < minPetalLoc){
               minPetalLoc = particles[i].getPetalLoc();
            }
    }

    if (minPetalLoc > 599) {
        particles.clear();
        pollen.clear();
        colorMults.clear();
        bloomCounter++;
        if (bloomCounter >= 60){
            reset();
        }
    }
}

//--------------------------------------------------------------

void ofApp::reset(){
        //minPetalLoc = ofGetWidth();
        makeFlower();
        bloomCounter = 0;

}

//--------------------------------------------------------------
void ofApp::draw(){
    //if(ofGetKeyPressed('s')){
      //  ofBeginSaveScreenAsPDF(ofGetTimestampString()+".pdf");
    //}

    ofBackground(213, 205, 169);
	ofSetColor(255);

    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.5,ofGetHeight()*0.5);

    for (auto &it: particles) {
        it.draw(colorState);
    }

    //for (auto &it: pollen) {
        //it.draw(colorState);
   // }

    ofPopMatrix();

    //SLIDER
    //ofRectMode(CENTER);
    //ofSetColor(ofColor(blackColor));
    //ofRect(ofPoint(50,50),100,50);
    //ofSetColor(ofColor(255,0,0));
    //ofRect(ofPoint(50,50),sliderLoc-50,50);


    if(ofGetKeyPressed('s')){
        ofEndSaveScreenAsPDF();
    }

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
        string frameCount = ofToString(1000+ofGetFrameNum());
        string fileName = "Images2/" + frameCount + ".png";
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

    if (mouseX >= 50 && mouseX <= 150){
        if (sliderLoc >=20){
            sliderLoc = mouseX;
        } else {
            sliderLoc = sliderLoc;
        }
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    /*
    if (sliderLoc >70 && sliderLoc <130){
            sliderLoc = mouseX-20;
        } else {
            sliderLoc = sliderLoc;
        }
        */
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
        sliderLoc = sliderLoc;
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
