

#include "MyClass.h"


        void MyClass::set(float _dist, float _intAngle){
            radius = _dist;
            angle = _intAngle;
            xSpeed = ofRandom(-0.1,0.1);
            gravity = 0.3;
            ySpeed = ofRandom(-0.1,0.1) + gravity;
            x = ofRandom(0,ofGetWidth());
            y = ofRandom(0,ofGetHeight());
        }

        void MyClass::update(float _step, ofPoint _pos){
            angle += _step;

           // if (x > ofGetWidth() || x < 0 || y > ofGetHeight() || y < 0){
           //     radius *= 0.9995;
           // } else {
           // radius = ;
           // }



if(x < 0 ){
        x = 0;
        xSpeed = -xSpeed;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        xSpeed = -xSpeed;
    }

    if(y < 0 ){
        y = 0;
        ySpeed = -ySpeed;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        ySpeed = -ySpeed;
    }

            //if (y > ofGetHeight()) {
              //  ySpeed = -ySpeed;
            //}

            x += xSpeed;
            y += ySpeed;


           // x = radius * cos(angle*0.3);
           // y = radius * sin(angle*0.5);
/*
            tail.push_back(*this);



          if(tail.size()>500){
           tail.erase(tail.begin());
           }
*/
        }

        void MyClass::draw(){

            ofSetColor(ofColor::red);

            ofPushStyle();
/*
            ofBeginShape();
            for (int i=0; i < tail.size(); i++) {
                    ofNoFill();
                //ofVertex(tail[i]);
                ofFill();
                ofCircle(tail[i].x,tail[i].y,10,10);

            }

    //        for (auto &it: tail) {
    //            ofVertex(it);
    //        }

            ofEndShape(false);
            */
            ofPopStyle();


            ofCircle(*this, 10);
        }


