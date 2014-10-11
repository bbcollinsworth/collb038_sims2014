#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){

}

//------------------------------------------------------------------
void rectangle::draw() {


    ofPushMatrix();
    ofTranslate(*this); //translates 0,0 to center of ofPoint or "*this"


    float tailSpeed = abs(ofMap(distToCatch,0,ofGetWidth(),-0.05,-0.03,true));



    ofFill();

    ofSetColor(100,230,255);




            ofBeginShape();
            for (int i=0; i < tail.size(); i++) {
                //ofVertex(tail[i]);

            float tailAmp = abs(ofMap(i,0,ofGetWidth(),-0.5,-0.03,true));
            float tailSpeed = abs(ofMap(i,0,ofGetWidth(),-0.1,-0.03,true));




                ofSetColor(50,255,255,250);
                ofLine(i, (sin(i*0.05-ofGetFrameNum()*0.1))*tailAmp*i*0.1,i,ofGetHeight());

                ofSetColor(50,255,255,250);
                ofLine(-i, (sin(i*0.05-ofGetFrameNum()*0.1))*tailAmp*i*0.1,-i,ofGetHeight());


            }



            ofEndShape(false);




  ofPopMatrix();

}

//------------------------------------------------------------------
void rectangle::update(ofPoint _start){


    x = ofGetWidth()*0.5;
    y = _start.y + sin(ofGetFrameNum()*0.1)*10;



    tail.push_back(*this);




    if(tail.size() >= ofGetWidth()*0.5){

        tail.erase(tail.end());
    }






}
