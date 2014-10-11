

#include "Boom.h"

//--------------------------------------------------------------
    void Boom::set(float _posX, float _posY, float _velX, float _velY, float _accX, float _accY){
            //radius = _dist;
            //angle = _intAngle;

            velX = _velX;
            velY = _velY;

            accX = _accX;
            accY = _accY;


            x = _posX;
            y = _posY;
        }

//--------------------------------------------------------------
    void Boom::update(){
            //angle += _step;

           // if (x > ofGetWidth() || x < 0 || y > ofGetHeight() || y < 0){
           //     radius *= 0.9995;
           // } else {
           // radius = ;
           // }
            gravity = 0.00005;



            accY += gravity;
            velY += accY;
            velX += accX;

/*
            if (vel >= 0) {
                x = x;
                y = y;
            } else {

*/
            x += velX;
            y += velY;
                        tail.push_back(*this);
          //  }

            //_ + _acc;

            //_vel *= gravity;


           // x = radius * cos(angle*0.3);
           // y = radius * sin(angle*0.5);





          //if(tail.size()>500){
          // tail.erase(tail.begin());
          // }

    }

//--------------------------------------------------------------
    void Boom::draw(){

            ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));

            ofPushStyle();

            ofBeginShape();
            for (int i=0; i < tail.size(); i++) {
                    ofNoFill();
                //ofVertex(tail[i]);
                ofFill();
                ofCircle(tail[i],5*1/tail.size());


            }

    //        for (auto &it: tail) {
    //            ofVertex(it);
    //        }

            ofEndShape(false);
            ofPopStyle();


            ofCircle(*this, 5);
    }


