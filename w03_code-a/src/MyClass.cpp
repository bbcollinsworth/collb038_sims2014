

#include "MyClass.h"

//--------------------------------------------------------------
    void MyClass::set(ofPoint _pos, float _vel, float _acc){
            //radius = _dist;
            //angle = _intAngle;

            vel = _vel;
            acc = _acc;


            x = _pos.x;
            y = _pos.y;
        }

//--------------------------------------------------------------
    void MyClass::update(){
            //angle += _step;

           // if (x > ofGetWidth() || x < 0 || y > ofGetHeight() || y < 0){
           //     radius *= 0.9995;
           // } else {
           // radius = ;
           // }
            gravity = 0.00005;



            acc += gravity;
            vel += acc;

            /*
            if (vel >= 0) {
                x = x;
                y = y;
            } else {
            */

            x += sin(ofGetFrameNum()*ofRandomf());
            y += vel;
                        tail.push_back(*this);
            }

            //_ + _acc;

            //_vel *= gravity;


           // x = radius * cos(angle*0.3);
           // y = radius * sin(angle*0.5);





          //if(tail.size()>500){
          // tail.erase(tail.begin());
          // }

//    }

//--------------------------------------------------------------
    void MyClass::draw(){

            ofSetColor(ofColor::red);

            ofPushStyle();

            ofBeginShape();
            for (int i=0; i < tail.size(); i++) {
                    ofNoFill();
                //ofVertex(tail[i]);
                ofFill();
                ofCircle(tail[i],10);


            }

    //        for (auto &it: tail) {
    //            ofVertex(it);
    //        }

            ofEndShape(false);
            ofPopStyle();


            ofCircle(*this, 10);
    }


