

#include "MyClass.h"

//--------------------------------------------------------------
    void MyClass::set(ofPoint _pos, float _vel, float _rad, float _length, float _rot, float _gStart){


            branchLength =_length;
            branchRand = ofRandom(-0.1,0.1);
            branchRandD = ofRandom(1,1.008);

            gStart = _gStart;
            vel = ((0.3-abs(branchRand))*10*-1)/3;
            velInit = _vel;

            radius = _rad;
            radInit = _rad;
            angle = _rot;

            x = _pos.x;
            y = _pos.y;

            xInit = _pos.x;
            yInit = _pos.y;
        }

//--------------------------------------------------------------
    void MyClass::update(float _rotUp){
            angle += _rotUp;

            gravity = 0.00005;

            branchRand *= branchRandD;

ofPushMatrix();
ofTranslate(xInit,yInit);

ofRotate(angle);

            if (tail.size() >= branchLength || abs(branchRand) >= ofRandom(0.8,1.7)) {
                x = x;
                y = y;
            } else {

            x += sin(y*ofRandom(0.05,0.03))*0.5+branchRand;//*ofRandom(1,2);
            y += vel;
                        tail.push_back(*this);

            }


ofPopMatrix();

    }

//--------------------------------------------------------------
    void MyClass::ofGetRad() {

    }

//--------------------------------------------------------------
    void MyClass::getY() {

    }

//--------------------------------------------------------------
    void MyClass::branch(float _branchRot) {

        branchRot = _branchRot;
        float branchStart = 100;
        if (tail.size() > branchStart) {

            for (int i=branchStart; i < tail.size(); i++) {

                float branchRad = 2*radInit*(tail.size()-i)/branchLength;

                ofFill();

                ofSetColor(0,gStart,100);
                ofCircle(tail[i].x+i*0.05,tail[i].y,branchRad,branchRad);

                ofCircle(tail[i].x-i*0.05,tail[i].y,branchRad,branchRad);

                if(tail[i].y > ofGetHeight()){
                    tail.erase(tail.begin());
                }
            }
        }
    }

//--------------------------------------------------------------
    void MyClass::draw(){



cout << yInit << ", angle: " << angle << ", yPosition:" << y << endl;



            for (int i=0; i < tail.size(); i++) {

                float tailRad = 2*radInit*(tail.size()-i)/branchLength;

                ofFill();
                ofSetColor(0,gStart,100);
                ofCircle(tail[i],tailRad);

                if(tail[i].y > ofGetHeight()){
                    tail.erase(tail.begin());
                }

            }


    }


