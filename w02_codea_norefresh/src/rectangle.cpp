#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.005f;
    bodySize = 30;



	//stretchFactor = ofMap(distToCatch,0,ofGetWidth(),1,2,false);

	//distToCatch = ofDist(rectangle.x,rectangle.y, mouseX, mouseY);
}

//------------------------------------------------------------------
void rectangle::draw() {


    ofPushMatrix();
    ofTranslate(*this); //translates 0,0 to center of ofPoint or "*this"

    //distToCatch = ofDist(0,0,pCatch.x,pCatch.y);
    stretchFactor = ofMap(distToCatch,0,ofGetWidth(),1,4,true);
    float tailSpeed = ofMap(distToCatch,0,ofGetWidth(),0.03,0.07,true);
    float tailAmp = ofMap(distToCatch,0,ofGetWidth(),0.1,0.5,true);
    float bodyA = ofMap(distToCatch,0,ofGetWidth()*2,0,255,true);
    float randR = abs(sin(ofGetFrameNum()*ofRandom(0.001,0.05))*255);
    float randG = abs(cos(ofGetFrameNum()*ofRandom(0.001,0.05))*255);
    float randB = abs(sin(ofGetFrameNum()*ofRandom(0.001,0.05))*255);

    //if (angle >= 360){

//} else {
//ofRotate(ofRadToDeg(-angle));
//}
    ofFill();
    ofPushStyle();
    ofSetColor(100,230,255);
    //ofPushStyle();

            ofBeginShape();
            for (int i=10; i < tail.size(); i+=3) {
                //ofVertex(tail[i]);

                ofRotate((ofRadToDeg(angle*1))*1-0.01*i);
                //adjust angle multiplier to make tail more or less crazy

                ofSetRectMode(OF_RECTMODE_CENTER);

                ofSetColor(randR,randG,randB,150);
                ofRect(i*1.01, (sin(i*tailSpeed+ofGetFrameNum()*1))*i*tailAmp,bodySize*0.4+i*0.03,bodySize*0.4+i*0.03*stretchFactor);


                ofSetColor(randR,randG,randB,250);
                ofRect(i,(sin(i*tailSpeed+ofGetFrameNum()*1))*i*tailAmp,bodySize*0.2-i*0.01,bodySize*0.2-i*0.01);

                ofSetColor(randR*0.5,randG*0.5,randB*0.5,250);
                ofRect(i+5,(sin(i*tailSpeed+ofGetFrameNum()*1))*i*tailAmp+5,bodySize*0.2-i*0.01,bodySize*0.2-i*0.01);

               // prevY[i]=(sin(i*tailSpeed+ofGetFrameNum()*1))*i*tailAmp;
                //I set the above to NEGATIVE frameNum to make the tail wag from the source.
                //WHAT ABOUT tying the frequency to an exponential framecount?
                //tie framecount multiplier to distance from target to speed up or slow down tail motion -- smaller multiplier = slower

                //cout << tail[i] << endl;
            }

    //        for (auto &it: tail) {
    //            ofVertex(it);
    //        }

            ofEndShape(false);
    ofPopStyle();


 ofRotate(ofRadToDeg(angle)); //rotates by angle translated to degrees
    ofSetColor(randR,randG,randB,100);
    ofEllipse(0, 0, bodySize*stretchFactor, bodySize/stretchFactor);

    ofSetColor(randR,randG,randB,255);
    ofEllipse(0, 0, bodySize*stretchFactor*0.8, bodySize/stretchFactor*0.8); // X & Y are 0,0 because translated to center

for (int i=1; i<200; i+=tailAmp*20){
ofSetColor(randR,randG,randB,bodyA*0.2);
    ofEllipse(0, i*stretchFactor, bodySize*stretchFactor*0.1*i, bodySize/stretchFactor*0.1*i);

    ofSetColor(randR,randG,randB,bodyA*0.5);
    ofEllipse(0, i*stretchFactor, bodySize*stretchFactor*0.8*0.1*i, bodySize/stretchFactor*0.8*0.1*i);
}
   ofPopMatrix();

    //   cout << distToCatch << endl;
   // cout << stretchFactor << endl;
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(ofPoint _catch, ofPoint _loc){
    set(catchUpSpeed * _catch + (1-catchUpSpeed) * (*this)); //easing of difference

    diff = *this - _catch; //gets the difference between ofPoint location and target

    //if (angle < TWO_PI) {
    angle = ofLerp(angle, atan2(diff.y,diff.x), 0.01); //calculates the angle for rotation
    //} else {
    //    angle = ofLerp(angle, -atan2(diff.y,diff.x), 0.01);
    //}

    if (angle < -PI) {
            angle += PI;
    }

    if (angle > PI) {
            angle -= PI;
    }

    cout << atan2(diff.y,diff.x) << endl;
    cout << angle << endl;

    tail.push_back(*this);


    if(tail.size()>750){
        tail.erase(tail.begin());
    }

    distToCatch = ofDist(_loc.x,_loc.y,_catch.x,_catch.y);

    pCatch = _catch;

    offsetY = abs(prevY - _loc.y);

    prevY = _loc.y;




}
